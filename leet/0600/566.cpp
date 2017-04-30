class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		if (r * c == 0) { return nums; }
		if (nums.size() == 0) { return nums; }
		if (nums.size() * nums[0].size() != r * c) { return nums; }

		vector<vector<int>> ans(r, vector<int>(c));
		int cnt = 0;
		for (int i=0; i<nums.size(); ++i) {
			for (int j=0; j<nums[i].size(); ++j) {
				int x = cnt / c, y = cnt % c;
				ans[x][y] = nums[i][j];
				++cnt;
			}
		}

		return ans;
	}
};
