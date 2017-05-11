#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

const int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
char mat[MAXN+2][MAXN+2];
int vis[26];

struct Position { int x, y; };

int main() {
	memset(mat, '.', sizeof(mat));
	memset(vis, 0, sizeof(vis));
	int n, m; char c;
	scanf("%d %d %c", &n, &m, &c);
	vis[c-'A'] = true;
	int sx, sy;
	for (int i=1; i<=n; ++i) {
		scanf("%s", &mat[i][1]);
		mat[i][m+1] = '.';
		for (int j=1; j<=m; ++j) {
			if (mat[i][j] == c) {
				sx = i; sy = j;
				break;
			}
		}
	}

	mat[sx][sy] = '.';
	Position tmp = { sx, sy };
	queue<Position> q;
	q.push(tmp);
	int ans = 0;

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		for (int i=0; i<4; ++i) {
			Position nxt = { tmp.x + dir[i][0], tmp.y + dir[i][1] };
			if (mat[nxt.x][nxt.y] == '.') { continue; }
			char color = mat[nxt.x][nxt.y];
			mat[nxt.x][nxt.y] = '.';
			if (!vis[color-'A']) {
				vis[color-'A'] = true;
				++ans;
			}

			if (color == c) { q.push(nxt); }
		}
	}

	printf("%d\n", ans);
	return 0;
}
