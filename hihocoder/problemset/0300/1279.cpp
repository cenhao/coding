/*
 * State DP
 * The straight forward idea is to do a dp[i<8192][j<8192], 
 * where i is the value of AND op, and j is the value of XOR op,
 * and dp[i][j] is the # of solutions with for i, j.
 * However the time complexity for this is O(50 * 2^13^2), which
 * is too high.
 *
 * Then consider doing a state dp.
 *
 * for each bit it can be 0, 1 or 2.
 * 0 means this bit contains at least 1 zero, and even # of ones.
 * 1 means this bit contains at least 1 zero, and odd # of ones.
 * 2 means this bit contains only ones.
 *
 * The XOR and AND value can be reconstructed for state 0 or 1, but
 * to construct the XOR value for 2 needs an extract piece of information:
 * Are there odd # or even # of ones?
 *
 * Eventually the state dp is: dp[N][STATE][0/1]
 * which means for the first N numbers, to reach to STATE, with even(0) or odd(1)
 * count of numbers in the solution.
 *
 * Then the DP can be performed, with time complexity O(N*2*3^13)
 *
 * But this problem is very strict with constant overhead, in the worst case,
 * it's very easy to timeout. Hence some preprocessing is needed to neutralize
 * the overhead, and extra tricks to reduce the number of computation is also
 * important.
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 50
#define MAXB 13
#define STATES 1594323 /* 3^13 */

int64_t dp[2][STATES][2]; // 0 - even 1s with 0s, 1 - odd 1s with 0s, 2 - all 1s
int a[STATES], x[STATES][2], inv[1<<MAXB][1<<MAXB][2];
int v[MAXN+1], base[MAXB+1];

void init() {
	base[0] = 1;
	a[0] = 0; x[0][0] = 0, x[0][1] = 0;
	for (int i=0; i<MAXB; ++i) {
		int b1 = base[i], b2 = 2 * base[i];
		int cur_bit = 1 << i;
		int andv, xorv[2], cs;
		for (int j=0; j<base[i]; ++j) {
			cs = b1 + j;
			andv = a[j];
			xorv[0] = x[j][0] | cur_bit;
			xorv[1] = x[j][1] | cur_bit;
			a[cs] = andv;
			x[cs][0] = xorv[0]; x[cs][1] = xorv[1];
			inv[andv][xorv[0]][0] = cs;
			inv[andv][xorv[1]][1] = cs;

			cs = b2 + j;
			andv = a[j] | cur_bit;
			xorv[0] = x[j][0];
			xorv[1] = x[j][1] | cur_bit;
			a[cs] = andv;
			x[cs][0] = xorv[0]; x[cs][1] = xorv[1];
			inv[andv][xorv[0]][0] = cs;
			inv[andv][xorv[1]][1] = cs;
		}

		base[i+1] = 3 * base[i];
	}
}

int main() {
	init();

	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &v[i]); }
	sort(v, v+n);
	memset(dp, 0, sizeof(dp));
	int end;
	for (int i=0; i<n; ++i) {
		for (end=0; v[i]>=(1<<end); ++end);
		end = base[end];

		int cur = i & 1; int pre = cur ^ 1;
		memcpy(dp[cur], dp[pre], end*2*sizeof(int64_t));

		++dp[cur][inv[v[i]][v[i]][1]][1];

		int andv, xorv, state;
		for (int j=0; j<end; ++j) {
			if (dp[pre][j][0]) { // < this check is important
				andv = a[j]; xorv = x[j][0];
				state = inv[andv&v[i]][xorv^v[i]][1];
				dp[cur][state][1] += dp[pre][j][0];
			}
			if (dp[pre][j][1]) {
				andv = a[j]; xorv = x[j][1];
				state = inv[andv&v[i]][xorv^v[i]][0];
				dp[cur][state][0] += dp[pre][j][1];
			}
		}
	}

	int64_t ans = 0;
	int last = (n-1) & 1;
	for (int i=0; i<end; ++i) {
		if (a[i] == x[i][0]) { ans += dp[last][i][0]; }
		if (a[i] == x[i][1]) { ans += dp[last][i][1]; }
	}

	printf("%" PRId64 "\n", ans);

	return 0;
}
