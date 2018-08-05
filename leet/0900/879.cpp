class Solution {
public:
	int profitableSchemes(int g, int need, vector<int>& gs, vector<int>& pro) {
		int sz = gs.size();
		int mod = 1000000007;
		vector<vector<int>> dp(g+1, vector<int>(need+1, 0));
		dp[0][0] = 1;
		for (int i=0; i<sz; ++i) {
			for (int j=g; j>=0; --j) {
				for (int k=need; k>=0; --k) {
					int nj = j + gs[i];
					if (nj > g) { continue; }
					int nk = min(k + pro[i], need);
					dp[nj][nk] = (dp[nj][nk] + dp[j][k]) % mod;
				}
			}
		}
		int ans = 0;
		for (int i=0; i<=g; ++i) { ans = (ans + dp[i][need]) % mod; }
		return ans;
	}
};
