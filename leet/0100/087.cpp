#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool dfs(int sta, int len, int off, vector<vector<vector<char>>> &dp, const string &s1, const string &s2) {
		if (dp[sta][len][off] != 0) { return dp[sta][len][off] == 1; }
		if (len == 0) {
			dp[sta][len][off] = s1[sta] == s2[off] ? 1 : 2;
		} else {
			dp[sta][len][off] = 2;
			// branch cutting
			vector<int> cnt(128, 0);
			int c = 0;
			for (int i=0; i<=len; ++i) {
				++cnt[s1[sta+i]];
				c += (cnt[s1[sta+i]] == 0) ? -1 : ((cnt[s1[sta+i]] == 1) ? 1 : 0);
				--cnt[s2[off+i]];
				c += (cnt[s2[off+i]] == 0) ? -1 : ((cnt[s2[off+i]] == -1) ? 1 : 0);
			}
			if (c != 0) { return false; }

			for (int i=0; i<len; ++i) {
				bool v1 = dfs(sta, i, off, dp, s1, s2);
				bool v2 = dfs(sta+i+1, len-i-1, off+i+1, dp, s1, s2);
				if (v1 && v2) {
					dp[sta][len][off] = 1;
					break;
				}
				v1 = dfs(sta, i, off+len-i, dp, s1, s2);
				v2 = dfs(sta+i+1, len-i-1, off, dp, s1, s2);
				if (v1 && v2) {
					dp[sta][len][off] = 1;
					break;
				}
			}
		}

		return dp[sta][len][off] == 1;
	}

	bool isScramble(string s1, string s2) {
		int len1 = s1.length(), len2 = s2.length();
		if (len1 != len2) { return false; }
		vector<vector<vector<char>>> dp(len1);
		for (int i=0; i<len1; ++i) {
			dp[i].resize(len1-i);
			for (int j=0; j<len1-i; ++j) {
				dp[i][j].resize(len1-j, 0);
			}
		}

		return dfs(0, len1-1, 0, dp, s1, s2);
	}
};

int main() {
	string s1, s2; cin >> s1 >> s2;
	Solution sol;
	cout << sol.isScramble(s1, s2) << endl;
	return 0;
}
