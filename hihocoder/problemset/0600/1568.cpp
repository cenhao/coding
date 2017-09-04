#include <bits/stdc++.h>
using namespace std;

#define MAXN 300
#define MOD 1000000007

int dp[MAXN+1][MAXN+1][MAXN+1];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	memset(dp, 0, sizeof(dp));
	for (int i=0; i<=n; ++i) { dp[0][i][0] = 1; }
	for (int i=1; i<=n; ++i) {
		for (int j=0; j<=n; ++j) {
			for (int k=1; k<=n; ++k) {
				dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k-1]) % MOD;
			}
			if (j <= 0) { continue; }
			for (int k=0; k<n; ++k) {
				dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k+1]) % MOD;
				if (k == 0) {
					dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k]) % MOD;
				}
			}
		}
	}

	printf("%d\n", dp[n][n][k]);
	return 0;
};
