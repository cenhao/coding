#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAXN 800
#define INF 20000

const int mov[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

char buff[MAXN];
int mat[MAXN][MAXN];

struct Position {
	int x, y;
};

int main() {
	memset(mat, 0x7f, sizeof(mat));

	int n, m; scanf("%d %d", &n, &m);
	Position tmp, tmp1;
	queue<Position> q;
	for (int i=0; i<n; ++i) {
		scanf("%s", buff);
		for (int j=0; j<n; ++j) {
			if (buff[j] == '0') {
				tmp.x = i; tmp.y = j;
				q.push(tmp);
				mat[i][j] = 0;
			} else {
				mat[i][j] = INF;
			}
		}
	}

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		for (int i=0; i<4; ++i) {
			tmp1.x = tmp.x + mov[i][0];
			tmp1.y = tmp.y + mov[i][1];

			if (tmp1.x < 0 || tmp1.x >= n ||
				tmp1.y < 0 || tmp1.y >= m ||
				mat[tmp.x][tmp.y]+1 >= mat[tmp1.x][tmp1.y]) {
				continue;
			}

			mat[tmp1.x][tmp1.y] = mat[tmp.x][tmp.y] + 1;
			q.push(tmp1);
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			printf("%d%c", mat[i][j], (j==m-1) ? '\n' : ' ');
		}
	}

	return 0;
}
