/*
ID: cenhao11
PROG: castle
LANG: C++11
*/

#include <stdio.h>
#include <string.h>

#define MAXN 55
#define MAXR (MAXN * MAXN)

const int mov[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

int castle[MAXN][MAXN];
int size[MAXR];
int room[MAXN][MAXN];
int cnt;

int lableRoom(int x, int y, int num) {
	if (room[x][y] != 0) { return 0; }

	room[x][y] = num;
	int sum = 1;
	for (int i=0; i<4; ++i) {
		if ((castle[x][y] & (1 << i)) == 0) {
			sum += lableRoom(x+mov[i][0], y+mov[i][1], num);
		}
	}

	return sum;
}

void lable(int m, int n) {
	cnt = 0;
	int mx = -1;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			if (room[i][j] != 0) { continue; }
			++cnt;
			size[cnt] = lableRoom(i, j, cnt);
			mx = (size[cnt] > mx) ? size[cnt] : mx;
		}
	}

	printf("%d\n%d\n", cnt, mx);
}

void merge(int m, int n) {
	int mx = -1;
	int x, y, d;
	for (int j=m; j>0; --j) {
		for (int i=1; i<=n; ++i) {
			for (int k=2; k>0; --k) {
				if ((castle[i][j] & (1<<k)) > 0 && room[i][j] != room[i+mov[k][0]][j+mov[k][1]]) {
					int tmp = size[room[i][j]] + size[room[i+mov[k][0]][j+mov[k][1]]];
					if (tmp >= mx) {
						mx = tmp;
						x = i; y = j; d = k;
					}
				}
			}
		}
	}

	printf("%d\n", mx);
	printf("%d %d %c\n", x, y, (d == 1) ? 'N' : 'E');
}

int main() {
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);

	int m, n;
	scanf("%d%d", &m, &n);
	memset(castle, 0, sizeof(castle));
	memset(size, 0, sizeof(size));
	memset(room, 0, sizeof(room));

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			scanf("%d", &castle[i][j]);
		}
	}

	lable(m, n);
	merge(m, n);

	return 0;
}
