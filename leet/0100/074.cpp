class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int xs = matrix.size();
		if (xs == 0) { return false; }
		int ys = matrix[0].size();
		if (ys == 0) { return false; }
		int x = 0;
		while (x < xs && target > matrix[x][ys-1]) { ++x; }
		if (x >= xs) { return false; }
		int l = 0, r = ys-1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (matrix[x][m] <= target) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		return r >= 0 && matrix[x][r] == target;
	}
};
