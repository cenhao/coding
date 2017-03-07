#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAXN 500

int mx[MAXN*MAXN][2], mn[MAXN*MAXN][2];
int mat[MAXN][MAXN];
char buff[MAXN+1];
int mov[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

struct Pos {
	int x, y;
};

void bfs(int x, int y, int n, int m, int v) {
	queue<Pos> q;
	mat[x][y] = v;
	Pos item = { x, y }, tmp;
	q.push(item);

	while (!q.empty()) {
		item = q.front(); q.pop();
		for (int i=0; i<4; ++i) {
			tmp.x = item.x+mov[i][0]; tmp.y = item.y+mov[i][1];
			if (tmp.x < 0 || tmp.x >= n || tmp.y < 0 || tmp.y >= m || mat[tmp.x][tmp.y] != 1) {
				continue;
			}

			mat[tmp.x][tmp.y] = v;
			q.push(tmp);
		}
		mx[v][0] = max(mx[v][0], item.x); mn[v][0] = min(mn[v][0], item.x);
		mx[v][1] = max(mx[v][1], item.y); mn[v][1] = min(mn[v][1], item.y);
	}
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i) {
		scanf("%s", buff);
		for (int j=0; j<m; ++j) { mat[i][j] = buff[j] - '0'; }
	}

	memset(mn, 0x7f, sizeof(mn));
	memset(mx, -1, sizeof(mx));
	int nxt = 2;
	for (int i=0; i<m; ++i) {
		for (int j=0; j<n; ++j) {
			if (mat[j][i] != 1) { continue; }
			bfs(j, i, n, m, nxt++);
		}
	}

	for (int i=2; i<nxt; ++i) {
		printf("%d %d\n", mx[i][0]-mn[i][0]+1, mx[i][1]-mn[i][1]+1);
		for (int j=mn[i][0]; j<=mx[i][0]; ++j) {
			for (int k=mn[i][1]; k<=mx[i][1]; ++k) {
				printf("%d", mat[j][k] == i ? 1 : 0);
			}

			printf("\n");
		}
	}

	return 0;
}
