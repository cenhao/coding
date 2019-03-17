#include <bits/stdc++.h>
using namespace std;

class Solution {
	const int MOD = 1000000007;

	int calc(int n, int m, vector<vector<int>> &comb) {
		if (comb[n][m] == -1) {
			if (n<=m || m==0) {
				comb[n][m] = 1;
			} else {
				comb[n][m] = (calc(n-1, m-1, comb) + calc(n-1, m, comb)) % MOD;
			}
		}
		return comb[n][m];
	}

	int search(const string &s, int l, int r, vector<vector<int>> &dp, vector<vector<int>> &c) {
		if (l >= r-1) { return 1; }
		if (dp[l][r-1] == -1) {
			dp[l][r-1] = 0;
			for (int i=l; i<r; ++i) {
				int lidx = i-1, ridx = i;
				if ((lidx<l || s[lidx]=='I') && (ridx>=r-1 || s[ridx]=='D')) {
					int64_t lv = search(s, l, i, dp, c);
					int64_t rv = search(s, i+1, r, dp, c);
					int64_t res = (((lv * rv) % MOD) * calc(r-l-1, i-l, c)) % MOD;
					dp[l][r-1] = (dp[l][r-1] + res) % MOD;
				}
			}
		}

		return dp[l][r-1];
	}
public:
	int numPermsDISequence(string s) {
		int len = s.length();
		vector<vector<int>> comb(len+2, vector<int>(len+2, -1));
		vector<vector<int>> dp(len+1, vector<int>(len+1, -1));
		return search(s, 0, len+1, dp, comb);
	}
};

int main() {
	string s;
	while (cin >> s) {
		Solution sol;
		cout << sol.numPermsDISequence(s) << endl;
	}
	return 0;
}
