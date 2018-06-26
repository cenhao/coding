#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dfs(const string &a, const string &b, vector<bool> &vis, int idx, char tar) {
		vis[idx] = true;
		if (b[idx] == tar) {
			int mn = -1;
			for (int i=0; i<a.length(); ++i) {
				if (!vis[i]) {
					mn = dfs(a, b, vis, i, a[i]);
					break;
				}
			}

			vis[idx] = false;
			return mn == -1 ? 0 : mn;
		}
		int mn = -1;
		for (int i=0; i<a.length(); ++i) {
			if (vis[i]) { continue; }
			if (a[i] == b[idx]) {
				int v = dfs(a, b, vis, i, tar) + 1;
				if (mn == -1 || v < mn) { mn = v; }
			}
		}
		vis[idx] = false;
		return mn;
	}
	int kSimilarity(string a, string b) {
		int len = a.length();
		string aa, bb;
		for (int i=0; i<len; ++i) {
			if (a[i] != b[i]) {
				aa += a[i];
				bb += b[i];
			}
		}

		int llen = aa.length();
		vector<bool> vis(llen, false);
		int ans = dfs(aa, bb, vis, 0, aa[0]);
		return ans;
	}
};

int main() {
	string a, b; cin >> a >> b;
	Solution sol;
	cout << sol.kSimilarity(a, b) << endl;
	return 0;
}
