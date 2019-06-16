#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<int>> sp(n, vector<int>(n, -1));
		queue<pair<int, int>> q;
		if (grid[0][0] == 0) {
			sp[0][0] = 0;
			q.emplace(make_pair(0, 0));
		}
		const int mov[8][2] = { {-1, -1}, {0, -1}, {1, -1},
			{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0} };
		bool stop = false;
		while (!q.empty() && !stop) {
			auto cur = q.front(); q.pop();
			for (int i=0; i<8 && !stop; ++i) {
				int x = cur.first + mov[i][0], y = cur.second + mov[i][1];
				if (x<0 || x>=n || y<0 || y>=n || grid[x][y]==1 || sp[x][y]!=-1) { continue; }
				sp[x][y] = sp[cur.first][cur.second] + 1;
				q.emplace(make_pair(x, y));
				if (x == n-1 && y == n-1) { stop = true; }
			}
		}

		int ret = sp[n-1][n-1];
		if (ret >= 0) { ++ret; }
		return ret;
	}
};

int main() {
	int n; cin >> n;
	vector<vector<int>> g(n, vector<int>(n));
	for (int i=0; i<n; ++i) { for (int j=0; j<n; ++j) { cin >> g[i][j]; } }
	Solution sol;
	cout << sol.shortestPathBinaryMatrix(g) << endl;
	return 0;
}
