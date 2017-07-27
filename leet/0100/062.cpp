class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(2, vector<int>(n+1, 0));
		dp[1][1] = 1;
		for (int i=0; i<m; ++i) {
			int cur = i & 1, pre = (i+1) & 1;
			for (int j=1; j<=n; ++j) {
				dp[cur][j] = dp[cur][j-1] + dp[pre][j];
			}
		}

		return dp[(m-1)&1][n];
	}
};
