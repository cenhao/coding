#include <vector>
using namespace std;

class Solution {
	public:
	int islandPerimeter(vector<vector<int>>& grid) {
		const int mov[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
		int ans = 0;
		for (int i=0, end=grid.size(); i<end; ++i) {
			for (int j=0, endj=grid[i].size(); j<endj; ++j) {
				if (grid[i][j] == 0) { continue; }
				int cnt = 4;
				for (int k=0; k<4; ++k) {
					int x = i + mov[k][0], y = j + mov[k][1];
					if (x>=end || x<0 || y>=endj || y<0) { continue; }
					if (grid[x][y] == 1) { --cnt; }
				}

				ans += cnt;
			}
		}

		return ans;
	}
};
