#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

const int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
const int reflect[4] = {2, 3, 0, 1};

int n, m;
char mat[MAXN][MAXN+5];
int vis[MAXN][MAXN][4];

void dfs(int x, int y, int k) {
	for (int i=0; i<4; ++i) {
		if (mat[x][y] == ' ' ||
			(mat[x][y] == '/' && ((i+k) == 1 || (i+k) == 5)) ||
			(mat[x][y] == '\\' && (i+k) == 3)) {
			if (vis[x][y][i] == 0) {
				vis[x][y][i] = vis[x][y][k];
				dfs(x, y, i);
			}
		}
	}

	int xx = x + dir[k][0], yy = y + dir[k][1], kk = reflect[k];
	if (xx >= 0 && xx < n && yy >= 0 && yy < m && vis[xx][yy][kk] == 0) {
		vis[xx][yy][kk] = vis[x][y][k];
		dfs(xx, yy, kk);
	}
}

int main() {
	fgets(mat[0], sizeof(mat[0]), stdin);
	sscanf(mat[0], "%d %d", &n, &m);
	for (int i=0; i<n; ++i) { fgets(mat[i], sizeof(mat[i]), stdin); }
	memset(vis, 0, sizeof(vis));

	int cnt = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			for (int k=0; k<4; ++k) {
				if (vis[i][j][k] != 0) { continue; }
				vis[i][j][k] = ++cnt;
				dfs(i, j, k);
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}
