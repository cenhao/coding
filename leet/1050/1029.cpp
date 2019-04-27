class Solution {
public:
	int twoCitySchedCost(vector<vector<int>>& costs) {
		int nn = costs.size();
		int n = nn / 2;
		vector<vector<int>> dp(2, vector<int>(n+1, -1));
		dp[1][0] = 0;

		for (int i=0; i<nn; ++i) {
			int cur = i & 1, pre = (i+1) & 1;
			fill(dp[cur].begin(), dp[cur].end(), -1);
			for (int j=0; j<=n; ++j) {
				if (dp[pre][j] == -1) { continue; }
				int v = dp[pre][j] + costs[i][1];
				if (dp[cur][j]==-1 || dp[cur][j]>v) {
					dp[cur][j] = v;
				}
				if (j == n) { continue; }
				v = dp[pre][j] + costs[i][0];
				if (dp[cur][j+1]==-1 || dp[cur][j+1]>v) {
					dp[cur][j+1] = v;
				}
			}
		}

		int cur = (nn-1) & 1;
		return dp[cur][n];
	}
};
