/*
ID: cenhao11
PROG: camelot
LANG: C++11
*/

/*
 * This is the solution provided by usaco.
 * The idea is the calculate the cost for a knight to get to
 * any square with and without the king.
 * without the king it's simple shortest path(spfa), while with the king,
 * it can be:
 * 1. Move from a previous square that already has the king, or
 * 2. Move from a previous square without the king, and ask the king
 * 	to move to this square.
 *
 * So this can be done as shortest path with a heap.
 * Let n = rc, the cost is O(n^2logn)
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXC 26
#define MAXR 30

const int mov[8][2] = {
	{1, -2}, {2, -1}, {2, 1}, {1, 2},
	{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}
};

struct Position {
	int x, y, cnt;
	int withking;
	bool operator <(const Position& p) const {
		return cnt > p.cnt;
	}
};

int cost[MAXC][MAXR]; // the cost to gather all knights in i,j
int kcost[MAXC][MAXR]; // the extra cost to get king to i,j
int kdist[MAXC][MAXR]; // to move the king to (i, j)
int dist[MAXC][MAXR][2];
int king[2];

inline int getKingMoves(int x, int y, int x1, int y1) {
	return max(abs(x-x1), abs(y-y1));
}

inline bool within(int c, int r, int x, int y) {
	return x >= 0 && y >= 0 && x < c && y < r;
}

void spfa(int x, int y, int sx, int sy) {
	memset(dist, -1, sizeof(dist));
	Position pos, tmp;
	priority_queue<Position> q;
	pos.x = sx; pos.y = sy; pos.cnt = 0; pos.withking = 0;
	dist[sx][sy][0] = 0;
	q.push(pos);
	pos.cnt = kdist[sx][sy];
	pos.withking = 1;
	dist[sx][sy][1] = pos.cnt;
	q.push(pos);
	int vcnt = 0, end = x * y * 2;

	while (!q.empty() && vcnt<=end) {
		pos = q.top();
		q.pop();

		if (dist[pos.x][pos.y][pos.withking] != pos.cnt) { continue; }
		++vcnt;

		for (int wk=pos.withking; wk<2; ++wk) {
			tmp.withking = wk;
			for (int i=0; i<8; ++i) {
				tmp.x = pos.x + mov[i][0];
				tmp.y = pos.y + mov[i][1];
				tmp.cnt = pos.cnt + 1;
				if (wk == 1 && pos.withking == 0) {
					tmp.cnt += kdist[tmp.x][tmp.y];
				}
				if (!within(x, y, tmp.x, tmp.y) ||
						(dist[tmp.x][tmp.y][tmp.withking] != -1 && dist[tmp.x][tmp.y][tmp.withking] <= tmp.cnt)) {
					continue;
				}
				dist[tmp.x][tmp.y][tmp.withking] = tmp.cnt;
				q.push(tmp);
			}
		}
	}
}

int main() {
	freopen("camelot.in", "r", stdin);
	freopen("camelot.out", "w", stdout);

	int r, c;
	scanf("%d %d", &r, &c);
	memset(cost, 0, sizeof(cost));

	char colstr[3];
	int row, col, cnt = 0;
	scanf("%s %d", colstr, &row);
	king[0] = colstr[0] - 'A';
	king[1] = --row;

	for (int i=0; i<c; ++i) {
		for (int j=0; j<r; ++j) {
			kdist[i][j] = kcost[i][j] = getKingMoves(king[0], king[1], i, j);
		}
	}

	while (EOF != scanf("%s %d", colstr, &row)) {
		col = colstr[0] - 'A';
		--row;
		spfa(c, r, col, row);

		for (int i=0; i<c; ++i) {
			for (int  j=0; j<r; ++j) {
				if (dist[i][j][0] < 0) {
					cost[i][j] = -1;
					kcost[i][j] = -1;
				} else {
					cost[i][j] += dist[i][j][0];
					kcost[i][j] = min(kcost[i][j], dist[i][j][1]-dist[i][j][0]);
				}
			}
		}
	}

	int mn = 0x7ffffff0;
	for (int i=0; i<c; ++i) {
		for (int j=0; j<r; ++j) {
			if (cost[i][j] < 0) { continue; }
			mn = min(cost[i][j] + kcost[i][j], mn);
		}
	}

	printf("%d\n", mn);
}
