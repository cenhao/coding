#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

const int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

char mat[MAXN+2][MAXN+2];
int vis[MAXN+2][MAXN+2];
struct Location { int x, y; };

inline void flush_print(char c) {
	printf("%c\n", c);
	fflush(stdout);
}

inline void exit_if_finish(int &x, int &y) {
	scanf("%d%d", &x, &y);
	if (mat[x][y] == 'F') { exit(0); }
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	memset(mat, 0, sizeof(mat));
	int ex, ey;
	for (int i=1; i<=n; ++i) {
		scanf("%s", &mat[i][1]);
		for (int j=1; j<=m; ++j) {
			if (mat[i][j] == 'F') { ex = i; ey = j; }
		}
	}

	// find out dir
	bool vok = false, hok = false;
	bool vr = false, hr = false;
	int x = 1, y = 1;
	if (mat[1][2] == '.' || mat[1][2] == 'F') {
		flush_print('R');
		exit_if_finish(x, y);
		hok = true;
		hr = (y != 2);
	}

	if (mat[2][1] == '.' || mat[2][1] == 'F') {
		if (hok && !hr) {
			flush_print('L');
			exit_if_finish(x, y);
		}
		flush_print('D');
		exit_if_finish(x, y);
		vok = true;
		vr = (x != 2);
	}

	if (!hok) {
		while (mat[x][y+1] != '.' && mat[x][y+1] != 'F') {
			flush_print(vr ? 'U' : 'D');
			exit_if_finish(x, y);
		}

		flush_print('R');
		exit_if_finish(x, y);
		hr = (y != 2);
		hok = true;
	}

	if (!vok) {
		while (mat[x+1][y] != '.' && mat[x+1][y] != 'F') {
			flush_print(hr ? 'L' : 'R');
			exit_if_finish(x, y);
		}

		flush_print('D');
		exit_if_finish(x, y);
		vr = (x != 2);
		vok = true;
	}

	Location tmp = { x, y }, tmp1;
	memset(vis, -1, sizeof(vis));
	vis[x][y] = -2;
	queue<Location> q;
	q.push(tmp);
	bool found = false;

	while (!q.empty() && !found) {
		tmp = q.front(); q.pop();
		for (int i=0; i<4; ++i) {
			tmp1.x = tmp.x + dir[i][0]; tmp1.y = tmp.y + dir[i][1];
			if (vis[tmp1.x][tmp1.y] == -1 &&
				(mat[tmp1.x][tmp1.y] == '.' || mat[tmp1.x][tmp1.y] == 'F')) {
				vis[tmp1.x][tmp1.y] = i;

				if (mat[tmp1.x][tmp1.y] == 'F') {
					found = true;
					break;
				}
				q.push(tmp1);
			}
		}
	}

	vector<char> ans;
	while (vis[ex][ey] != -2) {
		int d = vis[ex][ey];
		if (dir[d][0] != 0) {
			bool up = dir[d][0] == -1;
			ans.push_back(up ? (vr ? 'D' : 'U') : (vr ? 'U' : 'D'));
		} else {
			bool left = dir[d][1] == -1;
			ans.push_back(left ? (hr ? 'R' : 'L') : (hr ? 'L' : 'R'));
		}
		ex -= dir[d][0]; ey -= dir[d][1];
	}

	for (int i=ans.size()-1; i>=0; --i) {
		flush_print(ans[i]);
		exit_if_finish(x, y);
	}

	return 0;
}
