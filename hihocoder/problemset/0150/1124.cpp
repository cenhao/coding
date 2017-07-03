#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define MOD 1000000007

bool available[MAXN+1];
int dp[MAXN+1][MAXN+1][MAXN+1]; // dp[i][a][b]: in the i-th row, with a 0-sum col and b 1 sum col
int ans[MAXN+1][MAXN+1];

int process(int m) {
	available[m] = true;
	memset(dp, 0, sizeof(dp));
	dp[0][m][0] = 1;
	for (int i=1; i<=MAXN; ++i) {
		ans[i][m] = 0;
		for (int a=0; a<=m; ++a) {
			for (int b=0; b+a<=m; ++b) {
				dp[i][a][b] = dp[i-1][a][b]; // add 0
				if (a < m && b > 0) { // add 1 to one of the `0 sum` column
					dp[i][a][b] = (dp[i][a][b] + int64_t(dp[i-1][a+1][b-1])*(a+1)) % MOD;
				}
				if (b < m) { // add 1 to one of the `1 sum` column
					dp[i][a][b] = (dp[i][a][b] + int64_t(dp[i-1][a][b+1])*(b+1)) % MOD;
				}
				if (a < m) { // add 2 to one of the `0 sum` column
					dp[i][a][b] = (dp[i][a][b] + int64_t(dp[i-1][a+1][b])*(a+1)) % MOD;
				}
				if (a + 2 <= m && b >= 2) { // add two 1s to two of the `0 sum` column
					dp[i][a][b] = (dp[i][a][b] + int64_t(dp[i-1][a+2][b-2])*(a+2)*(a+1)/2) % MOD;
				}
				if (b + 2 <= m) { // add two 1s to two of the `1 sum` column
					dp[i][a][b] = (dp[i][a][b] + int64_t(dp[i-1][a][b+2])*(b+2)*(b+1)/2) % MOD;
				}
				if (a < m && b <= m) {
					dp[i][a][b] = (dp[i][a][b] + int64_t(dp[i-1][a+1][b])*(a+1)*b) % MOD;
				}

				ans[i][m] = (ans[i][m] + dp[i][a][b]) % MOD;
			}

		}
	}
}

int main() {
	memset(available, false, sizeof(available));
	memset(ans, -1, sizeof(ans));
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d%d", &n, &m);
		if (!available[m]) { process(m); }
		printf("%d\n", ans[n][m]);
	}

	return 0;
}
