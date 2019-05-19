class Solution {
public:
	bool dfs(int cur, vector<vector<int>> &adj, vector<int> &ans) {
		int bm = 0;
		for (auto a: adj[cur]) { if (ans[a] != -1) bm |= 1 << ans[a]; }
		for (int i=0; i<4; ++i) {
			if (bm & (1<<i)) { continue; }
			ans[cur] = i;
			int cnt = 0;
			for (auto a: adj[cur]) {
				++cnt;
				if (ans[a] != -1) { continue; }
				if (!dfs(a, adj, ans)) {
					--cnt;
					break;
				}
			}

			if (cnt == (int)adj[cur].size()) { return true; }
		}

		return false;
	}

	vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
		vector<int> ans(n, -1);
		vector<vector<int>> adj(n);
		for (auto &p: paths) {
			adj[p[0]-1].push_back(p[1]-1);
			adj[p[1]-1].push_back(p[0]-1);
		}
		for (int i=0; i<n; ++i) {
			if (ans[i] != -1) { continue; }
			dfs(i, adj, ans);
		}
		for (int i=0; i<n; ++i) { ++ans[i]; }
		return ans;
	}
};
