class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.length(), len2 = word2.length();
		vector<vector<int>> dp(2, vector<int>(len2+1));
		for (int i=0; i<=len2; ++i) { dp[0][i] = i; }
		for (int i=1; i<=len1; ++i) {
			int pre = (i-1) & 1, cur = i & 1;
			dp[cur][0] = i;
			for (int j=1; j<=len2; ++j) {
				dp[cur][j] = dp[pre][j-1] + (word1[i-1]==word2[j-1] ? 0 : 1);
				dp[cur][j] = min(dp[cur][j], dp[pre][j]+1);
				dp[cur][j] = min(dp[cur][j], dp[cur][j-1]+1);
			}
		}

		return dp[len1&1][len2];
	}
};
