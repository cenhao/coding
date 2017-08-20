class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int sz = grid.size(), csz = grid[0].size();
		vector<vector<int>> dp(2, vector<int>(csz+1, 0x7fffffff));
		int cur = 0, pre = 1;
		for (int i=0; i<sz; ++i) {
			cur = i & 1; pre = cur ^ 1;
			if (i == 0) {
				dp[cur][1] = grid[i][0];
				for (int j=1; j<csz; ++j) { dp[cur][j+1] = dp[cur][j] + grid[i][j]; }
			} else {
				for (int j=0; j<csz; ++j) {
					dp[cur][j+1] = grid[i][j] + min(dp[pre][j+1], dp[cur][j]);
				}
			}
		}

		return dp[cur][csz];
	}
};
