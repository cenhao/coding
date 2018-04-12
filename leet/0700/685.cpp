#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
	bool find_ring(int cur, vector<bool> &chk, vector<bool> &act,
				   vector<unordered_map<int, int>> &adj, vector<vector<int>> &edges,
				   vector<int> &path, vector<int> &ring) {
		if (act[cur]) {
			for (int i=path.size()-1; i>=0; --i) {
				ring.push_back(path[i]);
				if (edges[path[i]][0] == cur) { break; }
			}
			return true;
		}

		act[cur] = true;
		for (auto &kvp: adj[cur]) {
			int v = kvp.first;
			if (chk[v]) { continue; }
			path.push_back(kvp.second);
			if (find_ring(v, chk, act, adj, edges, path, ring)) { return true; }
			path.pop_back();
		}
		act[cur] = false;
		chk[cur] = true;
		return false;
	}
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		int sz = edges.size();
		vector<int> cnt(sz+1, 0);
		vector<int> par(sz+1);
		int cand1 = -1, cand2 = -1;
		vector<unordered_map<int, int>> adj(sz+1);
		for (int i=0; i<sz; ++i) {
			++cnt[edges[i][1]];
			if (cnt[edges[i][1]] > 1) {
				cand1 = par[edges[i][1]];
				cand2 = i;
			}
			par[edges[i][1]] = i;
			adj[edges[i][0]].insert(make_pair(edges[i][1], i));
		}

		vector<bool> chk(sz+1, false), act(sz+1, false);
		vector<int> path, ring;
		bool has_ring = false;
		for (int i=1; i<=sz; ++i) {
			if (chk[i]) { continue; }
			if (has_ring = find_ring(i, chk, act, adj, edges, path, ring)) { break; }
		}

		int pick = -1;
		if (!has_ring) {
			pick = max(cand1, cand2);
		} else {
			if (cand1 == -1) {
				for (int i=ring.size()-1; i>=0; --i) {
					pick = max(pick, ring[i]);
				}
			} else {
				for (int i=ring.size()-1; i>=0; --i) {
					if (ring[i] == cand1) {
						pick = cand1; break;
					} else if (ring[i] == cand2) {
						pick = cand2; break;
					}
				}
			}
		}

		return edges[pick];
	}
};
*/

class Solution {
public:
	int find(vector<int> &par, int x) {
		if (par[par[x]] != par[x]) {
			par[x] = find(par, par[x]);
		}
		return par[x];
	}
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		int sz = edges.size();
		vector<int> parent(sz+1, 0);
		vector<int> first, second;

		for (auto &e: edges) {
			if (parent[e[1]] == 0) {
				parent[e[1]] = e[0];
			} else {
				first = { parent[e[1]], e[1] };
				second = e;
				e[0] = -1; // mark the edge as deleted
			}
		}

		for (int i=1; i<=sz; ++i) { parent[i] = i; }
		for (auto &e: edges) {
			if (e[0] == -1) { continue; }
			int p0 = find(parent, e[0]), p1 = find(parent, e[1]);
			if (p0 == p1) {
				return first.empty() ? e : first;
			}
			parent[p1] = p0;
		}

		return second;
	}
};

int main() {
	int n; cin >> n;
	vector<vector<int>> e(n, vector<int>(2));
	for (int i=0; i<n; ++i) { cin >> e[i][0] >> e[i][1]; }
	Solution sol;
	vector<int> ans = sol.findRedundantDirectedConnection(e);
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}
