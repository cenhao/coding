class Solution {
public:
	int numWays(int n, int t) {
		int mn = min(t, n+1);
		vector<vector<int>> dp(2, vector<int>(mn, 0));
		const int MOD = 1000000007;
		dp[1][0] = 1;
		for (int i=0; i<n; ++i) {
			int cur = i & 1, pre = (i+1) & 1;
			for (int j=0; j<mn; ++j) {
				dp[cur][j] = dp[pre][j];
				if (j > 0) {
					dp[cur][j] = (dp[cur][j] + dp[pre][j-1]) % MOD;
				}
				if (j < mn-1) {
					dp[cur][j] = (dp[cur][j] + dp[pre][j+1]) % MOD;
				}
			}
		}

		return dp[(n-1) & 1][0];
	}
};
