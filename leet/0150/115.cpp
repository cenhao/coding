#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

int main() {
	string s, t;
	cin >> s >> t;
	Solution sol;
	cout << sol.numDistinct(s, t) << endl;
	return 0;
}
