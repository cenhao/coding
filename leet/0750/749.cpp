#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	const int mov[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	int rsz, csz;
	int dfs1(vector<vector<int>> &g, int x, int y, int step, vector<vector<int>> &vis, int vid) {
		int cnt = 0;
		g[x][y] = step+1;
		for (int i=0; i<4; ++i) {
			int xx = x + mov[i][0], yy = y + mov[i][1];
			if (xx<0 || xx>=rsz || yy<0 || yy>=csz) { continue; }
			if (g[xx][yy] != step) {
				if (g[xx][yy] == 0 && vis[xx][yy] != vid) {
					vis[xx][yy] = vid;
					++cnt;
				}
				continue;
			}
			cnt += dfs1(g, xx, yy, step, vis, vid);
		}
		return cnt;
	}

	int dfs2(vector<vector<int>> &g, int x, int y) {
		int cnt = 0;
		g[x][y] = -1;
		for (int i=0; i<4; ++i) {
			int xx = x + mov[i][0], yy = y + mov[i][1];
			if (xx<0 || xx>=rsz || yy<0 || yy>=csz || g[xx][yy]<0) { continue; }
			if (g[xx][yy] == 0) {
				++cnt;
				continue;
			}

			cnt += dfs2(g, xx, yy);
		}

		return cnt;
	}

	void dfs3(vector<vector<int>> &g, int x, int y, int step) {
		g[x][y] = step+1;
		for (int i=0; i<4; ++i) {
			int xx = x + mov[i][0], yy = y + mov[i][1];
			if (xx<0 || xx>=rsz || yy<0 || yy>=csz || g[xx][yy]<0) { continue; }
			if (g[xx][yy] == 0) {
				g[xx][yy] = step+1;
			} else if (g[xx][yy] == step) {
				dfs3(g, xx, yy, step);
			}
		}
	}

	int containVirus(vector<vector<int>>& g) {
		rsz = g.size(); csz = g[0].size();
		vector<vector<int>> vis(rsz, vector<int>(csz, -1));
		int step = 1, ans = 0, vid = 0;
		bool run = true;
		while (run) {
			run = false;
			int mx = -1, x, y;
			for (int i=0; i<rsz; ++i) {
				for (int j=0; j<csz; ++j) {
					if (g[i][j] != step) { continue; }
					run = true;
					int xx = i, yy = j;
					++vid;
					int cnt = dfs1(g, i, j, step, vis, vid);
					if (cnt > mx) {
						x = xx; y = yy;
						mx = cnt;
					}
				}
			}

			if (!run) { break; }
			ans += dfs2(g, x, y);
			++step;

			for (int i=0; i<rsz; ++i) {
				for (int j=0; j<csz; ++j) {
					if (g[i][j] != step) { continue; }
					dfs3(g, i, j, step);
				}
			}
			++step;
		}

		return ans;
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> g[i][j];
		}
	}

	Solution sol;
	cout << sol.containVirus(g) << endl;
	return 0;
}
