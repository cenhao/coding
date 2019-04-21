class Solution {
public:
	int numEnclaves(vector<vector<int>>& g) {
		int sz = g.size(), csz = g[0].size();
		vector<vector<int>> id(sz, vector<int>(csz, -1));
		const int mov[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

		int icnt = 0, ans = 0;
		for (int i=0; i<sz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (g[i][j] == 0 || id[i][j] >= 0) { continue; }
				queue<pair<int, int>> q;
				q.emplace(make_pair(i, j));
				bool keep = true;
				int cnt = 1;
				id[i][j] = icnt;
				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int k=0; k<4; ++k) {
						int x = cur.first + mov[k][0], y = cur.second + mov[k][1];
						if (x<0 || x>=sz || y<0 || y>=csz) {
							keep = false;
							continue;
						}
						if (g[x][y] == 1 && id[x][y] == -1) {
							id[x][y] = icnt;
							++cnt;
							q.emplace(make_pair(x, y));
						}
					}
				}

				if (keep) { ans += cnt; }
				++icnt;
			}
		}

		return ans;
	}
};
