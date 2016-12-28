#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXN 1000
#define MOD 1000000007

int64_t dp[MAXN+1][MAXN+1];

int main() {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1LL;

	int n; scanf("%d", &n);

	for (int i=1; i<=n; ++i) {
		int ii = i-1;
		for (int j=0; j<i; ++j) {
			dp[i][j] = (dp[i][j] + j*dp[ii][j]) % MOD;
			dp[i][j+1] = (dp[i][j+1] + (j+1)*dp[ii][j]) % MOD;
		}
	}

	int ans = 0;
	for (int i=1; i<=n; ++i) {
		ans = (ans + dp[n][i]) % MOD;
	}

	printf("%d\n", ans);
	return 0;
}
