#include <bits/stdc++.h>
using namespace std;

#define MAXN 6
#define MAXMN 20
#define MAXD 5
#define MAXK 7

const int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

int dp[1<<MAXMN][MAXD+1];
int maze[MAXN][MAXN];
int hp[MAXK], ap[MAXK];
int att;

struct QItem {
	int state, inv, health;
	bool operator < (const QItem &qi) const {
		return health < qi.health;
	}
};

int main() {
	int n, m; scanf("%d %d", &n, &m);

	int fs = 0, mcnt = 0, ms = 0;
	for (int i=0; i<n; ++i) {
		char buff[16]; scanf("%s", buff);
		for (int j=0; j<m; ++j) {
			maze[i][j] = 0;
			if (buff[j] == 'D') { continue; }
			if (buff[j] != '.') {
				ms |= 1 << (i*m + j);
				maze[i][j] = buff[j] == 'M' ? 1 : -1;
				maze[i][j] *= ++mcnt;
			}
			fs |= 1 << (i*m + j);
		}
	}

	for (int i=0; i<mcnt; ++i) { scanf("%d %d", &hp[i], &ap[i]); }
	int health; scanf("%d %d", &health, &att);
	memset(dp, 0, sizeof(dp));
	dp[fs][MAXD] = health;
	QItem tmp = { fs, MAXD, health }, tmp1;
	priority_queue<QItem> pq;
	pq.push(tmp);

	int mx = 0;
	while (!pq.empty()) {
		tmp = pq.top(); pq.pop();
		if (tmp.health < dp[tmp.state][tmp.inv]) { continue; }

		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (tmp.state & (1<<(i*m+j))) { continue; }
				for (int k=0; k<4; ++k) {
					int x = i+dir[k][0], y = j+dir[k][1];
					if (x >= n || x < 0 || y >= m || y < 0 || !(tmp.state & (1<<(x*m+y)))) {
						continue;
					}

					tmp1.health = tmp.health;
					tmp1.inv = max(0, tmp.inv - 1);
					tmp1.state = tmp.state & (~(1<<(x*m+y)));

					if (maze[x][y] != 0) {
						int id = abs(maze[x][y]) - 1;
						int r = hp[id] / att + (hp[id] % att == 0 ? 0 : 1);
						int damage = max(0, r - tmp1.inv) * ap[id];
						tmp1.health -= damage; tmp1.inv= max(0, tmp1.inv - r);
						if (tmp1.health > 0 && maze[x][y] < 0) { tmp1.inv = MAXD; }
					}

					if (tmp1.health > dp[tmp1.state][tmp1.inv]) {
						dp[tmp1.state][tmp1.inv] = tmp1.health;
						if (tmp1.state & ms) {
							pq.push(tmp1);
						} else {
							mx = max(mx, tmp1.health);
						}
					}
				}
			}
		}
	}

	if (mx > 0) {
		printf("%d\n", mx);
	} else {
		printf("DEAD\n");
	}

	return 0;
}
