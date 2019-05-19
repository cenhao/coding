class Solution {
public:
	int maxUncrossedLines(vector<int>& a, vector<int>& b) {
		int asz = a.size(), bsz = b.size();
		vector<int> dp(bsz, 0);
		for (int i=0; i<asz; ++i) {
			int mx = 0, pmx = 0;
			for (int j=0; j<bsz; ++j) {
				mx = max(pmx, dp[j]);
				if (a[i] == b[j]) { dp[j] = max(pmx+1, dp[j]); }
				pmx = mx;
			}
		}

		int mx = 0;
		for (int i=0; i<bsz; ++i) { mx = max(dp[i], mx); }
		return mx;
	}
};
