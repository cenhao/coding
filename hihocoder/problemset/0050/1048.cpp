/*
 * Hiho coder 1048. Compression DP. Classic problem (similar with poj 2411)
 * Given the binary format of an integer, 0 in the i-th bit means there's
 * no cake in the place, 1 the opposite.
 *
 * dp[i][j] means in row i, the current state is represented in binary format
 * of j, the number of possible solutions. In addition, with state j, row i-1
 * must be fully covered by cakes.
 *
 * The state transformation equaltion is:
 * dp[i][j] = sum(dp[i-1][k]), where from k, we can fill up row i-1 and achieve
 * j in row i.
 *
 * The problem is to test if j in row i can be achieved by filling up row i-1
 * with state k.
 *
 * So:
 * 1. if the a-th bit in j is 0, meaning we're not putting cake in this square,
 * and as row i-1 must be filled up, so the a-th bit in row i-1 must be 1.
 * > row[i-1]    1 ?
 * > row[i]      0 ?
 *
 * 2. If the a-th bit in j is 1, meaning we're putting cake in this square,
 * there're two possiblities:
 * 2.a put the cake vertically, to do this, the square in row i-1 must be empty:
 * > row[i-1]    0 ?
 * > row[i]      1 ?
 * 2.b put the cake horizontally, then a mustn't be the last bit, and a and a+1
 * in row i-1 must be filled:
 * > row[i-1]    1 1
 * > row[i]      1 1
 *
 * The other states are invalid, so those states cannot be used in sum in the dp.
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAXN 1000
#define MAXM 5

int64_t dp[2][1<<MAXM];
int n, m;

bool test(int sc, int sp) {
	for (int i=0; i<m; ++i) {
		int mask = 1 << i;
		int nmask = 1 << (i+1);

		if ((sc & mask) == 0) {
			if ((sp & mask) == 0) { return false; }
		} else {
			if ((sp & mask) != 0) {
				if (i == m-1 || (sp & nmask) == 0 || (sc & nmask) == 0) {
					return false;
				}

				++i;
			}
		}
	}
}

int64_t process() {
	memset(dp, 0, sizeof(dp));
	int end = 1 << m;
	int full = end - 1;

	for (int i=0; i<end; ++i) {
		if (test(i, full)) { dp[0][i] = 1LL; }
	}

	for (int i=1; i<n; ++i) {
		int cur = i & 1, pre = (i-1) & 1;

		for (int i2=0; i2<end; ++i2) {
			dp[cur][i2] = 0LL;
			for (int i3=0; i3<end; ++i3) {
				if (test(i2, i3)) {
					dp[cur][i2] = (dp[cur][i2] + dp[pre][i3]) % MOD;
				}
			}
		}
	}

	return dp[(n-1)&1][full];
}

int main() {
	scanf("%d %d", &n, &m);
	printf("%"PRId64"\n", process());
	return 0;
}
