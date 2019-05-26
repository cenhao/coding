#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dfs(int cur, vector<int> &mx, const vector<vector<int>> &adj) {
		mx[cur] = 1;
		for (auto c: adj[cur]) {
			if (mx[c] == -1) { dfs(c, mx, adj); }
			mx[cur] = max(mx[cur], mx[c] + 1);
		}

		return mx[cur];
	}

	int longestStrChain(vector<string>& w) {
		int sz = w.size();
		sort(w.begin(), w.end(), [](string &a, string &b) {
			return (a.length() != b.length()) ? a.length() < b.length() : a < b;
		});
		vector<vector<int>> adj(sz);
		for (int i=0; i<sz; ++i) {
			for (int j=i+1; j<sz; ++j) {
				int len1 = w[i].length(), len2 = w[j].length();
				int diff = len2 - len1;
				if (diff > 1) { break; }
				if (diff < 1) { continue; }
				int a = i, b = j, lena = len1, lenb = len2;
				int cnt = 0, idx1 = 0, idx2 = 0;
				while (cnt < 2 && idx1 != len1 && idx2 != len2) {
					if (w[a][idx1] == w[b][idx2]) {
						++idx1; ++idx2;
					} else {
						++idx2; ++cnt;
					}
				}

				while (idx2 != len2) { ++idx2; ++cnt; }
				if (cnt == 1) {
					adj[a].push_back(b);
				}
			}
		}

		vector<int> mx(sz, -1);
		int ans = 0;
		for (int i=0; i<sz; ++i) {
			if (mx[i] == -1) { dfs(i, mx, adj); }
			ans = max(ans, mx[i]);
		}
		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<string> in(n); for (int i=0; i<n; ++i) { cin >> in[i]; }
	Solution sol;
	cout << sol.longestStrChain(in) << endl;
	return 0;
}
