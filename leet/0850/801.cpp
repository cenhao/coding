class Solution {
public:
	int minSwap(vector<int>& a, vector<int>& b) {
		int sz = a.size();
		vector<vector<int>> dp(sz, vector<int>(2, -1));

		dp[0][0] = 0; dp[0][1] = 1;
		for (int i=1; i<sz; ++i) {
			if (a[i] > a[i-1]&& b[i] > b[i-1]) {
				if (dp[i-1][0] >= 0) {
					dp[i][0] = dp[i-1][0];
				}
				if (dp[i-1][1] >= 0) {
					dp[i][1] = dp[i-1][1]+1;
				}
			}

			if (a[i] > b[i-1] && b[i] > a[i-1]) {
				if (dp[i-1][0] >= 0 && (dp[i][1] == -1 || dp[i][1] > dp[i-1][0]+1)) {
					dp[i][1] = dp[i-1][0] + 1;
				}
				if (dp[i-1][1] >= 0 && (dp[i][0] == -1 || dp[i][0] > dp[i-1][1])) {
					dp[i][0] = dp[i-1][1];
				}
			}
		}

		int ans = dp[sz-1][0];
		if (ans == -1 || (dp[sz-1][1]>=0 && dp[sz-1][1] < ans)) { ans = dp[sz-1][1]; }
		return ans;
	}
};
