/*
ID: cenhao11
PROG: camelot
LANG: C++11
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXC 26
#define MAXR 30
#define INF 0x7ffffff0

const int mov[8][2] = {
	{1, -2}, {2, -1}, {2, 1}, {1, 2},
	{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}
};

int dist[MAXR][MAXC][MAXR][MAXC];
int king[2];
int knight[MAXC*MAXR][2];
int proxy[MAXR*MAXC][2];
int pcnt;

struct Position {
	int x, y, cnt;
};

inline bool within(int r, int c, int x, int y) {
	return x >= 0 && y >= 0 && x < r && y < c;
}

int spfa(int r, int c, int x, int y) {
	queue<Position> q;
	Position pos = {x, y, 0}, tmp;
	q.push(pos);
	dist[x][y][x][y] = 0;

	while (!q.empty()) {
		pos = q.front();
		q.pop();

		tmp.cnt = pos.cnt + 1;
		for (int i=0; i<8; ++i) {
			tmp.x = pos.x + mov[i][0];
			tmp.y = pos.y + mov[i][1];
			if (!within(r, c, tmp.x, tmp.y) || dist[x][y][tmp.x][tmp.y] != -1) {
				continue;
			}
			dist[x][y][tmp.x][tmp.y] = tmp.cnt;
			q.push(tmp);
		}
	}
}

int spfa(int r, int c) {
	memset(dist, -1, sizeof(dist));

	for (int i=0; i<r; ++i) {
		for (int j=0; j<c; ++j) {
			spfa(r, c, i, j);
		}
	}
}

int process(int r, int c, int x, int y, int kcnt) {
	int sum = 0;
	for (int i=0; i<kcnt; ++i) {
		if (dist[x][y][knight[i][0]][knight[i][1]] < 0) {
			return INF;
		}
		sum += dist[x][y][knight[i][0]][knight[i][1]];
	}

	int mn = sum + max(abs(king[0]-x), abs(king[1]-y));
	for (int k=0; k<kcnt; ++k) {
		for (int i=0; i<pcnt; ++i) {
			if (dist[proxy[i][0]][proxy[i][1]][x][y] < 0) { continue; }
			int d = max(abs(king[0]-proxy[i][0]), abs(king[1]-proxy[i][1]));
			d += dist[proxy[i][0]][proxy[i][1]][x][y] + dist[proxy[i][0]][proxy[i][1]][knight[k][0]][knight[k][1]];
			d += sum - dist[x][y][knight[k][0]][knight[k][1]];
			mn = min(d, mn);
		}
	}

	return mn;
}

int process(int r, int c, int kcnt) {
	int mn = 0x7ffffff0;
	for (int i=0; i<r; ++i) {
		for (int j=0; j<c; ++j) {
			mn = min(mn, process(r, c, i, j, kcnt));
		}
	}

	return mn;
}

void calcPossibleProxy(int r, int c) {
	int x = king[0], y = king[1];
	for (int i=0; i<r; ++i) {
		for (int j=0; j<c; ++j) {
			int d = max(abs(i-x), abs(j-y));
			if (dist[x][y][i][j] >= d) {
				proxy[pcnt][0] = i;
				proxy[pcnt][1] = j;
				++pcnt;
			}
		}
	}
}

int main() {
	freopen("camelot.in", "r", stdin);
	freopen("camelot.out", "w", stdout);

	int r, c;
	scanf("%d %d", &r, &c);

	char colstr[3];
	int row, col, cnt = 0;
	while (EOF != scanf("%s %d", colstr, &row)) {
		col = colstr[0] - 'A';
		--row;
		if (cnt++ == 0) {
			king[0] = row; king[1] = col;
		} else {
			knight[cnt-2][0] = row; knight[cnt-2][1] = col;
		}
	}

	--cnt;
	spfa(r, c);
	calcPossibleProxy(r, c);
	printf("%d\n", process(r, c, cnt));
}
