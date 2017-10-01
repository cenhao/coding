#include <bits/stdc++.h>
using namespace std;

#define MAXN 60
int ans[MAXN][MAXN];

void fill_1(int n, int x, int y, int t) {
	int xinc = (x==0) ? 1:-1, yinc = (y==0) ? 1:-1, cnt = 0;
	if (t == 0) {
		while (x>=0 && x<n) {
			while (y>=0 && y<n) {
				ans[x][y] = ++cnt;
				y += yinc;
			}

			yinc *= -1;
			x += xinc; y += yinc;
		}
	} else {
		while (y>=0 && y<n) {
			while (x>=0 && x<n) {
				ans[x][y] = ++cnt;
				x += xinc;
			}

			xinc *= -1;
			y += yinc; x += xinc;
		}
	}
}

void fill_2(int n, int x, int y, int t) {
	int xinc = (x==0) ? 1:-1, yinc = (y==0) ? 1:-1, cnt = 0;
	int sx = x, sy = y;
	if (t == 0) {
		while (x>=0 && x<n) {
			ans[x][y] = ++cnt;
			x += xinc;
		}

		xinc *= -1;
		x += xinc; y += yinc;
		while (x>=0 && x<n) {
			while (y!=sy && y>=0 && y<n) {
				ans[x][y] = ++cnt;
				y += yinc;
			}

			yinc *= -1;
			x += xinc; y += yinc;
		}
	} else {
		while (y>=0 && y<n) {
			ans[x][y] = ++cnt;
			y += yinc;
		}

		yinc *= -1;
		y += yinc; x += xinc;
		while (y>=0 && y<n) {
			while (x!=sx && x>=0 && x<n) {
				ans[x][y] = ++cnt;
				x += xinc;
			}

			xinc *= -1;
			y += yinc; x += xinc;
		}
	}
}

int main() {
	int n; scanf("%d", &n);
	char swd[2]; scanf("%s", swd);
	int x, y; scanf("%d%d", &x, &y);

	if (swd[0] == 'n' || swd[0] == 's') {
		if ((swd[0] == 'n' && x == 0) || (swd[0] == 's' && x != 0)) {
			fill_1(n, x, y, 0);
		} else {
			fill_2(n, x, y, 0);
		}
	} else {
		if ((swd[0] == 'w' && y == 0) || (swd[0] == 'e' && y != 0)) {
			fill_1(n, x, y, 1);
		} else {
			fill_2(n, x, y, 1);
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			printf("%d%c", ans[i][j], (j == n-1) ? '\n' : ' ');
		}
	}

	return 0;
}
