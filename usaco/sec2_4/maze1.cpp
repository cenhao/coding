/*
ID: cenhao11
PROG: maze1
LANG: C++11
*/

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define MAXW 38
#define MAXH 100

#define NORTH (0)
#define EAST  (1)
#define SOUTH (2)
#define WEST  (3)
const int Move[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
const int Block[4] = { 0x01, 0x02, 0x04, 0x08 };

int field[MAXH+2][MAXW+2];
int mn[MAXH+2][MAXW+2];
int entrances[2][2];

void read(int w, int h) {
	memset(field, 0, sizeof(field));
	char buff[MAXW*2+10];
	fgets(buff, MAXW*2 + 10, stdin); // read `\n`
	int eh = 2 * h + 1;
	int ew = 2 * w + 1;
	int x, y;
	int ecnt = 0;
	for (int i=0; i<eh; ++i) {
		fgets(buff, MAXW*2+10, stdin);
		x = i / 2 + 1;
		for (int j=0; j<ew; ++j) {
			y = (j + 1) / 2;
			if (buff[j] == '-') {
				field[x][y] |= Block[NORTH];
				field[x-1][y] |= Block[SOUTH];
			} else if (buff[j] == '|') {
				field[x][y] |= Block[EAST];
				field[x][y+1] |= Block[WEST];
			} else if (buff[j] == ' ') {
				if (i == 0) {
					entrances[ecnt][0] = 1;
					entrances[ecnt++][1] = y;
					field[1][y] |= Block[NORTH];
				} else if (i == eh - 1) {
					entrances[ecnt][0] = h;
					entrances[ecnt++][1] = y;
					field[h][y] |= Block[SOUTH];
				} else if (j == 0) {
					entrances[ecnt][0] = x;
					entrances[ecnt++][1] = 1;
					field[x][1] |= Block[WEST];
				} else if (j == ew - 1) {
					entrances[ecnt][0] = x;
					entrances[ecnt++][1] = w;
					field[x][w] |= Block[EAST];
				}
			}
		}
	}
}

struct Pos {
	int x;
	int y;
	int cnt;
};

int bfs(int w, int h) {
	memset(mn, 0x7f, sizeof(mn));
	queue<Pos> q;
	Pos p = { entrances[0][0], entrances[0][1], 1 };
	q.push(p);
	p.x = entrances[1][0], p.y = entrances[1][1], p.cnt = 1;
	q.push(p);

	while (!q.empty()) {
		p = q.front();
		q.pop();
		if (mn[p.x][p.y] <= p.cnt) { continue; }
		mn[p.x][p.y] = p.cnt;

		for (int i=0; i<4; ++i) {
			if (field[p.x][p.y] & Block[i]) { continue; }
			Pos tmp = { p.x + Move[i][0], p.y + Move[i][1], p.cnt + 1 };
			if (mn[tmp.x][tmp.y] > tmp.cnt) {
				q.push(tmp);
			}
		}
	}

	int mx = -1;
	for (int i=1; i<=h; ++i) {
		for (int j=1; j<=w; ++j) {
			if (mn[i][j] > mx) { mx = mn[i][j]; }
		}
	}

	return mx;
}

int main() {
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
	int w, h;
	scanf("%d %d", &w, &h);
	read(w, h);
	printf("%d\n", bfs(w, h));
	return 0;
}
