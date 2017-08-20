class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int sz = obstacleGrid.size(), csz = obstacleGrid[0].size();
		vector<vector<int>> dp(sz+1, vector<int>(csz+1, 0));
		dp[1][1] = obstacleGrid[0][0] == 0 ? 1 : 0;
		for (int i=0; i<sz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (obstacleGrid[i][j] == 1) {
					dp[i+1][j+1] = 0;
				} else {
					dp[i+1][j+1] += dp[i][j+1] + dp[i+1][j];
				}
			}
		}

		return dp[sz][csz];
	}
};
