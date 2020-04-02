#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dist(char c1, char c2) {
		if (c1 == 0 || c2 == 0) { return 0; }
		int v1 = c1 - 'A', v2 = c2 - 'A';
		int x1 = v1 / 6, y1 = v1 % 6;
		int x2 = v2 / 6, y2 = v2 % 6;
		return abs(x1-x2) + abs(y1-y2);
	}

	int dfs(int cur, int f, int pos, vector<vector<vector<int>>> &dp, string &w) {
		if (pos < 0) { return -1; }
		if (dp[cur][f][pos] == -1) {
			if (cur == pos+1) {
				int nf = f ^ 1;
				for (int i=pos-1; i>=0; --i) {
					int v = dfs(pos, nf, i, dp, w);
					if (v == -1) { continue; }
					v += dist(w[cur-1], i==0 ? 0 : w[i-1]);
					if (dp[cur][f][pos] == -1 || dp[cur][f][pos] > v) {
						dp[cur][f][pos] = v;
					}
				}
			} else {
				int v = dfs(cur-1, f, pos, dp, w);
				if (v != -1) {
					int d = dist(w[cur-1], w[cur-2]);
					dp[cur][f][pos] = v + d;
				}
			}
		}
		return dp[cur][f][pos];
	}
	int minimumDistance(string word) {
		int len = word.length();
		vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(2, vector<int>(len+1, -1)));
		dp[1][0][0] = dp[1][1][0] = 0;
		int mn = -1;
		for (int i=0; i<len; ++i) {
			int v = dfs(len, 0, i, dp, word);
			if (mn==-1 || mn>v) {
				mn = v;
			}
		}

		return mn;
	}
};

int main() {
	string s; cin >> s;
	Solution sol;
	cout << sol.minimumDistance(s) << endl;
	return 0;
}
