class Solution {
public:
	int projectionArea(vector<vector<int>>& grid) {
		int cnt = 0;
		unordered_map<int, int> rhm, chm;
		for (int i=0; i<grid.size(); ++i) {
			for (int j=0; j<grid[i].size(); ++j) {
				if (grid[i][j] != 0) { ++cnt; }
				rhm[i] = max(rhm[i], grid[i][j]);
				chm[j] = max(chm[j], grid[i][j]);
			}
		}
		for (auto &kvp: rhm) { cnt += kvp.second; }
		for (auto &kvp: chm) { cnt += kvp.second; }
		return cnt;
	}
};
