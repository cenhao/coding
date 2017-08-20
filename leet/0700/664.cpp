#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dp[27][105][105];
	int dfs(int s, int e, string &str, int base) {
		if (s > e) { return 0; }
		if (dp[base][s][e] >= 0) { return dp[base][s][e]; }
		if (s == e) {
			dp[base][s][e] = (str[s]-'a') == base ? 0 : 1;
		} else {
			int mn = 0x7fffffff;
			for (int i=s; i<e; ++i) {
				mn = min(mn, dfs(s, i, str, base) + dfs(i+1, e, str, base));
			}

			if (str[s] == str[e]) {
				int tmp = dfs(s+1, e-1, str, str[s]-'a');
				if (str[s] - 'a' != base) { ++tmp; }
				mn = min(mn, tmp);
			}

			dp[base][s][e] = mn;
		}

		return dp[base][s][e];
	}
	int strangePrinter(string s) {
		memset(dp, -1, sizeof(dp));
		int len = s.length();
		return dfs(0, len-1, s, 26);
	}
};

int main() {
	string s; cin >> s;
	Solution sol;
	cout << sol.strangePrinter(s) << endl;
	return 0;
}
