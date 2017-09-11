#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	const int mov[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	struct Item { int x, y, s; };
	int cutOffTree(vector<vector<int>>& forest) {
		map<int, int> hm;
		int h = forest.size(), w = forest[0].size();
		if (forest[0][0] == 0) { return -1; }
		for (int i=0; i<h; ++i) {
			for (int j=0; j<w; ++j) {
				if (forest[i][j] >= 2) { hm[forest[i][j]] = 0; }
			}
		}

		int cnt = 0;
		for (auto it=hm.begin(); it!=hm.end(); ++it) { it->second = ++cnt; }
		for (int i=0; i<h; ++i) {
			for (int j=0; j<w; ++j) {
				if (forest[i][j] == 0) { forest[i][j] = -1; }
				else if (forest[i][j] == 1) { forest[i][j] = 0; }
				else { forest[i][j] = hm[forest[i][j]]; }
			}
		}

		vector<vector<int>> mn_tree(h, vector<int>(w, -1));
		vector<vector<int>> mn_step(h, vector<int>(w, -1));
		int s = forest[0][0] == 1 ? 1 : 0;
		Item tmp = { 0, 0, s };
		mn_tree[0][0] = s;
		mn_step[0][0] = 0;
		queue<Item> q;
		q.push(tmp);

		while (!q.empty()) {
			tmp = q.front(); q.pop();
			if (tmp.s < mn_tree[tmp.x][tmp.y]) { continue; }
			int sc = mn_step[tmp.x][tmp.y] + 1;
			for (int i=0; i<4; ++i) {
				int x = tmp.x + mov[i][0], y = tmp.y + mov[i][1];
				if (x<0 || x>=h || y<0 || y>=w || forest[x][y]<0) { continue; }
				int s = (forest[x][y] == tmp.s+1) ? tmp.s+1 : tmp.s;
				if (s < mn_tree[x][y] || (s==mn_tree[x][y] && mn_step[x][y]!=-1 && sc>=mn_step[x][y])) { continue; }
				if (s == hm.size()) { return sc; }
				mn_tree[x][y] = s;
				mn_step[x][y] = sc;
				Item tmp1 = { x, y, s };
				q.push(tmp1);
			}
		}

		return -1;
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> f(n, vector<int>(m));
	for (int i=0; i<n; ++i) { for (int j=0; j<m; ++j) { cin >> f[i][j]; } }
	Solution sol;
	cout << sol.cutOffTree(f);
	return 0;
}
