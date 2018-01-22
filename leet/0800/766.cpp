class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int r = matrix.size(), c = matrix[0].size();
		bool ok = true;
		for (int i=0; ok && i<r; ++i) {
			int cur = matrix[i][0];
			for (int x=i, y=0; ok && x<r && y<c; ++x, ++y) {
				if (matrix[x][y] != cur) {
					ok = false;
				}
			}
		}
		for (int i=1; ok && i<c; ++i) {
			int cur = matrix[0][i];
			for (int x=0, y=i; ok && x<r && y<c; ++x, ++y) {
				if (matrix[x][y] != cur) { ok = false; }
			}
		}

		return ok;
	}
};
