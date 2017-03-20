#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAXN 100000

int64_t dp[MAXN+1][3][2];

int main() {
	memset(dp, 0, sizeof(dp));
	int n; scanf("%d", &n);
	dp[0][0][0] = 1;

	for (int i=1; i<=n; ++i) {
		dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][1][0] + dp[i-1][2][0]) % MOD;
		dp[i][1][0] = dp[i-1][0][0] % MOD;
		dp[i][2][0] = dp[i-1][1][0] % MOD;
		dp[i][0][1] =
			(dp[i-1][0][1] + dp[i-1][1][1] + dp[i-1][2][1] + dp[i][0][0]) % MOD;
		dp[i][1][1] = dp[i-1][0][1] % MOD;
		dp[i][2][1] = dp[i-1][1][1] % MOD;
	}

	int64_t ans = 0;
	for (int i=0; i<3; ++i) {
		for (int j=0; j<2; ++j) {
			ans = (ans + dp[n][i][j]) % MOD;
		}
	}

	printf("%" PRId64 "\n", ans);
	return 0;
}
