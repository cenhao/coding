#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void check(vector<vector<char>> &board, int x, int y, bool first) {
		if (board[x][y] == 'M') {
			board[x][y] = 'X';
			return;
		}

		const static int mov[8][2] = {
			{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}
		};

		int mcnt = 0;
		for (int i=0; i<8; ++i) {
			int xx = x + mov[i][0], yy = y + mov[i][1];
			if (xx < 0 || xx >= board.size() || yy < 0 || yy >= board[0].size()) {
				continue;
			}

			if (board[xx][yy] == 'M') { ++mcnt; }
		}

		if (mcnt != 0) {
			board[x][y] = '0' + mcnt;
			return;
		}
		board[x][y] = 'B';

		for (int i=0; i<8; ++i) {
			int xx = x + mov[i][0], yy = y + mov[i][1];
			if (xx < 0 || xx >= board.size() || yy < 0 || yy >= board[0].size()) {
				continue;
			}
			if (board[xx][yy] != 'E') { continue; }
			check(board, xx, yy, false);
		}
	}

	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		check(board, click[0], click[1], true);
		return board;
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<char>> b(n, vector<char>(m));
	for (int i=0; i<n; ++i) {
		char s[100]; cin >> s;
		for (int j=0; j<m; ++j) {
			b[i][j] = s[j];
		}
	}

	vector<int> c(2); cin >> c[0] >> c[1];
	Solution sol;
	sol.updateBoard(b, c);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cout << b[i][j];
		}
		cout << endl;
	}

	return 0;
}
