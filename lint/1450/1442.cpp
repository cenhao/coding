#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param order: The order
     * @param pattern: The pattern
     * @return: Return the number of items do not meet the demand at least
     */
	int dfs(int cur, const vector<int> &o, const vector<vector<int>> &p, vector<int> &cnt) {
		if (cur >= p.size()) {
			int tot = 0;
			for (int i=0; i<o.size(); ++i) { tot += o[i] - cnt[i]; }
			return tot;
		}
		int mn = -1, ok = true;
		int sm = 0;
		for (int i=0; i<p[cur].size(); ++i) { sm += p[cur][i]; }
		for (int i=0; true; ++i) {
			for (int j=0; ok && j<p[cur].size(); ++j) {
				if (cnt[j] > o[j]) { ok = false; }
			}
			if (ok) {
				int v = dfs(cur+1, o, p, cnt);
				if (mn == -1 || v < mn) { mn = v; }
			} else {
				for (int j=0; j<o.size(); ++j) {
					cnt[j] -= i * p[cur][j];
				}
				break;
			}
			if (sm == 0) { break; }
			for (int j=0; j<p[cur].size(); ++j) { cnt[j] += p[cur][j]; }
		}
		return mn;
	}
    int getMinRemaining(vector<int> &order, vector<vector<int>> &pattern) {
		int sz = order.size();
		vector<int> cnt(sz, 0);
		return dfs(0, order, pattern, cnt);
    }
};

int main() {
	int n; cin >> n;
	vector<int> order(n);
	for (int i=0; i<n; ++i) { cin >> order[i]; }
	int m; cin >> m;
	vector<vector<int>> p(m, vector<int>(n));
	for (int i=0; i<m; ++i) {
		for (int j=0; j<n; ++j) { cin >> p[i][j]; }
	}
	Solution sol;
	cout << sol.getMinRemaining(order, p) << endl;
	return 0;
}
