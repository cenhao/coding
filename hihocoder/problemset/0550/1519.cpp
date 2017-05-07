#include <bits/stdc++.h>
using namespace std;

#define MAXN 500

const int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
char mat[MAXN+2][MAXN+2];
int step[MAXN+2][MAXN+2][4];

struct QItem {
	int x, y, d, cnt;
	bool operator <(const QItem &qi) const {
		return cnt > qi.cnt;
	}
};

int bfs(int sx, int sy, int ex, int ey) {
	memset(step, -1, sizeof(step));
	priority_queue<QItem> q;
	for (int i=0; i<4; ++i) {
		QItem item = {sx, sy, i, 0};
		q.push(item);
		step[sx][sy][i] = 0;
	}

	while (!q.empty()) {
		QItem cur = q.top(); q.pop();
		if (cur.cnt > step[cur.x][cur.y][cur.d]) { continue; }

		for (int i=0; i<4; ++i) {
			int x = cur.x, y = cur.y;
			while (mat[x+dir[i][0]][y+dir[i][1]] != '#') {
				x += dir[i][0]; y += dir[i][1];
				if (mat[x][y] == 'T') { break; }
			}

			if (x == cur.x && y == cur.y) { continue; }
			int cost = cur.cnt + ((cur.d == i) ? 0 : 1);
			if (step[x][y][i] == -1 || cost < step[x][y][i]) {
				step[x][y][i] = cost;
				QItem tmp = { x, y, i, cost };
				q.push(tmp);
			}
		}
	}
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	int sx, sy, ex, ey;
	memset(mat, '#', sizeof(mat));
	for (int i=1; i<=n; ++i) {
		scanf("%s", &mat[i][1]);
		mat[i][m+1] = '#';
		for (int j=1; j<=m; ++j) {
			if (mat[i][j] == 'S') {
				sx = i; sy = j;
			} else if (mat[i][j] == 'T') {
				ex = i; ey = j;
			}
		}
	}

	bfs(sx, sy, ex, ey);
	int mn = 0x7fffffff;
	for (int i=0; i<4; ++i) {
		if (step[ex][ey][i] >= 0) { mn = min(mn, step[ex][ey][i]); }
	}
	if (mn == 0x7fffffff) { mn = -1; }
	printf("%d\n", mn);
	return 0;
}
