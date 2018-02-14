/*
 * Consider there's a chess board. There's will be only 2 types of row / column
 * in it. Not matter how the rows / columns are swapped, there will still
 * be two types of rows / columns in it.
 *
 * Also, the number of each type is the same for even size. For odd size, the
 * difference should be 1
 *
 * And, the number of 0 and 1 in each row / column are the same for even size.
 * For the Odd size, the difference is 1
 *
 * With all three above, we can tell if a given board can be revert back to a 
 * chess board.
 *
 * And since there will only be two types of row / column, and row and column
 * are independent, finding the minimal move is relatively trivial.
 */
class Solution {
public:
	int solve(vector<vector<int>> &b) {
		int sz = b.size();
		unordered_map<int, int> vcnt;
		vector<int> v(sz, 0);
		for (int i=0; i<sz; ++i) {
			int zcnt = 0;
			for (int j=0; j<sz; ++j) {
				v[i] = (v[i]<<1) | b[i][j];
				if (b[i][j] == 0) { ++zcnt; }
			}

			if (abs(sz-(zcnt<<1)) > 1) { return -1; }
			++vcnt[v[i]];
			if (vcnt.size() > 2) { return -1; }
		}

		int a[2][2], pos = 0;
		for (auto it=vcnt.begin(); it!=vcnt.end(); ++it, ++pos) {
			a[pos][0] = it->first; a[pos][1] = it->second;
		}

		int full = (1<<sz) - 1;
		if ((a[0][0]^a[1][0]) != full || abs(a[0][1]-a[1][1])>1) { return -1; }

		int scnt[2] = { 0, 0 };
		for (int i=0; i<sz; ++i) {
			int cur = i&1, nxt = (i+1) & 1;
			if (v[i] == a[cur][0]) {
				++scnt[1];
			} else {
				++scnt[0];
			}
		}

		scnt[0] = (scnt[0] & 1) ? 0x7fffffff : scnt[0]/2;
		scnt[1] = (scnt[1] & 1) ? 0x7fffffff : scnt[1]/2;
		return min(scnt[0], scnt[1]);
	}

	int movesToChessboard(vector<vector<int>> &board) {
		// sz > 1
		int sz = board.size(), ans = 0;
		int tmp = solve(board);
		if (tmp < 0) { return -1; }
		ans += tmp;
		for (int i=0; i<sz; ++i) {
			for (int j=i+1; j<sz; ++j) {
				swap(board[i][j], board[j][i]);
			}
		}
		tmp = solve(board);
		if (tmp < 0) { return -1; }
		return tmp + ans;
	}
};
