#include <bits/stdc++.h>
using namespace std;

class Solution {
	int dfs(int cur, vector<int> &quiet, vector<unordered_set<int>> &adj, vector<int> &ans, vector<int> &mn) {
		if (ans[cur] != -1) { return mn[cur]; }
		mn[cur] = quiet[cur];
		ans[cur] = cur;
		for (auto c: adj[cur]) {
			int v = dfs(c, quiet, adj, ans, mn);
			if (v < mn[cur]) {
				mn[cur] = v;
				ans[cur] = ans[c];
			}
		}
		return mn[cur];
	}
public:
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		int sz = quiet.size();
		vector<unordered_set<int>> adj(sz);
		vector<int> in(sz, 0);
		for (auto &r: richer) {
			if (adj[r[1]].insert(r[0]).second) {
				++in[r[0]];
			}
		}
		vector<int> ans(sz, -1);
		vector<int> mn(sz, -1);
		for (int i=0; i<sz; ++i) {
			if (in[i] != 0) { continue; }
			dfs(i, quiet, adj, ans, mn);
		}
		return ans;
	}
};

int main() {
	vector<vector<int>> e = {{0,1},{0,2}};
	vector<int> q = {2, 0, 1};
	Solution sol;
	auto ans = sol.loudAndRich(e, q);
	return 0;
}
