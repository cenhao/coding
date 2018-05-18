#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	pair<int, int> dfs(int cur, int par, vector<vector<int>> &adj, vector<vector<int>> &ccnt, vector<vector<int>> &ecnt) {
		int c = 0, e = 0;
		for (auto chd: adj[cur]) {
			if (chd == par) {
				ccnt[cur].push_back(0);
				ecnt[cur].push_back(0);
			} else {
				auto tp = dfs(chd, cur, adj, ccnt, ecnt);
				ccnt[cur].push_back(tp.first+1);
				ecnt[cur].push_back(tp.second+tp.first+1);
				c += tp.first + 1;
				e += tp.second + tp.first + 1;
			}
		}
		return make_pair(c, e);;
	}
	void dfs2(int cur, int par, int fc, int fe, vector<vector<int>> &adj, vector<vector<int>> &ccnt, vector<vector<int>> &ecnt, vector<int> &ans) {
		int c = 0, e = 0;
		for (int i=0; i<adj[cur].size(); ++i) {
			c += ccnt[cur][i];
			e += ecnt[cur][i];
		}
		ans[cur] = e + fe + fc;
		for (int i=0; i<adj[cur].size(); ++i) {
			int chd = adj[cur][i];
			if (chd == par) { continue; }
			dfs2(chd, cur, c-ccnt[cur][i]+1+fc, e-ecnt[cur][i]+fe+fc, adj, ccnt, ecnt, ans);
		}
	}
	vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
		vector<vector<int>> ecnt(n);
		vector<vector<int>> ccnt(n);
		vector<vector<int>> adj(n);
		for (auto &e: edges) {
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
		}
		dfs(0, -1, adj, ccnt, ecnt);
		vector<int> ans(n);
		dfs2(0, -1, 0, 0, adj, ccnt, ecnt, ans);
		return ans;
	}
};
int main() {
	int n; cin >> n;
	vector<vector<int>> e(n-1, vector<int>(2));
	for (int i=1; i<n; ++i) { cin >> e[i-1][0] >> e[i-1][1]; }
	Solution sol;
	vector<int> ans = sol.sumOfDistancesInTree(n, e);
	for (auto a: ans) { cout << a << endl; }
	return 0;
}
