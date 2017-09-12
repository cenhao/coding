class Solution {
public:
	const int mov[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
	bool check(int x, int y, int len, const string &w, const vector<vector<char>> &b, vector<vector<bool>> &vis) {
		if (b[x][y] != w[len]) { return false; }
		if (len == w.length()-1) { return true; }
		vis[x][y] = true;
		for (int i=0; i<4; ++i) {
			int xx = x + mov[i][0], yy = y + mov[i][1];
			if (xx < 0 || xx >= b.size() || yy < 0 || yy > b[0].size() || vis[xx][yy]) { continue; }
			if (check(xx, yy, len+1, w, b, vis)) { return true; }
		}
		vis[x][y] = false;
		return false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
		for (int i=0; i<board.size(); ++i) {
			for (int j=0; j<board[i].size(); ++j) {
				if (check(i, j, 0, word, board, vis)) { return true; }
			}
		}

		return false;
	}
};
