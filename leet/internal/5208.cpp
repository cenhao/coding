#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumMoves(vector<vector<int>>& grid) {
		int rsz = grid.size(), csz = grid[0].size();
		int prod = rsz * csz;
		auto calc = [&](int x1, int y1, int x2, int y2) {
			int v1 = x1 * csz + y1, v2 = x2 * csz + y2;
			return v2 * prod + v1;
		};

		queue<pair<int, int>> q;
		q.push(make_pair(calc(0, 0, 0, 1), 0));
		unordered_set<int> hs;
		hs.insert(calc(0, 0, 0, 1));
		while (!q.empty()) {
			auto p = q.front(); q.pop();
			int tmp = p.first;
			int v1 = tmp % prod, v2 = tmp / prod;
			int x1 = v1 / csz, y1 = v1 % csz;
			int x2 = v2 / csz, y2 = v2 % csz;
			if (x1==rsz-1 && y1==csz-2 && x2==rsz-1 && y2==csz-1) { return p.second; }

			if (x1 == x2) { // horizontal
				if (y2+1<csz && grid[x2][y2+1]==0) { // 1. right;
					int v = calc(x2, y2, x2, y2+1);
					auto it = hs.find(v);
					if (it == hs.end()) {
						q.push(make_pair(v, p.second+1));
						hs.insert(v);
					}
				}
				if (x1+1<rsz && grid[x1+1][y1]==0 && grid[x1+1][y2]==0) {
					int v = calc(x1, y1, x1+1, y1);
					if (hs.find(v) == hs.end()) {
						q.push(make_pair(v, p.second+1));
						hs.insert(v);
					}
					v = calc(x1+1, y1, x2+1, y2);
					if (hs.find(v) == hs.end()) {
						q.push(make_pair(v, p.second+1));
						hs.insert(v);
					}

				}
			}

			if (y1 == y2) { // vertical
				if (x2+1<rsz && grid[x2+1][y2]==0) { // 2. down
					int v = calc(x2, y2, x2+1, y2);
					auto it = hs.find(v);
					if (it == hs.end()) {
						q.push(make_pair(v, p.second+1));
						hs.insert(v);
					}
				}
				if (y1+1<csz && grid[x1][y1+1]==0 && grid[x2][y1+1]==0) {
					int v = calc(x1, y1, x1, y1+1);
					if (hs.find(v) == hs.end()) {
						q.push(make_pair(v, p.second+1));
						hs.insert(v);
					}
					v = calc(x1, y1+1, x2, y2+1);
					if (hs.find(v) == hs.end()) {
						q.push(make_pair(v, p.second+1));
						hs.insert(v);
					}
				}
			}
		}

		return -1;
	}
};

int main() {
	vector<vector<int>> g = { {0,0,0,0,0,1},{1,1,0,0,1,0},{0,0,0,0,1,1},{0,0,1,0,1,0},{0,1,1,0,0,0},{0,1,1,0,0,0} };
	Solution sol;
	cout << sol.minimumMoves(g) << endl;
	return 0;
}
