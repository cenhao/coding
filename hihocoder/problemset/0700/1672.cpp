/*
// segment tree solution
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXR 1000000
#define LE(cur) ((nodes[cur].l + nodes[cur].r)>>1)
#define LC(cur) (cur << 1)
#define RC(cur) ((cur<<1) + 1)
struct Interval { int l, r; } itvs[MAXN];
struct STN { int l, r, cnt; } nodes[MAXR*4];

void build(int cur, int l, int r) {
	nodes[cur] = { l, r, 0 };
	if (l == r) { return; }
	int le = LE(cur), lc = LC(cur), rc = RC(cur);
	build(lc, l, le);
	build(rc, le+1, r);
}

void inc(int cur, int p) {
	++nodes[cur].cnt;
	if (nodes[cur].l == nodes[cur].r && nodes[cur].l == p) {
		return;
	}

	int le = LE(cur), lc = LC(cur), rc = RC(cur);
	if (p <= le) {
		inc(lc, p);
	} else {
		inc(rc, p);
	}
}

int query(int cur, int l, int r) {
	if (nodes[cur].l == l && nodes[cur].r == r) {
		return nodes[cur].cnt;
	}

	int le = LE(cur), lc = LC(cur), rc = RC(cur);
	if (r <= le) {
		return query(lc, l, r);
	} else if (l > le) {
		return query(rc, l, r);
	}
	return query(lc, l, le) + query(rc, le+1, r);
}

int main() {
	int n; scanf("%d", &n);
	int mn = 0x7fffffff, mx = -1;
	for (int i=0; i<n; ++i) {
		scanf("%d%d", &itvs[i].l, &itvs[i].r);
		mn = min(mn, itvs[i].l);
		mx = max(mx, itvs[i].r);
	}

	sort(itvs, itvs+n, [](const Interval &i1, const Interval &i2) {
		return i1.r < i2.r;
	});
	build(1, mn, mx);

	for (int i=0; i<n; ++i) {
		int cnt = query(1, itvs[i].l, itvs[i].r);
		for (int j=0, need=2-cnt; j<need; ++j) { inc(1, itvs[i].r-j); }
	}

	printf("%d\n", query(1, mn, mx));
	return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
struct Interval { int l, r; } itvs[MAXN];
int st[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d%d", &itvs[i].l, &itvs[i].r); }
	sort(itvs, itvs+n, [](const Interval& i1, const Interval &i2) {
		return (i1.l == i2.l) ? i1.r > i2.r : i1.l < i2.l;
	});

	int r = 0;
	for (int i=0; i<n; ++i) {
		while (r != 0 && itvs[st[r-1]].r >= itvs[i].r) { --r; }
		if (r != 0) {
			itvs[st[r-1]+1] = itvs[i];
			st[r] = st[r-1]+1;
			++r;
		} else {
			itvs[0] = itvs[i];
			st[r++] = 0;
		}
	}

	set<int> hs;
	for (int i=0; i<r; ++i) {
		auto it = hs.lower_bound(itvs[i].l);

		if (it == hs.end()) {
			hs.insert(itvs[i].r-1);
			hs.insert(itvs[i].r);
		} else if (++it == hs.end()) {
			hs.insert(itvs[i].r);
		}
	}

	printf("%d\n", (int) hs.size());
	return 0;
}
