class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0) { return 0; }
		int rsz = matrix.size(), csz = matrix[0].size();
		vector<int> h(csz, 0);
		vector<vector<int>> dp(rsz+1, vector<int>(csz+1, 0));
		int ans = 0;
		for (int i=0; i<rsz; ++i) {
			int w = 0;
			for (int j=0; j<csz; ++j) {
				if (matrix[i][j] == '0') {
					w = h[j] = dp[i+1][j+1] = 0;
				} else {
					++w; ++h[j];
					dp[i+1][j+1] = min(min(w, h[j]), dp[i][j]+1);
					ans = max(ans, dp[i+1][j+1]);
				}
			}
		}
		return ans * ans;
	}
};
