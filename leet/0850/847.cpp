#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int get(int cur, int state, const vector<vector<int>> &g, vector<vector<int>> &dp, int sz) {
		if (state == (1<<sz)-1) { return 0; }
		if (dp[state][cur] == -2) { return -1; }
		if (dp[state][cur] == -1) {
			dp[state][cur] = -2;
			for (auto c: g[cur]) {
				int v = get(c, state | (1<<c), g, dp, sz);
				if (v == -1) { continue; }
				++v;
				if (dp[state][cur]<0 || dp[state][cur]>v) { dp[state][cur] = v; }
			}
			if (dp[state][cur] == -2) { dp[state][cur] = -1; }
		}
		return dp[state][cur];
	}
	int shortestPathLength(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<vector<int>> dp(1<<n, vector<int>(n, -1));
		int ans = -1;
		for (int i=0; i<n; ++i) {
			int v = get(i, 1<<i, graph, dp, n);
			if (ans==-1 || v<ans) { ans = v; }
		}
		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<vector<int>> g(n);
	for (int i=0; i<n; ++i) {
		int m; cin >>m;
		for (int j=0; j<m; ++j) {
			int v; cin >> v;
			g[i].push_back(v);
		}
	}

	Solution sol;
	cout << sol.shortestPathLength(g) << endl;
}
