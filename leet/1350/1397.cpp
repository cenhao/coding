#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findGoodStrings(int n, string s1, string s2, string evil) {
		int elen = evil.length();
		vector<int> fail(elen, -1);
		for (int i=1, fp=-1; i<evil.length(); ++i) {
			while (fp>=0 && evil[fp+1]!=evil[i]) { fp = fail[fp]; }
			if (evil[fp+1] == evil[i]) { fail[i] = ++fp; }
		}

		int64_t dp[500][50][2][2];
		const int64_t MOD = 1000000007;
		memset(dp, -1, sizeof(dp));

		function<int64_t(int, int, int,  int)> dfs;
		dfs = [&](int spos, int epos, int l, int h) {
			if (epos == elen) { return 0L; }
			if (spos == n) { return 1L; }

			if (dp[spos][epos][l][h] == -1) {
				dp[spos][epos][l][h] = 0;
				char st = (l == 1) ? s1[spos] : 'a';
				char ed = (h == 1) ? s2[spos] : 'z';
				for (char i=st; i<=ed; ++i) {
					int tpos = epos - 1;
					while (tpos>=0 && evil[tpos+1]!=i) { tpos = fail[tpos]; }
					if (evil[tpos+1] == i) { ++tpos; }
					int64_t v = dp[spos][epos][l][h] + dfs(spos+1, tpos+1, (i==st)&l, (i==ed)&h);
					dp[spos][epos][l][h] = v % MOD;
				}
			}

			return dp[spos][epos][l][h];
		};

		return int(dfs(0, 0, 1, 1));
	}
};

int main() {
	string s1, s2, e; cin >> s1 >> s2 >> e;
	Solution sol;
	cout << sol.findGoodStrings(int(s1.length()), s1, s2, e) << endl;
	return 0;
}
