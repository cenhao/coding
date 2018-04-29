#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int largestIsland(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) { return 0; }
		int sz = grid.size(), csz = grid[0].size();
		const int mov[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
		vector<vector<bool>> vis(sz, vector<bool>(csz, false));
		int id = 1; 
		vector<int> size = {0};
		for (int i=0; i<sz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (grid[i][j]==0 || vis[i][j]) { continue; }
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				vis[i][j] = true;
				int cnt = 0;
				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					grid[cur.first][cur.second] = id;
					++cnt;
					for (int k=0; k<4; ++k) {
						int x = cur.first + mov[k][0], y = cur.second + mov[k][1];
						if (x<0||y<0||x>=sz||y>=csz||vis[x][y]||grid[x][y]==0) { continue; }
						vis[x][y] = true;
						q.push(make_pair(x, y));
					}
				}
				size.push_back(cnt);
				++id;
			}
		}
		int ans = 0;
		for (int i=1; i<id; ++i) { ans = max(ans, size[i]); }
		for (int i=0; i<sz; ++i) {
			for (int j=0; j<sz; ++j) {
				if (grid[i][j] != 0) { continue; }
				unordered_set<int> used;
				int cur = 1;
				for (int k=0; k<4; ++k) {
					int x = i + mov[k][0], y = j + mov[k][1];
					if (x<0||y<0||x>=sz||y>=csz||grid[x][y]==0) { continue; }
					int cid = grid[x][y];
					if (used.find(cid) != used.end()) { continue; }
					used.insert(cid);
					cur += size[cid];
				}
				ans = max(cur, ans);
			}
		}
		return ans;
	}
};

int main() {
	int x, y; cin >> x >> y;
	vector<vector<int>> m(x, vector<int>(y));
	for (int i=0; i<x; ++i) { for (int j=0; j<y; ++j) { cin >> m[i][j]; } }
	Solution sol;
	cout << sol.largestIsland(m) << endl;
	return 0;
}
