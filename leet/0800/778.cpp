#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	struct Pos { int x, y, h; };
	int swimInWater(vector<vector<int>>& grid) {
		int n = grid.size();
		int nn = n * n;
		vector<vector<bool>> vis(n, vector<bool>(n, false));
		auto cmp = [](const Pos &a, const Pos &b) { return a.h > b.h; };
		priority_queue<Pos, vector<Pos>, decltype(cmp)> pq(cmp);
		Pos tmp = { 0, 0, grid[0][0] };
		pq.push(tmp);
		vis[0][0] = true;
		const int mov[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		int found = -1;
		for (int i=0; i<nn && found<=0; ++i) {
			if (pq.top().h > i) { continue; }
			while (!pq.empty() && pq.top().h <= i) {
				Pos cur = pq.top(); pq.pop();
				if (cur.x == n-1 && cur.y == n-1) {
					found = i;
					break;
				}
				for (int j=0; j<4; ++j) {
					int x = cur.x + mov[j][0], y = cur.y + mov[j][1];
					if (x<0 || x>=n || y<0 || y>=n || vis[x][y]) { continue; }
					vis[x][y] = true;
					Pos tmp1 = { x, y, grid[x][y] };
					pq.push(tmp1);
				}
			}
		}

		return found;
	}
};

int main() {
	int n; cin >> n;
	vector<vector<int>> m(n, vector<int>(n));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) { cin >> m[i][j]; }
	}
	Solution sol;
	cout << sol.swimInWater(m) << endl;
	return 0;
}
