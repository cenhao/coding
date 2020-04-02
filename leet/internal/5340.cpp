class Solution {
public:
	int countNegatives(vector<vector<int>>& grid) {
		int sz = grid.size(), csz = grid[0].size();
		int cnt = 0, sta = csz-1;
		for (int i=0; i<sz; ++i) {
			for (int j=sta; j>=0; --j) {
				if (grid[i][j] < 0) {
					--sta;
					cnt += sz - i;
				} else {
					break;
				}
			}
		}

		return cnt;
	}
};
