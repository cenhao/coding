#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
		int sz = routes.size();
		if (S == T) { return 0; }
		vector<set<int>> adj(sz);
		unordered_map<int, set<int>> conn;
		for (int i=0; i<sz; ++i) {
			auto &r = routes[i];
			for (auto v: r) { conn[v].insert(i); }
		}
		for (int i=0; i<sz; ++i) {
			auto &r = routes[i];
			for (auto v: r) { adj[i].insert(conn[v].begin(), conn[v].end()); }
		}

		vector<int> step(sz, -1);
		vector<bool> vis(sz, false);
		unordered_set<int> tar;
		for (auto r: conn[T]) { tar.insert(r); }
		queue<int> q;
		for (auto r: conn[S]) {
			if (tar.find(r) != tar.end()) { return 1; }
			vis[r] = true;
			step[r] = 1;
			q.push(r);
		}
		bool found = false;
		int ans = -1;
		while (!q.empty() && !found) {
			int cur = q.front(); q.pop();
			for (auto r: adj[cur]) {
				if (r == cur || vis[r]) { continue; }
				vis[r] = true;
				step[r] = step[cur]+1;
				if (tar.find(r) != tar.end()) {
					found = true;
					ans = step[r];
					break;
				}
				q.push(r);
			}
		}

		return ans;
	}
};

int main() {
	int n; cin >> n;
	int s, t; cin >> s >> t;
	vector<vector<int>> r(n);
	for (int i=0; i<n; ++i) {
		int k; cin >> k;
		for (int j=0; j<k; ++j) {
			int v; cin >> v;
			r[i].push_back(v);
		}
	}
	Solution sol;
	cout << sol.numBusesToDestination(r, s, t) << endl;
	return 0;
}
