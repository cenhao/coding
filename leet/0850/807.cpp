class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		int rsz = grid.size();
		int csz = rsz != 0 ? grid[0].size() : 0;

		vector<int> rmx(rsz, 0);
		vector<int> cmx(csz, 0);
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				rmx[i] = max(rmx[i], grid[i][j]);
				cmx[j] = max(cmx[j], grid[i][j]);
			}
		}

		int ans = 0;
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				ans += min(rmx[i]-grid[i][j], cmx[j]-grid[i][j]);
			}
		}

		return ans;
	}
};
