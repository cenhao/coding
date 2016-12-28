#include <algorithm>
#include <cinttypes>
#include <cstdint>
#include <cstdio>
using namespace std;

#define MAXN 1000
#define INF 0x7fffffffffffffffLL

struct Point {
	int x, y;
} points[MAXN];

int xidx[MAXN+1];
int yv[MAXN];

class Cmp {
	public:
	bool operator ()(const Point &p1, const Point &p2) {
		return (p1.x == p2.x) ? p1.y < p2.y : p1.x < p2.x;
	}
};

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d %d", &points[i].x, &points[i].y);
	}

	sort(points, points+n, Cmp());
	int cnt = 0, last = -1;
	for (int i=0; i<n; ++i) {
		if (points[i].x != last) {
			xidx[cnt++] = i;
			last = points[i].x;
		}
	}
	xidx[cnt] = n;
	int64_t mn = INF;

	for (int i=0; i<cnt; ++i) {
		for (int j=i+1; j<cnt; ++j) {
			int si = xidx[i], ei = xidx[i+1];
			int sj = xidx[j], ej = xidx[j+1];
			int ycnt = 0, dx = points[sj].x - points[si].x;

			while (si < ei && sj < ej) {
				if (points[si].y > points[sj].y) {
					++sj;
				} else if (points[si].y < points[sj].y) {
					++si;
				} else {
					yv[ycnt++] = points[si].y;
					++si; ++sj;
				}
			}

			for (int i1=ycnt-1; i1>=1; --i1) {
				int64_t tmp = yv[i1] - yv[i1-1];
				tmp *= dx;
				mn = min(mn, tmp);
			}
		}
	}

	if (mn == INF) {
		printf("-1\n");
	} else {
		printf("%" PRId64 "\n", mn);
	}
	return 0;
}
