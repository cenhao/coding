#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool dfs(int cur, vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &svis, vector<bool> &safe) {
		vis[cur] = svis[cur] = true;
		for (auto v: graph[cur]) {
			if (vis[v]) {
				safe[cur] = (svis[v]) ? false : safe[cur] && safe[v];
			} else {
				safe[cur] = safe[cur] && dfs(v, graph, vis, svis, safe);
			}
		}

		svis[cur] = false;
		return safe[cur];
	}
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int sz = graph.size();
		vector<bool> vis(sz, false);
		vector<bool> svis(sz, false);
		vector<bool> safe(sz, true);
		for (int i=0 ; i<sz; ++i) {
			if (vis[i]) { continue; }
			dfs(i, graph, vis, svis, safe);
		}

		vector<int> ans;
		for (int i=0; i<sz; ++i) {
			if (safe[i]) { ans.push_back(i); }
		}

		return ans;
	}
};
int main() {
	int n; cin >> n;
	vector<vector<int>> g;
	for (int i=0; i<n; ++i) {
		int m; cin >> m;
		vector<int> r(m);
		for (int j=0; j<m; ++j)  { cin >> r[j]; }
		g.push_back(move(r));
	}

	Solution sol;
	sol.eventualSafeNodes(g);
	return 0;
}
