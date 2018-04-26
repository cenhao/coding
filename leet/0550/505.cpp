class Solution {
public:
	bool block(int x, int y, const vector<vector<int>> &maze) {
		int rsz = maze.size(), csz = maze[0].size();
		return (x<0 || x>=rsz || y<0 || y>=csz || maze[x][y]==1);
	}
	struct QItem {
		QItem(int xx, int yy, int c) : x(xx), y(yy), cnt(c) {}
		int x, y, cnt;
		bool operator <(const QItem &q) const {
			return cnt > q.cnt; // min heap
		}
	};
	int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		int rsz = maze.size(), csz = maze[0].size();
		vector<vector<int>> step(rsz, vector<int>(csz, -1));
		step[start[0]][start[1]] = 0;
		queue<QItem> q;
		q.push(QItem(start[0], start[1], 0));
		const int mov[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		while (!q.empty()) {
			auto item = q.front(); q.pop();
			if (item.cnt > step[item.x][item.y]) { continue; }
			for (int i=0; i<4; ++i) {
				int cx = item.x, cy = item.y;
				int cnt = item.cnt;
				while (!block(cx+mov[i][0], cy+mov[i][1], maze)) {
					++cnt;
					cx += mov[i][0]; cy += mov[i][1];
				}
				if (step[cx][cy] < 0 || step[cx][cy] > cnt) {
					step[cx][cy] = cnt;
					q.push(QItem(cx, cy, cnt)); 
				}
			}
		}

		return step[destination[0]][destination[1]];
	}
};
