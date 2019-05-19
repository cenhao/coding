class Solution {
public:
	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
		int rsz = grid.size(), csz = grid[0].size();
		vector<vector<int>> m(rsz, vector<int>(csz, 0));
		const int mov[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		queue<pair<int, int>> q;
		q.emplace(make_pair(r0, c0));
		int initc = grid[r0][c0];
		grid[r0][c0] = -initc;
		while (!q.empty()) {
			auto pos = q.front(); q.pop();
			for (int i=0; i<4; ++i) {
				int x = pos.first+mov[i][0], y = pos.second+mov[i][1];
				if (x<0 || x>=rsz || y<0 || y>=csz || grid[x][y]!=initc) { continue; }
				grid[x][y] = -initc;
				q.emplace(make_pair(x, y));
			}
		}

		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (grid[i][j] == -initc) {
					if (i==0 || i==rsz-1 || j==0 || j==csz-1) {
						m[i][j] = 1;
						continue;
					}

					for (int k=0; k<4; ++k) {
						if (grid[i+mov[k][0]][j+mov[k][1]] != -initc) {
							m[i][j] = 1;
							break;
						}
					}
				}
			}
		}

		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (m[i][j] == 1) {
					grid[i][j] = color;
				} else {
					grid[i][j] = abs(grid[i][j]);
				}
			}
		}

		return grid;
	}
};
