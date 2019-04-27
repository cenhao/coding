class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<vector<int>> ans;
		for (int i=0; i<R; ++i) {
			for (int j=0; j<C; ++j) {
				ans.emplace_back(vector<int>{i, j});
			}
		}

		sort(ans.begin(), ans.end(), [&](const vector<int> &v1, const vector<int> &v2) {
			int d1 = abs(v1[0]-r0) + abs(v1[1]-c0);
			int d2 = abs(v2[0]-r0) + abs(v2[1]-c0);
			return d1 < d2;
		});
		return ans;
	}
};
