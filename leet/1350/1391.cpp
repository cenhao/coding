#include <bits/stdc++.h>
using namespace std;

#define NA {100, 100, 0}
#define ML {0, -1, 3}
#define MD {1, 0, 0}
#define MR {0, 1, 1}
#define MU {-1, 0, 2}
class Solution {
public:
	bool hasValidPath(vector<vector<int>>& grid) {
		int rsz = grid.size(), csz = grid[0].size();
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) { --grid[i][j]; }
		}

		const int tf[6][4][3] = {
			{ NA, MR, NA, ML },
			{ MD, NA, MU, NA },
			{ NA, MD, ML, NA },
			{ NA, NA, MR, MD },
			{ ML, MU, NA, NA },
			{ MR, NA, NA, MU }
		};

		for (int i=0; i<4; ++i) {
			int cx = 0, cy = 0, pd = i;
			if (tf[grid[cx][cy]][pd][0] > 1) { continue; }
			while (cx!=rsz-1 || cy!=csz-1) {
				int nx = cx + tf[grid[cx][cy]][pd][0];
				int ny = cy + tf[grid[cx][cy]][pd][1];
				int nd = tf[grid[cx][cy]][pd][2];
				if (nx<0 || nx>=rsz || ny<0 || ny>=csz) { break; }
				cx = nx; cy = ny; pd = nd;
				if (tf[grid[cx][cy]][pd][0] > 1) { break; }
				if (cx == 0 && cy == 0) { break; }
			}

			if (tf[grid[cx][cy]][pd][0] > 1) { continue; }
			if (cx==rsz-1 && cy==csz-1) { return true; }
		}

		return false;
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (int i=0; i<n; ++i) { for (int j=0; j<m; ++j) { cin >> g[i][j]; } }
	Solution sol;
	cout << sol.hasValidPath(g) << endl;
	return 0;
}
