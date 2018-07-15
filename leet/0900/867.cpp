class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& a) {
		int rsz = a.size(), csz = a[0].size();
		vector<vector<int>> b(csz, vector<int>(rsz));
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				b[j][i] = a[i][j];
			}
		}

		return b;
	}
};
