class Solution {
public:
	int largest1BorderedSquare(vector<vector<int>>& grid) {
		int rsz = grid.size(), csz = grid[0].size();
		vector<vector<int>> ver(rsz, vector<int>(csz)), hor(rsz, vector<int>(csz));
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				ver[i][j] = hor[i][j] = 0;
				if (grid[i][j] == 1) {
					ver[i][j] = 1 + (i==0 ? 0 : ver[i-1][j]);
					hor[i][j] = 1 + (j==0 ? 0 : hor[i][j-1]);
				}
			}
		}

		int mx = 0;
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (grid[i][j] != 1) { continue; }
				for (int k=hor[i][j]; k>=1; --k) {
					if (i+k > rsz) { continue; }
					if (ver[i+k-1][j]>=k && ver[i+k-1][j-k+1]>=k && hor[i+k-1][j]>=k) {
						mx = max(mx, k);
						break;
					}
				}
			}
		}

		return mx * mx;
	}
};
