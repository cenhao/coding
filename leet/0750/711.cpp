class Solution {
	const int mov[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	bool same(int a, int b, const vector<vector<int>> &m, const vector<vector<int>> &islands) {
		int axs = islands[a][0], axe = islands[a][2];
		int ays = islands[a][1], aye = islands[a][3];
		int bxs = islands[b][0], bxe = islands[b][2];
		int bys = islands[b][1], bye = islands[b][3];

		bool issame = false;
		if (axe-axs==bxe-bxs && aye-ays==bye-bys) {
			bool test[4] = { true, true, true, true };
			for (int i=0; i<=axe-axs; ++i) {
				int x = axs + i;
				for (int j=0; j<=aye-ays; ++j) {
					int y = ays + j;
					int xx = bxs+i, yy = bys+j;
					test[0] &= (m[x][y]==a && m[xx][yy]==b) || (m[x][y]!=a && m[xx][yy]!=b);
					xx = bxe-i; yy = bye-j;
					test[1] &= (m[x][y]==a && m[xx][yy]==b) || (m[x][y]!=a && m[xx][yy]!=b);
					xx = bxs+i; yy = bye-j;
					test[2] &= (m[x][y]==a && m[xx][yy]==b) || (m[x][y]!=a && m[xx][yy]!=b);
					xx = bxe-i; yy = bys+j;
					test[3] &= (m[x][y]==a && m[xx][yy]==b) || (m[x][y]!=a && m[xx][yy]!=b);
				}
			}

			issame |= test[0] || test[1] || test[2] || test[3];
		}

		if (issame) { return true; }
		if (axe-axs==bye-bys && aye-ays==bxe-bxs) {
			bool test[4] = { true, true, true, true };
			for (int i=0; i<=axe-axs; ++i) {
				int x = axs + i;
				for (int j=0; j<=aye-ays; ++j) {
					int y = ays + j;
					int yy = bye-i, xx = bxs+j;
					test[0] &= (m[x][y]==a && m[xx][yy]==b) || (m[x][y]!=a && m[xx][yy]!=b);
					yy = bys+i; xx = bxe-j;
					test[1] &= (m[x][y]==a && m[xx][yy]==b) || (m[x][y]!=a && m[xx][yy]!=b);
					yy = bys+i; xx = bxs+j;
					test[2] &= (m[x][y]==a && m[xx][yy]==b) || (m[x][y]!=a && m[xx][yy]!=b);
					yy = bye-i; xx = bxe-j;
					test[3] &= (m[x][y]==a && m[xx][yy]==b) || (m[x][y]!=a && m[xx][yy]!=b);
				}
			}
			issame |= test[0] || test[1] || test[2] || test[3];
		}

		return issame;
	}
public:
	int numDistinctIslands2(vector<vector<int>>& g) {
		int rsz = g.size(), csz = g.empty() ? 0 : g[0].size();
		if (rsz == 0 || csz == 0) { return 0; }

		int cnt = 0;
		vector<vector<int>> mark(rsz, vector<int>(csz, -1));
		vector<vector<int>> islands;
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (g[i][j] == 0 || mark[i][j] >= 0) { continue; }
				queue<pair<int, int>> q;
				mark[i][j] = cnt;
				q.emplace(i, j);
				islands.emplace_back(vector<int>({i, j, i, j}));
				while (!q.empty()) {
					auto p = q.front(); q.pop();
					for (int k=0; k<4; ++k) {
						int x = p.first+mov[k][0], y = p.second+mov[k][1];
						if (x<0 || x>=rsz || y<0 || y>=csz || g[x][y]!=1 || mark[x][y]>=0) {
							continue;
						}
						mark[x][y] = cnt;
						q.emplace(x, y);
						islands[cnt][0] = min(islands[cnt][0], x);
						islands[cnt][1] = min(islands[cnt][1], y);
						islands[cnt][2] = max(islands[cnt][2], x);
						islands[cnt][3] = max(islands[cnt][3], y);
					}
				}
				++cnt;
			}
		}

		vector<int> f(cnt);
		function<int(int)> find = [&](int x) -> int { return f[x] = (f[x] == f[f[x]]) ? f[x] : find(f[x]); };
		for (int i=0; i<cnt; ++i) { f[i] = i; }

		int ans = cnt;
		for (int i=0; i<cnt; ++i) {
			for (int j=i+1; j<cnt; ++j) {
				int pi = find(i), pj = find(j);
				if (pi == pj) { continue; }
				if (same(i, j, mark, islands)) {
					--ans;
					f[pi] = pj;
				}
			}
		}

		return ans;
	}
};
