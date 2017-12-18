#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define LC(x) (x << 1)
#define RC(x) ((x<<1) + 1)

struct STN {
	int l, r, h, all;
} nodes[MAXN*4+10];

void build(int cur, int l, int r) {
	nodes[cur] = { l, r, 0, 1 };
	if (l == r) { return; }
	int le = (l + r) >> 1;
	build(LC(cur), l, le);
	build(RC(cur), le+1, r);
}

void update(int cur, int l, int r, int v) {
	if (l == nodes[cur].l && r == nodes[cur].r) {
		nodes[cur].h = v;
		nodes[cur].all = 1;
		return;
	}

	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	int lc = LC(cur), rc = RC(cur);

	if (nodes[cur].all == 1) {
		nodes[lc].h = nodes[rc].h = nodes[cur].h;
		nodes[lc].all = nodes[rc].all = 1;
		nodes[cur].all = 0;
	}

	if (r <= le) {
		update(lc, l, r, v);
	} else if (l > le) {
		update(rc, l, r, v);
	} else {
		update(lc, l, le, v);
		update(rc, le+1, r, v);
	}

	nodes[cur].h = max(nodes[lc].h, nodes[rc].h);
}

int query(int cur, int l, int r) {
	if ((l == nodes[cur].l && r == nodes[cur].r) || nodes[cur].all == 1) {
		return nodes[cur].h;
	}

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

int main() {
	int n; scanf("%d", &n);
	build(1, 1, MAXN);
	for (int i=0; i<n; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		int h = query(1, l, r);
		printf("%d\n", h+1);
		update(1, l, r, h+1);
	}

	return 0;
}
