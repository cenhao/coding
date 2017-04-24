#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXL 1000000

struct Location {
	int x, y, id;
} hotels[MAXL];

int xcnt[MAXN+1], ycnt[MAXN+1];
int64_t dist[MAXL];

int main() {
	memset(xcnt, 0, sizeof(xcnt));
	memset(ycnt, 0, sizeof(ycnt));
	memset(dist, 0, sizeof(dist));

	int x, y, l, h; scanf("%d %d %d %d", &x, &y, &l, &h);
	for (int i=0; i<l; ++i) {
		int lx, ly; scanf("%d %d", &lx, &ly);
		++xcnt[lx]; ++ycnt[ly];
	}
	for (int i=0; i<h; ++i) {
		scanf("%d %d", &hotels[i].x, &hotels[i].y);
		hotels[i].id = i;
	}

	int64_t sum = 0, cnt = 0;
	for (int i=x; i>=1; --i) { cnt += xcnt[i]; sum += cnt; }
	sort(hotels, hotels+h, [](const Location &h1, const Location &h2) -> bool {
		return h1.x < h2.x;
	});
	int cur = 0;
	int64_t lcnt = 0, rcnt = cnt;
	for (int i=0; i<h; ++i) {
		while (cur < hotels[i].x) {
			lcnt += xcnt[cur++];
			sum += lcnt - rcnt;
			rcnt -= xcnt[cur];
		}

		dist[hotels[i].id] += sum;
	}

	sum = cnt = 0;
	for (int i=y; i>=1; --i) { cnt += ycnt[i]; sum += cnt; }
	sort(hotels, hotels+h, [](const Location &h1, const Location &h2) -> bool {
		return h1.y < h2.y;
	});
	cur = lcnt = 0, rcnt = cnt;
	for (int i=0; i<h; ++i) {
		while (cur < hotels[i].y) {
			lcnt += ycnt[cur++];
			sum += lcnt - rcnt;
			rcnt -= ycnt[cur];
		}

		dist[hotels[i].id] += sum;
	}

	int64_t mn = 0x7fffffffffffffffLL;
	int ans = -1;
	for (int i=0; i<h; ++i) {
		if (dist[i] < mn) {
			mn = dist[i];
			ans = i;
		}
	}
	printf("%d\n", ans+1);

	return 0;
}
