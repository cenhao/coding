#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define LC(x) (x << 1)
#define RC(x) ((x<<1) + 1)

struct Card {
	int v, p, f;
} cards[MAXN];

struct STN {
	int l, r;
	int mx;
} nodes[MAXN*4+1];

void build(int cur, int l, int r) {
	nodes[cur] = { l, r, -1 };
	if (l == r) { return; }

	int le = (l + r) >> 1;
	int lc = LC(cur), rc = RC(cur);
	build(lc, l, le);
	build(rc, le+1, r);
}

void update(int cur, int p, int v) {
	if (nodes[cur].l == p && nodes[cur].r == p) {
		nodes[cur].mx = v;
		return;
	}

	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	int lc = LC(cur), rc = RC(cur);
	if (p <= le) {
		update(lc, p, v);
	} else {
		update(rc, p, v);
	}
	nodes[cur].mx = max(nodes[lc].mx, nodes[rc].mx);
}

int query(int cur, int l, int r) {
	if (l == nodes[cur].l && r == nodes[cur].r) {
		return nodes[cur].mx;
	}

	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	int lc = LC(cur), rc = RC(cur);

	if (r <= le) {
		return query(lc, l, r);
	} else if (l > le) {
		return query(rc, l, r);
	}

	return max(query(lc, l, le), query(rc, le+1, r));
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &cards[i].v);
		cards[i].p = i;
	}

	sort(cards, cards+n, [](const Card &c1, const Card &c2) {
		return (c1.v == c2.v) ? (c1.p < c2.p) : (c1.v < c2.v);
	});

	build(1, 0, n-1);

	int lastv = 0, lastp = 0;
	int64_t ans = n;
	for (int i=0; i<n; ++i) {
		if (cards[i].v != lastv) {
			for (int j=lastp; j<i; ++j) { update(1, cards[j].p, cards[j].f); }
			lastv = cards[i].v;
			lastp = i;
		}

		cards[i].f = max(query(1, 0, cards[i].p), query(1, cards[i].p, n-1)+1);
		ans += cards[i].f;
	}

	printf("%" PRId64 "\n", ans);
	return 0;
}
