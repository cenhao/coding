#include <bits/stdc++.h>
using namespace std;

#define MAXN 500000
#define LC(x) (x << 1)
#define RC(x) ((x << 1) + 1)
struct Princess { int b, i, r; } p[MAXN];

struct STN {
	int l, r, mx;
} nodes[MAXN*4];

void build(int cur, int l, int r) {
	nodes[cur] = { l, r, -1 };
	if (l == r) { return; }
	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	build(LC(cur), l, le);
	build(RC(cur), le+1, r);
}

int update(int cur, int r, int v) {
	if (nodes[cur].l == r && nodes[cur].r == r) {
		return nodes[cur].mx = max(nodes[cur].mx, v);
	}

	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	int lc = LC(cur), rc = RC(cur);

	nodes[cur].mx = max(nodes[cur].mx, (r<=le) ? update(lc, r, v):update(rc, r, v));

	return nodes[cur].mx;
}

int query(int cur, int l) {
	if (nodes[cur].l == l) { return nodes[cur].mx; }
	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	int lc = LC(cur), rc = RC(cur);
	int v = query(rc, max(le+1, l));
	if (l <= le) { v = max(v, query(lc, l)); }
	return v;
}

int r[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &p[i].b); }
	for (int i=0; i<n; ++i) { scanf("%d", &p[i].i); }
	for (int i=0; i<n; ++i) { scanf("%d", &p[i].r); }
	for (int i=0; i<n; ++i) { r[i] = p[i].r; }

	sort(r, r+n);
	int pos = 0;
	for (int i=1; i<n; ++i) { if (r[i] != r[pos]) { r[++pos] = r[i]; } }
	for (int i=0; i<n; ++i) {
		p[i].r = distance(r, lower_bound(r, r+pos+1, p[i].r));
	}

	sort(p, p+n, [](const Princess &p1, const Princess &p2) {
		return p1.b != p2.b ? p1.b > p2.b : (p1.r != p2.r ? p1.r > p2.r : p1.i > p2.i);
	});

	build(1, 0, pos+1);
	int ans = 0;
	for (int i=0, last=0; i<n; ++i) {
		if (p[i].b != p[last].b) {
			while (last != i) {
				update(1, p[last].r, p[last].i);
				++last;
			}
		}

		if (query(1, p[i].r+1) > p[i].i) { ++ans; }
	}

	printf("%d\n", ans);
	return 0;
}
