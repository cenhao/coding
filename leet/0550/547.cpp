#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void dfs(int cur, int n, vector<int> &num, const vector<vector<int>> M) {
		if (num[cur] == n) { return; }
		num[cur] = n;
		for (int i=0; i<M[cur].size(); ++i) {
			if (M[cur][i]) { dfs(i, n, num, M); }
		}
	}

	int findCircleNum(vector<vector<int>>& M) {
		vector<int> num(M.size(), 0);
		int cnt = 0;
		for (int i=0; i<M.size(); ++i) {
			if (num[i] != 0) { continue; }
			num[i] = ++cnt;
			for (int j=0; j<M[i].size(); ++j) {
				if (M[i][j] == 1) {
					dfs(j, num[i], num, M);
				}
			}
		}

		return cnt;
	}
};

int main() {
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> v[i][j];
		}
	}

	Solution sol;
	cout << sol.findCircleNum(v) << endl;
	return 0;
}
