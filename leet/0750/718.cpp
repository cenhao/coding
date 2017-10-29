class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		int sza = A.size(), szb = B.size();
		vector<vector<int>> dp(2, vector<int>(szb+1, 0));

		int mx = 0;
		for (int i=0; i<sza; ++i) {
			int cur = (i+1) & 1, pre = i&1;
			for (int j=0; j<szb; ++j) {
				if (A[i] == B[j]) {
					dp[cur][j+1] = dp[pre][j] + 1;
					mx = max(mx, dp[cur][j+1]);
				} else {
					dp[cur][j+1] = 0;
				}
			}
		}

		return mx;
	}
};
