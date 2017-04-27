#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000
#define INF 0x7fffffffffff0000

struct City {
	int x, y, z;
	int point;
	int id;
}c[MAXN+1];

int64_t dp[MAXN+1];
int idx[MAXN+1];
int x, y, mxy;

struct STN {
	int l, r;
	int64_t val;
} nodes[MAXN*4+1];

#define LC(x) (x << 1)
#define RC(x) ((x << 1) + 1)

void build(int cur, int l, int r) {
	nodes[cur].l = l;
	nodes[cur].r = r;
	nodes[cur].val = -INF;
	if (l != r) {
		int le = (l + r) >> 1;
		build(LC(cur), l, le);
		build(RC(cur), le+1, r);
	}
}

void update(int cur, int p, int64_t val) {
	if (nodes[cur].l == p && nodes[cur].r == p) {
		nodes[cur].val = val;
		return;
	}

	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	int lc = LC(cur), rc = RC(cur);
	if (p <= le) {
		update(lc, p, val);
	} else {
		update(rc, p, val);
	}

	nodes[cur].val = max(nodes[lc].val, nodes[rc].val);
}

int64_t query(int cur, int l, int r) {
	if (nodes[cur].l == l && nodes[cur].r == r) { return nodes[cur].val; }
	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	int lc = LC(cur), rc = RC(cur);
	if (r <= le) {
		return query(lc, l, r);
	} else if (l > le) {
		return query(rc, l, r);
	} else {
		return max(query(lc, l, le), query(rc, le+1, r));
	}
}

void devide(int l, int r) {
	if (l == r) { return; }
	int m = (l+r) / 2;
	devide(l, m);
	for (int i=l; i<=r; ++i) { idx[i] = i; }
	sort(idx+l, idx+m+1, [](const int &i1, const int &i2) -> bool {
		return ::c[i1].x < ::c[i2].x;
	});
	sort(idx+m+1, idx+r+1, [](const int &i1, const int &i2) -> bool {
		return ::c[i1].x < ::c[i2].x;
	});

	int ls = l, rs = l;
	for (int i=m+1; i<=r; ++i) {
		while (rs <= m && (c[idx[rs]].x <= c[idx[i]].x+x)) {
			update(1, c[idx[rs]].y, dp[c[idx[rs]].id]);
			++rs;
		}
		while (ls <= m && (c[idx[ls]].x < c[idx[i]].x-x)) {
			update(1, c[idx[ls]].y, -INF);
			++ls;
		}

		int ylow = max(0, c[idx[i]].y - y), yup = min(mxy, c[idx[i]].y + y);
		int64_t v = query(1, ylow, yup);
		if (v > -INF && v+c[idx[i]].point > dp[c[idx[i]].id]) {
			dp[c[idx[i]].id] = v + c[idx[i]].point;
		}
	}

	for (int i=ls; i<rs; ++i) { update(1, c[idx[i]].y, -INF); }
	devide(m+1, r);
}

int main() {
	int n; scanf("%d %d %d", &n, &x, &y);
	mxy = -1;
	for (int i=0; i<n; ++i) {
		scanf("%d %d %d %d", &c[i].x, &c[i].y, &c[i].z, &c[i].point);
		c[i].id = i;
		dp[i] = c[i].point;
		mxy = max(mxy, c[i].y);
	}

	sort(c, c+n, [](const City &c1, const City &c2) {
		return c1.z < c2.z;
	});

	build(1, 0, mxy);
	devide(0, n-1);

	int64_t mx = -INF;
	for (int i=0; i<n; ++i) {
		mx = max(mx, dp[i]);
	}

	printf("%" PRId64 "\n", mx);
	return 0;
}
