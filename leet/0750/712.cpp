#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {
		int len1 = s1.length(), len2 = s2.length();
		vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

		for (int i=0; i<len1; ++i) {
			for (int j=0; j<len2; ++j) {
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
				if (s1[i] == s2[j]) {
					dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + s1[i]);
				}
			}
		}
		int sm = -dp[len1][len2] * 2;
		for (int i=0; i<len1; ++i) { sm += s1[i]; }
		for (int i=0; i<len2; ++i) { sm += s2[i]; }
		return sm;
	}
};

int main() {
	string s1, s2; cin >> s1 >> s2;
	Solution sol;
	cout << sol.minimumDeleteSum(s1, s2) << endl;
	return 0;
}
