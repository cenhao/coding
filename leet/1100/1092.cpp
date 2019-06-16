class Solution {
public:
	string shortestCommonSupersequence(string str1, string str2) {
		int len1 = str1.length(), len2 = str2.length();
		vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
		vector<vector<char>> dir(len1+1, vector<char>(len2+1, 'x'));
		for (int i=1; i<=len1; ++i) { dir[i][0] = 'u'; }
		for (int i=1; i<=len2; ++i) { dir[0][i] = 'f'; }
		for (int i=1; i<=len1; ++i) {
			for (int j=1; j<=len2; ++j) {
				if (dp[i-1][j] > dp[i][j-1]) {
					dp[i][j] = dp[i-1][j];
					dir[i][j] = 'u';
				} else {
					dp[i][j] = dp[i][j-1];
					dir[i][j] = 'f';
				}
				if (str1[i-1]==str2[j-1] && dp[i-1][j-1]+1>dp[i][j]) {
					dp[i][j] = dp[i-1][j-1] + 1;
					dir[i][j] = 'd';
				}
			}
		}

		string ans;
		int x = len1, y = len2;
		while (dir[x][y] != 'x') {
			if (dir[x][y] == 'u') {
				ans += str1[--x];
			} else if (dir[x][y] == 'f') {
				ans += str2[--y];
			} else {
				ans += str1[x-1];
				--x; --y;
			}
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}
};
