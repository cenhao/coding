class Solution {
public:
	int countServers(vector<vector<int>>& grid) {
		int rsz = grid.size(), csz = grid[0].size();
		vector<int> rcnt(rsz, 0), ccnt(csz, 0);
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (grid[i][j] == 1) {
					++rcnt[i];
					++ccnt[j];
				}
			}
		}

		int ans = 0;
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (grid[i][j] != 1) { continue; }
				if (rcnt[i] > 1) { ++ans; }
				if (ccnt[j] > 1) { ++ans; }
				if (rcnt[i]>1 && ccnt[j]>1) { --ans; }
			}
		}

		return ans;
	}
};
