int64_t dp[100001][2][3];
class Solution {
public:
	int checkRecord(int n) {
		const int MOD = 1000000007;
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;

		for (int i=1; i<=n; ++i) {
			dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]) % MOD;
			dp[i][0][1] = dp[i-1][0][0] % MOD;
			dp[i][0][2] = dp[i-1][0][1] % MOD;
			dp[i][1][0] = (dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2] + dp[i][0][0]) % MOD;
			dp[i][1][1] = dp[i-1][1][0] % MOD;
			dp[i][1][2] = dp[i-1][1][1] % MOD;
		}

		int64_t ans = (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] +
					   dp[n][1][0] + dp[n][1][1] + dp[n][1][2]) % MOD;
		return ans;
	}
};
