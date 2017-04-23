class Solution {
public:
	int longestLine(vector<vector<int>>& M) {
		if (M.size() <= 0 || M[0].size() <= 0) { return 0; }
		vector<vector<vector<int>>> dp(M.size()+2, vector<vector<int>>(M[0].size()+2, vector<int>(4, 0)));
		const int dir[4][2] = { {0, -1}, {-1, 0}, {-1, -1}, {-1, 1} };
		int mx = 0;
		for (int i=0; i<M.size(); ++i) {
			for (int j=0; j<M[i].size(); ++j) {
				if (M[i][j] == 0) { continue; }
				int ii = i + 1; int jj = j + 1;
				for (int k=0; k<4; ++k) {
					int x = ii + dir[k][0], y = jj + dir[k][1];
					dp[ii][jj][k] = max(dp[ii][jj][k], 1+dp[x][y][k]);
					mx = max(dp[ii][jj][k], mx);
				}
			}
		}

		return mx;
	}
};
