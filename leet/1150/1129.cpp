class Solution {
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
		vector<vector<int>> st(2, vector<int>(n, -1));
		vector<vector<vector<int>>> adj(2, vector<vector<int>>(n));

		for (auto &e: red_edges) { adj[0][e[0]].push_back(e[1]); }
		for (auto &e: blue_edges) { adj[1][e[0]].push_back(e[1]); }

		st[0][0] = st[1][0] = 0;
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		q.push(make_pair(0, 1));

		while (!q.empty()) {
			auto p = q.front(); q.pop();
			int cc = p.second ^ 1;

			for (auto c: adj[cc][p.first]) {
				if (st[cc][c] != -1) { continue; }

				st[cc][c] = st[p.second][p.first] + 1;
				q.push(make_pair(c, cc));
			}
		}

		vector<int> ans(n);
		for (int i=0; i<n; ++i) {
			int mn = st[0][i];
			if (mn < 0 || (st[1][i]>=0 && st[1][i]<mn)) { mn = st[1][i]; }
			ans[i] = mn;
		}
		return ans;
	}
};
