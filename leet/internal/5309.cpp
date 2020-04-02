#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int makeConnected(int n, vector<vector<int>>& connections) {
		vector<vector<int>> adj(n);
		for (auto &c: connections) {
			adj[c[0]].push_back(c[1]);
			adj[c[1]].push_back(c[0]);
		}
		vector<int> gid(n, -1); // group id
		vector<int> lvl(n, 0);
		function<void(int, int, int)> dfs = [&](int cur, int par, int id) {
			gid[cur] = id;
			for (auto c: adj[cur]) {
				if (c == par) { continue; }
				if (gid[c] == -1) { dfs(c, cur, id); }
			}
		};
		int ngcnt = 0;
		for (int i=0; i<n; ++i) {
			if (gid[i] != -1) { continue; }
			dfs(i, -1, ngcnt++);
		}
		vector<int> gncnt(ngcnt, 0), gecnt(ngcnt, 0); // group node cnt, group edge cnt
		for (int i=0; i<n; ++i) { ++gncnt[gid[i]]; }
		for (auto &c: connections) { ++gecnt[gid[c[0]]]; }
		int ext = 0;
		for (int i=0; i<gncnt.size(); ++i) {
			ext += gecnt[i] - gncnt[i] + 1;
		}

		if (ext < int(gecnt.size()-1)) { return -1; }
		return int(gecnt.size() - 1);
	}
};

int main() {
	vector<vector<int>> c = {{1,5},{1,7},{1,2},{1,4},{3,7},{4,7},{3,5},{0,6},{0,1},{0,4},{2,6},{0,3},{0,2}};
	Solution sol;
	cout << sol.makeConnected(12, c) << endl;
}
