class Solution {
public:
	vector<vector<int>> candyCrush(vector<vector<int>>& board) {
		int sz = board.size(); if (sz <= 0) { return board; }
		int vsz = board[0].size(); if (vsz <= 0) { return board; }

		bool found = true;
		while (found) {
			found = false;
			for (int i=0; i<sz; ++i) {
				int last = -1, cnt = 0;
				for (int j=0; j<=vsz; ++j) {
					int v = (j == vsz) ? 0 : abs(board[i][j]);
					if (v == 0 || v != last) {
						if (cnt >= 3) {
							for (int k=1; k<=cnt; ++k) { board[i][j-k] = -last; }
							found = true;
						}
						cnt = 0;
						last = (v == 0) ? -1 : v;
					}
					if (v != 0) { ++cnt; }
				}
			}

			for (int j=0; j<vsz; ++j) {
				int last = -1, cnt = 0;
				for (int i=0; i<=sz; ++i) {
					int v = (i == sz) ? 0 : abs(board[i][j]);
					if (v == 0 || v != last) {
						if (cnt >= 3) {
							for (int k=1; k<=cnt; ++k) { board[i-k][j] = -last; }
							found = true;
						}
						cnt = 0;
						last = (v == 0) ? -1 : v;
					}
					if (v != 0) { ++cnt; }
				}
			}

			if (!found) { break; }

			for (int j=0; j<vsz; ++j) {
				for (int i=sz-1, pos=sz-1; i>=0; --i) {
					if (board[i][j] <= 0) {
						board[i][j] = 0;
					} else {
						swap(board[pos--][j], board[i][j]);
					}
				}
			}
		}
		return board;
	}
};
