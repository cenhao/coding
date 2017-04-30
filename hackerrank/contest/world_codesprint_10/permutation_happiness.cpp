#include <bits/stdc++.h>
using namespace std;

#define MAXN 3000
#define MOD 1000000007

int64_t dp[MAXN+1][MAXN];

void init() {
	memset(dp, 0, sizeof(dp));
	dp[1][0] = 1;
	for (int i=1; i<MAXN; ++i) {
		for (int j=0; j<i; ++j) {
			int inc = (i-j) * 2;
			int same = i+1-inc;
			dp[i+1][j] = (((dp[i][j]*same)%MOD) + dp[i+1][j]) % MOD;
			dp[i+1][j+1] = (((dp[i][j]*inc)%MOD) + dp[i+1][j+1]) % MOD;
		}
	}

	for (int i=1; i<=MAXN; ++i) {
		int64_t tmp = 0, sum = 0;
		for (int j=i-1; j>=0; --j) {
			tmp = dp[i][j];
			dp[i][j] = (dp[i][j] + sum) % MOD;
			sum = (sum + tmp) % MOD;
		}
	}
}

int main() {
	init();

	int q; scanf("%d", &q);
	for (int i=0; i<q; ++i) {
		int n, k; scanf("%d %d", &n, &k);
		if (k >= n) {
			printf("0\n");
		} else {
			printf("%" PRId64 "\n", dp[n][k]);
		}
	}

	return 0;
}
