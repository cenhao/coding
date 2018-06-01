class Solution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		if (rooms.empty() || rooms[0].empty()) { return; }

		const static int mov[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		int rsz = rooms.size(), csz = rooms[0].size();
		queue<pair<int, int>> q;
		for (int i=0; i<rsz; ++i) {
			for (int j=0; j<csz; ++j) {
				if (rooms[i][j] == 0) { q.push(make_pair(i, j)); }
			}
		}

		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			int step = rooms[p.first][p.second]+1;
			for (int i=0; i<4; ++i) {
				int x = p.first+mov[i][0], y = p.second+mov[i][1];
				if (x<0 || x>=rsz || y<0 || y>=csz || rooms[x][y]==-1 || step>=rooms[x][y]) {
					continue;
				}
				rooms[x][y] = step;
				q.push(make_pair(x, y));
			}
		}
	}
};
