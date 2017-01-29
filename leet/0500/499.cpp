#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
	public:
	struct Status {
		Status() {
			vis = false;
			cost = -1;
		}

		int cost;
		bool vis;
	};

	struct Pos {
		int x, y;
		int cost;
		bool operator <(const Pos &p1) const { return cost > p1.cost; }
	};

	bool can_move(int x, int y, const vector<vector<int>> &maze) {
		return (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 0);
	}

	void dfs(int x, int y, int sx, int sy, string &str, vector<vector<Status>> &sm, vector<vector<int>> &maze) {
		const static char name[4] = { 'd', 'l', 'r', 'u' };
		const static int mov[4][2] = { {1, 0}, {0, -1}, {0, 1}, {-1, 0} };

		if (x == sx && y == sy) {
			return;
		}

		string mn = "z";
		for (int i=0; i<4; ++i) {
			for (int j=1; ; ++j) {
				int xx = x - mov[i][0]*j, yy = y-mov[i][1]*j;
				if (!can_move(xx, yy, maze)) { break; }
				if (sm[xx][yy].cost + j != sm[x][y].cost) { continue; }
				string tmp;
				dfs(xx, yy, sx, sy, tmp, sm, maze);
				tmp += name[i];
				if (tmp < mn) { mn = move(tmp); }
			}
		}

		str = move(mn);
	}

	string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
		const static int mov[4][2] = { {1, 0}, {0, -1}, {0, 1}, {-1, 0} };
		vector<vector<Status>> sm(maze.size(), vector<Status>(maze[0].size()));
		sm[ball[0]][ball[1]].vis = true;
		sm[ball[0]][ball[1]].cost = 0;
		priority_queue<Pos> q;
		Pos tmp = { ball[0], ball[1], 0 }, tmp1;
		q.push(tmp);

		while (!q.empty()) {
			tmp = q.top();
			q.pop();
			if (tmp.cost > sm[tmp.x][tmp.y].cost) { continue; }

			for (int i=0; i<4; ++i) {
				int cnt = 0, x = tmp.x, y = tmp.y;
				while (can_move(x+mov[i][0], y+mov[i][1], maze)) {
					++cnt;
					x += mov[i][0]; y += mov[i][1];
					if (x == hole[0] && y == hole[1]) { break; }
				}

				if (cnt == 0) { continue; }
				if (!sm[x][y].vis || tmp.cost+cnt <= sm[x][y].cost) {
					sm[x][y].vis = true;
					if (sm[x][y].cost == -1 || tmp.cost+cnt < sm[x][y].cost) {
						sm[x][y].cost = tmp.cost+cnt;
						if (x != hole[0] || y != hole[1]) {
							tmp1.x = x, tmp1.y = y, tmp1.cost = sm[x][y].cost;
							q.push(tmp1);
						}
					}
				}
			}
		}

		string ans;
		if (sm[hole[0]][hole[1]].vis) {
			dfs(hole[0], hole[1], ball[0], ball[1], ans, sm, maze);
			return ans;
		} else {
			return string("impossible");
		}
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> maze(n, vector<int>(m));
	for (int i=0; i<n; ++i) { for (int j=0; j<m; ++j) { cin >> maze[i][j]; } }
	vector<int> b(2); cin >> b[0] >> b[1];
	vector<int> h(2); cin >> h[0] >> h[1];

	Solution sol;
	cout << sol.findShortestWay(maze, b, h) << endl;
	return 0;
}
