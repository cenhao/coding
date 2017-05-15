#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
		for (int i=0; i<word1.size(); ++i) {
			for (int j=0; j<word2.size(); ++j) {
				if (word1[i] == word2[j]) {
					dp[i+1][j+1] = dp[i][j] + 1;
				} else {
					dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
				}
			}
		}

		int v = dp[word1.length()][word2.length()];
		return word1.length()-v + word2.length() -v;
	}
};
