class Solution {
public:
	int dfs(int l, int r, int m, vector<vector<vector<int>>> &dp, const vector<int> &n) {
		if (m<=l || m>=r) { return 0; }
		if (dp[l][r][m] != -1) { return dp[l][r][m]; }
		int v = n[l] * n[m] * n[r];
		if (l+1 == m && r-1==m) { return dp[l][r][m] = v; }
		int mxl = 0, mxr = 0;
		for (int i=l+1; i<m; ++i) {
			mxl = max(mxl, dfs(l, m, i, dp, n));
		}
		for (int i=m+1; i<r; ++i) {
			mxr = max(mxr, dfs(m, r, i, dp, n));
		}
		return dp[l][r][m] = v + mxl + mxr;
	}
	int maxCoins(vector<int>& nums) {
		int sz = nums.size();
		if (sz <= 0) { return 0; }
		vector<int> n(sz+2);
		for (int i=0; i<nums.size(); ++i) { n[i+1] = nums[i]; }
		n[0] = 1; n[nums.size()+1] = 1;
		vector<vector<vector<int>>> dp(sz+2, vector<vector<int>>(sz+2, vector<int>(sz+2, -1)));
		int ans = 0;
		for (int i=1; i<=sz; ++i) {
			ans = max(ans, dfs(0, sz+1, i, dp, n));
		}
		return ans;
	}
};
