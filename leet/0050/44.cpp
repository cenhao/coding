class Solution {
public:
	bool isMatch(string s, string p) {
		int slen = s.length(), plen = p.length();
		vector<vector<int>> dp(slen+1, vector<int>(plen+1, -1));
		dp[0][0] = 0;
		// important for s = "" p = "***"
		for (int i=0; i<plen && p[i] == '*'; ++i) { dp[0][i+1] = 0; }
		for (int i=0; i<slen; ++i) {
			for (int j=0; j<plen; ++j) {
				if (s[i] != p[j] && p[j] != '*' && p[j] != '?') {
					dp[i+1][j+1] = -1;
				} else {
					if (s[i] == p[j] || p[j] == '?') {
						dp[i+1][j+1] = (dp[i][j] >= 0) ? dp[i][j] + 1 : -1;
					} else {
						int mx = max(dp[i][j], dp[i][j+1]);
						if (mx >= 0) { ++mx; }
						mx = max(mx, dp[i+1][j]);
						dp[i+1][j+1] = mx;
					}
				}
			}
		}

		return dp[slen][plen] == slen;
	}
};
