class Solution {
public:
	bool dfs(vector<int> &st, vector<vector<int>> &g, int cur, int v) {
		st[cur] = v;
		for (auto adj : g[cur]) {
			if (st[adj] == 2) {
				if (!dfs(st, g, adj, v^1)) { return false; }
			} else if (st[adj] == v) {
				return false;
			}
		}

		return true;
	}
	bool isBipartite(vector<vector<int>>& graph) {
		int sz = graph.size();
		vector<int> state(sz, 2);
		for (int i=0; i<sz; ++i) {
			if (state[i] == 2) {
				if (!dfs(state, graph, i, 0)) { return false; }
			}
		}

		return true;
	}
};
