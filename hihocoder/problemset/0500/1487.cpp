#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

const int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int sea[MAXN+2][MAXN+2];
int f[MAXN*MAXN+1], w[MAXN*MAXN+1];

int get_parent(int x) {
	while (x != f[x]) {
		f[x] = f[f[x]];
		x = f[x];
	}

	return x;
}

bool merge(int a, int b) {
	int pa = get_parent(a), pb = get_parent(b);
	if (pa == pb) { return false; }

	if (w[pa] >= w[pb]) {
		f[pb] = pa;
		w[pa] += w[pb];
	} else if (w[pa] < w[pb]) {
		f[pa] = pb;
		w[pb] += w[pa];
	}

	return true;
}

int main() {
	memset(sea, 0, sizeof(sea));

	int c = 0, s = 0, d = 0;
	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		int x, y; scanf("%d %d", &x, &y);
		++x; ++y;
		if (sea[x][y] == 0) {
			f[i] = i; w[i] = 1;
			++s; ++c;
			for (int j=0; j<4; ++j) {
				int xx = x + dir[j][0], yy = y + dir[j][1];
				if (sea[xx][yy] == 0) {
					++d;
				} else {
					if (merge(sea[xx][yy], i)) { --c; }
					--d;
				}
			}

			sea[x][y] = get_parent(i);
		}
		printf("%d %d %d\n", c, s, d);
	}

	return 0;
}
