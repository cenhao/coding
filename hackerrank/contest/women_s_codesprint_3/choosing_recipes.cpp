#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXP 13
#define MAXR 30

int recipes[MAXR];
int c[MAXP];
int buy[1<<MAXP];

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int r, p, n, m; scanf("%d %d %d %d", &r, &p, &n, &m);
		memset(c, -1, sizeof(c));
		memset(buy, 0, sizeof(buy));
		for (int i=0; i<m; ++i) {
			int v; scanf("%d", &v);
			c[v] = 0;
		}

		for (int i=0; i<p; ++i) {
			int v; scanf("%d", &v);
			if (c[i] != 0) { c[i] = v; }
			buy[1<<i] = c[i];
		}

		int zcnt = 0;
		for (int i=0; i<r; ++i) {
			recipes[i] = 0;
			for (int j=0; j<p; ++j) {
				int v; scanf("%d", &v);
				if (v == 1) { recipes[i] |= 1<<j; }
			}

			if (recipes[i] == 0) { ++zcnt; }
		}

		if (zcnt >= n) {
			printf("0\n");
			continue;
		}

		int mn = 0x7fffffff;
		for (int i=1, end=1<<p; i<end; ++i) {
			int lowbit = i & (~(i-1));
			int x = i - lowbit;
			buy[i] = buy[x] + buy[lowbit];

			int cnt = 0;
			for (int j=0; j<r; ++j) {
				if ((i & recipes[j]) == recipes[j]) { ++cnt; }
			}

			if (cnt >= n) {
				mn = min(mn, buy[i]);
			}
		}

		printf("%d\n", mn);
	}

	return 0;
}
