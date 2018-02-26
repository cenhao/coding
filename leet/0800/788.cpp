#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int rotatedDigits(int N) {
		const int MAXL = 7, SZ = 7;
		int dp[MAXL][SZ][2], sm[MAXL][2];
		memset(dp, 0, sizeof(dp));
		memset(sm, 0, sizeof(sm));
		dp[0][0][0] = 1;
		sm[0][0] = 1;
		bool diff[7] = { false, false, true, true, true, false, true };

		for (int i=1; i<MAXL; ++i) {
			int v[2] = {0, 0};
			for (int j=0; j<SZ; ++j) {
				v[0] += dp[i-1][j][0]; v[1] += dp[i-1][j][1];
			}
			for (int j=0; j<SZ; ++j) {
				if (diff[j]) {
					dp[i][j][0] = 0; dp[i][j][1] = v[0] + v[1];
				} else {
					dp[i][j][0] = v[0]; dp[i][j][1] = v[1];
				}

				sm[i][0] += dp[i][j][0]; sm[i][1] += dp[i][j][1];
			}
		}

		int idx[10] = {0, 1, 2, -1, -1, 3, 4, -1, 5, 6};
		string strn = to_string(N);
		int ans = 0;
		bool safe = false;
		for (int i=0, end=strn.length(); i<end; ++i) {
			int pos = end-i;
			for (int j=0, jend=strn[i]-'0'+(i==end-1?1:0); j<jend; ++j) {
				if (idx[j] < 0) { continue; }
				ans += (diff[idx[j]] || safe) ? (sm[pos-1][0]+sm[pos-1][1]) : sm[pos-1][1];
			}

			if (idx[strn[i]-'0'] < 0) { break; }
			if (diff[idx[strn[i]-'0']]) { safe = true; }
		}

		return ans;
	}
};

/*
class Solution {
public:
	int rotatedDigits(int N) {
		set<int> gn = {0, 1, 2, 5, 6, 8, 9};
		set<int> cgn = { 2, 5, 6, 9 };
		int ans = 0;
		for (int i=1; i<=N; ++i) {
			string s = to_string(i);
			bool ok = true;;
			int ccnt = 0;
			for (auto c : s) {
				if (gn.find(c-'0') == gn.end()) {
					ok = false;
					break;
				}
				if (cgn.find(c-'0') != cgn.end()) {
					++ccnt;
				}
			}

			if (ok && ccnt>0) { ++ans; }
		}
		return ans;
	}
};
*/

int main() {
	int n; cin >> n;
	Solution sol;
	cout << sol.rotatedDigits(n) << endl;
	return 0;
}
