#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 50
#define LCH(x) (x << 1)
#define RCH(x) ((x<<1) + 1)

struct STNode {
	int l, r;
	int cnt;
} stn[MAXN*2 * 4];

void build(int cur, int l, int r) {
	stn[cur].l = l; stn[cur].r = r; stn[cur].cnt = 0;
	if (l == r) { return; }
	int lc = LCH(cur), rc = RCH(cur);
	int le = (l + r) >> 1;
	build(lc, l, le);
	build(rc, le+1, r);
}

void update(int cur, int v) {
	++stn[cur].cnt;
	if (stn[cur].l == v && stn[cur].r == v) { return; }
	int le = (stn[cur].l + stn[cur].r) >> 1;
	int child = (v <= le) ? LCH(cur) : RCH(cur);
	update(child, v);
}

int query(int cur, int l, int r) {
	if (l == stn[cur].l && r == stn[cur].r) { return stn[cur].cnt; }
	int lc = LCH(cur), rc = RCH(cur);
	int le = (stn[cur].l + stn[cur].r) >> 1;
	if (r <= le) {
		return query(lc, l, r);
	} else if (l > le) {
		return query(rc, l, r);
	} else {
		return query(lc, l, le) + query(rc, le+1, r);
	}
}

struct Zombie {
	int x, y;
} zombies[MAXN];

int xs[MAXN], ys[MAXN];
int movx[MAXN], rmovx[MAXN*2];

inline bool within(int x, int y, int x0, int y0, int r) {
	return x >= x0 && x <= x0+r && y >= y0 && y <= y0+r;
}

int find(int *arr, int cnt, int v) {
	int l = 0, r = cnt-1, m;
	while (l <= r) {
		m = (l + r) >> 1;
		if (arr[m] < v) {
			l = m + 1;
		} else if (arr[m] > v) {
			r = m - 1;
		} else {
			return m;
		}
	}

	return -1;
}

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int n, R; scanf("%d %d", &n, &R);
		for (int i=0; i<n; ++i) {
			scanf("%d %d", &zombies[i].x, &zombies[i].y);
			xs[i] = zombies[i].x; ys[i] = zombies[i].y;
		}

		sort(zombies, zombies+n, [](const Zombie& z1, const Zombie& z2) {
			return z1.y == z2.y ? (z1.x < z2.x) : (z1.y > z2.y);
		});
		sort(xs, xs+n);
		sort(ys, ys+n);

		int xcnt = 0, lastx = -1;
		for (int i=0; i<n; ++i) {
			if (xs[i] == lastx) { continue; }
			xs[xcnt++] = lastx = xs[i];
		}

		int ycnt = 0, lasty = -1;
		for (int i=0; i<n; ++i) {
			if (ys[i] == lasty) { continue; }
			ys[ycnt++] = lasty = ys[i];
		}

		int mx = 0;
		for (int i=0; i<xcnt; ++i) {
			for (int j=0; j<ycnt; ++j) {
				int dcnt = 0, x = xs[i], y = ys[j];
				for (int k=0; k<n; ++k) {
					if (within(zombies[k].x, zombies[k].y, x, y, R)) { ++dcnt; }
				}
				int start = n-1, end = n-1;
				for (int k=0; k<ycnt; ++k) {
					while (start >= 0 && zombies[start].y <= ys[k]+R) { --start; }
					while (end< n && zombies[end].y < ys[k]) { --end; }

					int cnt = 0;
					for (int k1=start+1; k1<=end; ++k1) {
						if (within(zombies[k1].x, zombies[k1].y, x, y, R)) { continue; }
						movx[cnt] = rmovx[cnt<<1] = zombies[k1].x;
						rmovx[(cnt<<1)+1] = zombies[k1].x + R;
						++cnt;
					}

					if (cnt == 0) {
						mx = max(dcnt, mx);
						continue;
					}
					sort(rmovx, rmovx+(2*cnt));
					int rcnt = 0, last = -1;
					for (int k1=0, k1end=2*cnt; k1<k1end; ++k1) {
						if (rmovx[k1] != last) { rmovx[rcnt++] = last = rmovx[k1]; }
					}

					build(1, 0, rcnt-1);
					for (int k1=0; k1<cnt; ++k1) {
						int v = find(rmovx, rcnt, movx[k1]);
						update(1, v);
					}

					last = -1;
					for (int k1=0; k1<cnt; ++k1) {
						if (movx[k1] == last) { continue; }
						last = movx[k1];
						int l = find(rmovx, rcnt, last);
						int r = find(rmovx, rcnt, last+R);
						int v = query(1, l, r);
						mx = max(mx, dcnt+v);
					}
				}
			}
		}

		printf("Case #%d: %d\n", t, mx);
	}

	return 0;
}
