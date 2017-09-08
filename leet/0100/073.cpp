class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		bool rfirst = false, cfirst = false;
		for (int i=0; i<matrix.size(); ++i) {
			for (int j=0; j<matrix[i].size(); ++j) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = matrix[0][j] = 0;
					if (i == 0) { rfirst = true; }
					if (j == 0) { cfirst = true; }
				}
			}
		}

		for (int i=1; i<matrix.size(); ++i) {
			if (matrix[i][0] == 0) {
				for (int j=0; j<matrix[i].size(); ++j) {
					matrix[i][j] = 0;
				}
			}
		}
		for (int i=1; i<matrix[0].size(); ++i) {
			if (matrix[0][i] == 0) {
				for (int j=0; j<matrix.size(); ++j) {
					matrix[j][i] = 0;
				}
			}
		}
		if (rfirst) {
			for (int i=0; i<matrix[0].size(); ++i) { matrix[0][i] = 0; }
		}
		if (cfirst) {
			for (int i=0; i<matrix.size(); ++i) { matrix[i][0] = 0; }
		}
	}
};
