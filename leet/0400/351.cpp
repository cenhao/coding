class Solution {
public:
	int dfs(int x, int y, vector<vector<bool>> &vis, int cnt, int m, int n) {
		const static int mov[16][2] = {
			{-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
			{1, 1}, {1, 0}, {1, -1}, {0, -1},
			{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
			{1, 2}, {2, 1}, {2, -1}, {1, -2}
		};
		vis[x][y] = true;
		int ans = 0;
		++cnt;
		if (cnt <= n) {
			if (cnt >= m) { ++ans; }
			for (int i=0; i<16; ++i) {
				int xx = x + mov[i][0], yy = y + mov[i][1];
				if (xx<0 || xx>=3 || yy<0 || yy>=3) { continue; }
				if (vis[xx][yy]) {
					xx += mov[i][0];
					yy += mov[i][1];
					if (xx<0 || xx>=3 || yy<0 || yy>=3) { continue; }
				}
				if (vis[xx][yy]) { continue; }
				ans += dfs(xx, yy, vis, cnt, m, n);
			}
		}
		vis[x][y] = false;
		return ans;
	}

	int numberOfPatterns(int m, int n) {
		vector<vector<bool>> vis(3, vector<bool>(3, false));
		int ans = dfs(0, 0, vis, 0, m, n) * 4;
		ans += dfs(0, 1, vis, 0, m, n) * 4;
		ans += dfs(1, 1, vis, 0, m, n);
		return ans;
	}
};
