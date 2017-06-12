class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int len = s.length();
		if (len <= 1) { return 1; }
		vector<vector<int>> dp(len, vector<int>(len+1, 0));

		for (int i=0; i<len; ++i) { dp[i][1] = 1; }
		for (int i=2; i<=len; ++i) {
			for (int j=0; j<=len-i; ++j) {
				dp[j][i] = max(dp[j][i-1], dp[j+1][i-1]);
				if (s[j] == s[j+i-1]) { dp[j][i] = max(dp[j][i], 2+dp[j+1][i-2]); }
			}
		}

		return dp[0][len];
	}
};
