class Solution {
public:
	int getMaximumGold(vector<vector<int>>& grid) {
		int rsz = grid.size(), csz = grid[0].size();
		vector<vector<bool>> vis(rsz, vector<bool>(csz));

		const int mov[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
		function<int(int, int, int)> dfs = [&](int x, int y, int v) {
			vis[x][y] = true;
			int cur = v + grid[x][y];
			int mx = cur;
			for (int i=0; i<4; ++i) {
				int xx = x + mov[i][0], yy = y + mov[i][1];
				if (xx<0 || xx>=rsz || yy<0 || yy>=csz || vis[xx][yy] || grid[xx][yy]<=0) {
					continue;
				}
				mx = max(mx, dfs(xx, yy, cur));
			}
			vis[x][y] = false;
			return mx;
		};

		int mx = 0;
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (grid[i][j] == 0) { continue; }
				mx = max(dfs(i, j, 0), mx);
			}
		}

		return mx;
	}
};
