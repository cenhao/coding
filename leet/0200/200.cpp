class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		const static int mov[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		int rsz = grid.size();
		if (rsz == 0) { return 0; }
		int csz = grid[0].size();
		if (csz == 0) { return 0; }

		vector<vector<int>> id(rsz, vector<int>(csz, 0));
		int cid = 0;
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (grid[i][j] == '1' && id[i][j] == 0) {
					id[i][j] = ++cid;
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						auto p = q.front();
						q.pop();
						for (int k=0; k<4; ++k) {
							int x = p.first+mov[k][0], y = p.second+mov[k][1];
							if (x<0 || x>=rsz || y<0 || y>=csz || grid[x][y]=='0' || id[x][y]!=0) {
								continue;
							}
							id[x][y] = cid;
							q.push(make_pair(x, y));
						}
					}
				}
			}
		}

		return cid;
	}
};
