class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) { return false; }
		int rsz = matrix.size(), csz = matrix[0].size();

		int pos = csz - 1;
		for (int i=0; i<rsz && pos>=0; ++i) {
			while (pos>=0 && matrix[i][pos]>target) { --pos; }
			if (pos>=0 && matrix[i][pos] == target) { return true; }
		}

		return false;
	}
};
