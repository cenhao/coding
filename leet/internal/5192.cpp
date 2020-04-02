class Solution {
public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		vector<vector<int>> adj(n);
		for (auto &c: connections) {
			adj[c[0]].push_back(c[1]);
			adj[c[1]].push_back(c[0]);
		}

		vector<int> dfn(n, -1), low(n, -1), f(n, -1);
		int nxt = 0;
		function<void(int, int)> tarjan = [&](int cur, int p) {
			f[cur] = p;
			dfn[cur] = low[cur] = nxt++;
			for (auto v: adj[cur]) {
				if (dfn[v] == -1) {
					tarjan(v, cur);
					low[cur] = min(low[cur], low[v]);
				} else if (f[cur] != v) {
					low[cur] = min(low[cur], dfn[v]);
				}
			}
		};

		tarjan(0, -1);

		vector<vector<int>> ans;
		for (int i=0; i<n; ++i) {
			int v = f[i];
			if (v>=0 && low[i]>dfn[v]) {
				ans.push_back({v, i});
			}
		}

		return ans;
	}
};
