#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAXN 100

char caf[MAXN][MAXN+1];
int vis[MAXN][MAXN];
const int mov[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

struct Position {
	int x, y;
	int step;

	bool operator < (const Position &p) const {
		return step > p.step;
	}
};

int main(){
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i) { scanf("%s", caf[i]); }

	int sx = -1, sy;
	for (int i=0; i<n && sx == -1; ++i) {
		for (int j=0; j<m; ++j) {
			if (caf[i][j] == 'H') {
				sx = i; sy = j;
				break;
			}
		}
	}

	memset(vis, -1, sizeof(vis));
	Position cur = { sx, sy, 0 };
	vis[sx][sy] = 0;
	queue<Position> q;
	q.push(cur);

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int i=0; i<4; ++i) {
			int x = cur.x + mov[i][0];
			int y = cur.y + mov[i][1];

			if (x < 0 || x >= n || y < 0 || y >= m ||
				(caf[x][y] != '.' && caf[x][y] != 'S') ||
				vis[x][y] != -1) {
				continue;
			}

			vis[x][y] = cur.step + 1;
			if (caf[x][y] == 'S') { continue; }
			Position tmp = { x, y, vis[x][y] };
			q.push(tmp);
		}
	}

	int mn = 0x7fff0000;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m-1; ++j) {
			if (caf[i][j] != 'S' || vis[i][j] == -1) { continue; }
			if (caf[i][j+1] == 'S' && vis[i][j+1] != -1) {
				mn = min(mn, vis[i][j] + vis[i][j+1]);
			}
			if (caf[i+1][j] == 'S' && vis[i+1][j] != -1) {
				mn = min(mn, vis[i][j] + vis[i+1][j]);
			}
		}
	}

	if (mn == 0x7fff0000) {
		printf("Hi and Ho will not have lunch.\n");
	} else {
		printf("%d\n", mn);
	}

	return 0;
}
