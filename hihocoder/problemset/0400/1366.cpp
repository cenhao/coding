#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
#define MOD 1000000007
#define LOWBIT(x) (x & (~(x-1)))

int64_t bits[MAXN+1][MAXN+1];
char cmd[4];

void add1d(int x, int y, int v, int n) {
	while (y <= n) {
		bits[x][y] += v;
		y += LOWBIT(y);
	}
}

void add2d(int x, int y, int v, int n) {
	while (x <= n) {
		add1d(x, y, v, n);
		x += LOWBIT(x);
	}
}

int64_t sum1d(int x, int y) {
	int64_t sum = 0;
	while (y > 0) {
		sum += bits[x][y];
		y -= LOWBIT(y);
	}
	return sum;
}

int64_t sum2d(int x, int y) {
	int64_t sum = 0;
	while (x > 0) {
		sum += sum1d(x, y);
		x -= LOWBIT(x);
	}
	return sum;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	memset(bits, 0, sizeof(bits));
	for (int i=0; i<m; ++i) {
		scanf("%s", cmd);
		if (cmd[0] == 'A') {
			int x, y, v; scanf("%d%d%d", &x, &y, &v);
			add2d(++x, ++y, v, n);
		} else {
			int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			++x1; ++y1; ++x2; ++y2;
			int64_t ans = sum2d(x2, y2)-sum2d(x2, y1-1)-sum2d(x1-1, y2)+sum2d(x1-1, y1-1);
			ans %= MOD;
			if (ans < 0) { ans += MOD; }
			printf("%" PRId64 "\n", ans);
		}
	}

	return 0;
}
