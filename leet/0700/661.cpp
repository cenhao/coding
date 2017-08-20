class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		int sz = M.size(), csz = M[0].size();
		vector<vector<int>> ans(sz, vector<int>(csz));
		int mov[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };
		for (int i=0; i<sz; ++i) {
			for (int j=0; j<csz; ++j) {
				int sum = M[i][j], cnt = 1;
				for (int k=0; k<8; ++k) {
					int x = i + mov[k][0], y = j + mov[k][1];
					if (x < 0 || x >= sz || y < 0 || y >= csz) { continue; }
					sum += M[x][y]; ++cnt;
				}
				ans[i][j] = sum / cnt;
			}
		}

		return ans;
	}
};
