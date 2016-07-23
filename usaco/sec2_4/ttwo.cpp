/*
ID: cenhao11
PROG: ttwo
LANG: C++11
*/

/*
 * Three scenarios:
 * 1. Both cow and farmer are not in the circle:
 * 	The first cell visit time has to be the same
 * 2. One of them is in the circle:
 * 	See if the one in the circle can reach the one not in the circle's first visit time
 * 	by looping in the circle
 * 3. Both are in the circle:
 * 	Chinese remainder princle, but the modulo might not be relatively prime with each other.
 * 	But still this can be solved.
 * 	Given a + k1*n1 = b + k2*n2
 * 	=> a - b + k1*n1 = k2*n2
 * 	gcd = GCD(n1, n2), the equation has solution iff gcd | (a - b), as gcd | k2*n2,
 * 	so (a-b + k1*n1) should be dividable by gcd as well.
 * 	so we have k2*n2 = (a-b) (mod n1).
 * 	Let c = (a - b)/gcd, n1' = n1/gcd, n2'=n2/gcd, the equation can be simplified to
 * 	k2*n2' = c (mod n1'), and gcd(n1', n2') = 1, so we can use extended eculidean algorithem
 * 	to calculate the modulo muliplicative inverse for n2', so that we have
 * 	k2 * n2' * (n2')^(-1) = c * (n2')^(-1) (mod n1')
 * 	=> k2 = c * (n2')^(-1) (mod n1')
 * 	so we can enumerate the possible k2 to find out the first sutable solution.
 */

#include <stdio.h>
#include <string.h>

#define MAXN 10

const int mov[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
char grid[MAXN+2][MAXN+5];
int vis[2][MAXN+1][MAXN+1][4];
int pos[2][2];
int circle[2];
int start[2];

int gcd, s, t;

void traverse(int p) {
	int x = pos[p][0];
	int y = pos[p][1];
	int dir = 0;
	int cnt = 0;

	while (vis[p][x][y][dir] < 0) {
		vis[p][x][y][dir] = cnt++;
		if (grid[x+mov[dir][0]][y+mov[dir][1]] == '*') {
			dir = (dir + 1) % 4;
		} else {
			x += mov[dir][0];
			y += mov[dir][1];
		}
	}

	start[p] = vis[p][x][y][dir];
	circle[p] = cnt - vis[p][x][y][dir];
}

int egcd(int a, int b, int *s, int *t) {
	int ns = 0, nt = 1;
	*s = 1;
	*t = 0;

	while (b != 0) {
		int q = a / b;
		int tmp = a;
		a = b;
		b = tmp - q * b;
		tmp = *s;
		*s = ns;
		ns = tmp - q * ns;
		tmp = *t;
		*t = nt;
		nt = tmp - q * nt;
	}

	return a;
}

int check(int x, int y) {
	int mn = 0x7fffffff;
	for (int i=0; i<4; ++i) {
		if (vis[0][x][y][i] < 0) { continue; }
		for (int j=0; j<4; ++j) {
			if (vis[1][x][y][j] < 0) { continue; }
			if (vis[0][x][y][i] == vis[1][x][y][j]) {
				mn = (vis[0][x][y][i] < mn) ? vis[0][x][y][i] : mn;
			} else if(vis[0][x][y][i] >= start[0] && vis[1][x][y][j] >= start[1]) {
				int a = vis[0][x][y][i];
				int b = vis[1][x][y][j];
				int c = a - b;
				int q, r;
				if (c % gcd == 0) {
					int n[2] = { circle[0], circle[1] };
					if (c < 0) {
						q = -c / n[0];
						r = c % n[0];
						q += (r == 0) ? 0 : 1;
						c += q * n[0];
					}

					c = c / gcd * t;
					n[0] /= gcd;
					n[1] /= gcd;

					if (c < 0) {
						q = -c / n[0];
						r = c % n[0];
						q += (r == 0) ? 0 : 1;
						c += q * n[0];
					}

					c %= n[0];
					while ((c * circle[1] + b - a) / circle[0] < 0) { c += n[0]; }
					c = c * circle[1] + vis[1][x][y][j];
					mn = (c < mn) ? c : mn;
				}
			} else if (vis[0][x][y][i] >= start[0]) {
				if (vis[1][x][y][j] >= vis[0][x][y][i] && (vis[1][x][y][j] - vis[0][x][y][i]) % circle[0] == 0) {
					mn = (vis[1][x][y][j] < mn) ? vis[1][x][y][j] : mn;
				}
			} else if (vis[1][x][y][j] > start[1]) {
				if (vis[0][x][y][i] > vis[1][x][y][j] && (vis[0][x][y][i] - vis[1][x][y][j]) % circle[1] == 0) {
					mn = (vis[0][x][y][i] < mn) ? vis[0][x][y][i] : mn;
				}
			}
		}
	}

	return mn;
}

int find() {
	gcd = egcd(circle[0], circle[1], &s, &t);
	int mn = 0x7fffffff;
	for (int i=1; i<=MAXN; ++i) {
		for (int j=1; j<=MAXN; ++j) {
			int res = check(i, j);
			mn = (res < mn) ? res : mn;
		}
	}

	return (mn == 0x7fffffff) ? 0 : mn;
}

int main() {
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
	memset(grid, '*', sizeof(grid));
	memset(vis, -1, sizeof(vis));
	for (int i=1; i<=MAXN; ++i) {
		scanf("%s", &grid[i][1]);
		grid[i][11] = '*';

		for (int j=1; j<=MAXN; ++j) {
			if (grid[i][j] == 'C') {
				pos[0][0] = i;
				pos[0][1] = j;
			} else if(grid[i][j] == 'F') {
				pos[1][0] = i;
				pos[1][1] = j;
			}
		}
	}

	traverse(0);
	traverse(1);
	printf("%d\n", find());

	return 0;
}
