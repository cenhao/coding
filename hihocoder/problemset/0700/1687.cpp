#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
struct Point {
	int x, y, idx;
} p[MAXN];

int64_t cross_prod(int x1, int y1, int x2, int y2, int x3, int y3) {
	int64_t ax = x2 - x1, ay = y2 - y1;
	int64_t bx = x3 - x2, by = y3 - y2;
	return ax*by - ay*bx;
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d%d", &p[i].x, &p[i].y);
		p[i].idx = i + 1;
	}

	if (n <= 2) {
		printf("1 2\n");
		return 0;
	}

	sort(p, p+n, [](const Point &p1, const Point &p2) {
		return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
	});

	int pick = 1;
	for (int i=2; i<n; ++i) {
		if (cross_prod(p[0].x, p[0].y, p[pick].x, p[pick].y, p[i].x, p[i].y) < 0) {
			pick = i;
		}
	}

	printf("%d %d\n", p[0].idx, p[pick].idx);

	return 0;
}
