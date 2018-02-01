class Solution {
	public:
	int numDistinct(string s, string t) {
		vector<vector<int>> dp(t.length()+1, vector<int>(s.length()+1, 0));
		for (int i=0; i<=s.length(); ++i) { dp[0][i] = 1; }

		for (int i=0; i<t.length(); ++i) {
			for (int j=0; j<s.length(); ++j) {
				int ii=i+1, jj = j+1;
				dp[ii][jj] = dp[ii][jj-1] + ((t[i] == s[j]) ? dp[ii-1][jj-1] : 0);
			}
		}

		return dp[t.length()][s.length()];
	}
};

/*
new attempt
class Solution {
public:
	int numDistinct(string s, string t) {
		int slen = s.length(), tlen = t.length();
		if (slen < tlen) { return 0; }
		vector<vector<int>> dp(slen+1, vector<int>(tlen+1, 0));
		for (int i=0; i<=slen; ++i) { dp[i][0] = 1; }
		for (int i=0; i<slen; ++i) {
			for (int j=0; j<tlen; ++j) {
				dp[i+1][j+1] = dp[i][j+1];
				if (s[i] == t[j]) { dp[i+1][j+1] += dp[i][j]; }
			}
		}

		return dp[slen][tlen];
	}
};
*/
