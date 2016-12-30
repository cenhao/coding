#include <algorithm>
#include <cstdio>
using namespace std;

#define MAXN 100000

struct Interval {
	int l, r;
} itv[MAXN];

int main() {
	int n, x, y; scanf("%d %d %d", &n, &x, &y);
	int cnt = 0;
	for (int i=0; i<n; ++i) {
		scanf("%d %d", &itv[cnt].l, &itv[cnt].r);
		if (itv[cnt].l > y || itv[cnt].r < x) { continue; }
		itv[cnt].l = max(x, itv[cnt].l);
		itv[cnt].r = min(y, itv[cnt].r);
		++cnt;
	}

	sort(itv, itv+cnt, [](const Interval& i1, const Interval& i2) {
		return (i1.l == i2.l) ? i1.r < i2.r : i1.l < i2.l;
	});

	int last = x;
	int mx = x;
	int ret = (cnt > 0) ? 0 : -1;
	for (int i=0; i<cnt; ++i) {
		if (itv[i].l <= last) {
			mx = max(mx, itv[i].r);
		} else if (mx == last) {
			ret = -1;
			break;
		} else {
			last = mx;
			++ret;
			--i;
		}
	}

	printf("%d\n", ret);
	return 0;
}
