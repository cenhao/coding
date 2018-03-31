class Solution {
public:
	int flood(int x, int y, vector<vector<int>> &cp) {
		if (cp[x][y] != 1) { return 0; }
		cp[x][y] = 2;
		int cnt = 1;
		if (x > 0) { cnt += flood(x-1, y, cp); }
		if (x < cp.size()-1) { cnt += flood(x+1, y, cp); }
		if (y > 0) { cnt += flood(x, y-1, cp); }
		if (y < cp[0].size()-1) { cnt += flood(x, y+1, cp); }
		return cnt;
	}
	vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
		const static int mov[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		int rsz = grid.size(), csz = grid[0].size(), hsz = hits.size();
		int conn = 0, all = 0;
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (grid[i][j] == 1) { ++all; }
			}
		}
		vector<vector<int>> cp(grid);
		for (auto &h: hits) { cp[h[0]][h[1]] = 0; }
		for (int i=0; i<csz; ++i) {
			if (cp[0][i] == 1) { conn += flood(0, i, cp); }
		}
		vector<int> left(hsz);
		vector<bool> ok(hsz, false);
		for (int i=hsz-1; i>=0; --i) {
			left[i] = conn;
			int x = hits[i][0], y = hits[i][1];
			if (grid[x][y] == 0) { continue; }
			cp[x][y] = 1;
			for (int j=0; j<4; ++j) {
				int xx = x + mov[j][0], yy = y + mov[j][1];
				if (xx>=rsz||yy<0||yy>=csz||(xx>=0 && cp[xx][yy]!=2)) { continue; }
				ok[i] = true;
				break;
			}
			if (ok[i]) {
				conn += flood(x, y, cp);
			}
		}
		vector<int> ans(hsz);
		for (int i=0, last=all; i<hsz; ++i) {
			ans[i] = last-left[i]-(ok[i]?1:0);
			last = left[i];
		}
		return ans;
	}
};
