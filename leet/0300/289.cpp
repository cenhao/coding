class Solution {
public:
	int count_life(int x, int y, vector<vector<int>> &board) {
		const static int mov[8][2] = {
			{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}
		};
		int rsz = board.size(), csz = board[0].size();
		int cnt = 0;
		for (int i=0; i<8; ++i) {
			int xx = mov[i][0] + x, yy = mov[i][1] + y;
			if (xx<0 || xx>=rsz || yy<0 || yy>=csz) { continue; }
			cnt += (board[xx][yy] & 1);
		}
		return cnt;
	}
	void gameOfLife(vector<vector<int>>& board) {
		int rsz = board.size(), csz = board[0].size();
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				int cnt = count_life(i, j, board);
				int nl = (board[i][j] == 1) ?
					((cnt>=2 && cnt<=3) ? 1 : 0) : (cnt == 3 ? 1 : 0);
				board[i][j] |= nl << 1;
			}
		}
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				board[i][j] >>= 1;
			}
		}
	}
};
