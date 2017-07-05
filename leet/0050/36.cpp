class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<vector<bool>> rmap(9, vector<bool>(9, false));
		vector<vector<bool>> cmap(9, vector<bool>(9, false));
		vector<vector<bool>> gmap(9, vector<bool>(9, false));

		for (int i=0; i<9; ++i) {
			for (int j=0; j<9; ++j) {
				if (board[i][j] == '.') { continue; }
				int v = board[i][j] - '1';
				if (rmap[i][v]) { return false; }
				rmap[i][v] = true;
				if (cmap[j][v]) { return false; }
				cmap[j][v] = true;
				int g = i / 3 * 3 + j / 3;
				if (gmap[g][v]) { return false; }
				gmap[g][v] = true;
			}
		}

		return true;
	}
};
