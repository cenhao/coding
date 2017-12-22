#include <bits/stdc++.h>
using namespace std;

#define MAXN 50000
#define LC(x) (x << 1)
#define RC(x) ((x<<1) + 1)

int ans[MAXN+1];
struct STN {
	bool all;
	int l, r, mx, inc;
} nodes[2][MAXN*4+1];

void build(int cur, int l, int r) {
	nodes[0][cur].all = nodes[1][cur].all = true;
	nodes[0][cur].l = nodes[1][cur].l = l;
	nodes[0][cur].r = nodes[1][cur].r = r;
	nodes[0][cur].mx = nodes[1][cur].mx = 0;
	nodes[0][cur].inc = nodes[1][cur].inc = 0;

	if (l == r) { return; }
	int le = (l + r) >> 1;
	build(LC(cur), l, le);
	build(RC(cur), le+1, r);
}

void push_down(int c, int cur, int lc, int rc) {
	nodes[c][lc].all = nodes[c][rc].all = true;
	nodes[c][lc].mx = nodes[c][rc].mx = nodes[c][cur].mx + nodes[c][cur].inc;
	nodes[c][lc].inc = nodes[c][rc].inc = 0;
	nodes[c][cur].inc = 0;
	nodes[c][cur].all = false;
}

int increase(int c, int cur, int l) {
	if (nodes[c][cur].l == l) {
		++nodes[c][cur].inc;
		return nodes[c][cur].mx + nodes[c][cur].inc;
	}

	int le = (nodes[c][cur].l + nodes[c][cur].r) >> 1;
	int lc = LC(cur), rc = RC(cur);
	if (nodes[c][cur].all) { push_down(c, cur, lc, rc); }

	int lv, rv;
	if (l > le) {
		lv = nodes[c][lc].mx + nodes[c][lc].inc;
		rv = increase(c, rc, l);
	} else {
		lv = increase(c, lc, l);
		rv = increase(c, rc, le+1);
	}

	nodes[c][cur].mx = max(lv, rv);
	return nodes[c][cur].mx + nodes[c][cur].inc;
}

int update(int c, int cur, int l, int v) {
	if (nodes[c][cur].l == l) {
		if (v >= nodes[c][cur].mx+nodes[c][cur].inc) {
			nodes[c][cur].mx = v;
			nodes[c][cur].inc = 0;
			nodes[c][cur].all = true;
			return nodes[c][cur].mx;
		}
		if (nodes[c][cur].all) { return nodes[c][cur].mx+nodes[c][cur].inc; }
	}

	int le = (nodes[c][cur].l + nodes[c][cur].r) >> 1;
	int lc = LC(cur), rc = RC(cur);

	if (nodes[c][cur].all) {
		if (v <= nodes[c][cur].mx + nodes[c][cur].inc) {
			return nodes[c][cur].mx + nodes[c][cur].inc;
		}
		push_down(c, cur, lc, rc);
	}

	v -= nodes[c][cur].inc;
	if (v > 0) {
		int lv, rv;
		if (l > le) {
			lv = nodes[c][lc].mx + nodes[c][lc].inc;
			rv = update(c, rc, l, v);
		} else {
			lv = update(c, lc, l, v);
			rv = update(c, rc, le+1, v);
		}

		nodes[c][cur].mx = max(lv, rv);
	}

	return nodes[c][cur].mx + nodes[c][cur].inc;
}

int query(int c, int cur, int l, int r) {
	if ((nodes[c][cur].l == l && nodes[c][cur].r == r) || nodes[c][cur].all) {
		return nodes[c][cur].mx + nodes[c][cur].inc;
	}

	int le = (nodes[c][cur].l + nodes[c][cur].r) >> 1;
	int lc = LC(cur), rc = RC(cur);

	if (r <= le) {
		return nodes[c][cur].inc + query(c, lc, l, r);
	} else if (l > le) {
		return nodes[c][cur].inc + query(c, rc, l, r);
	}

	return nodes[c][cur].inc + max(query(c, lc, l, le), query(c, rc, le+1, r));
}

struct Animal { int t, s, e; } animals[MAXN];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d%d", &m, &n);
		for (int i=0; i<n; ++i) {
			char tmp[4]; scanf("%s", tmp);
			animals[i].t = (tmp[0] == 'E' || tmp[0] == 'C') ? 0 : 1;
		}
		for (int i=0; i<n; ++i) { scanf("%d", &animals[i].s); }
		for (int i=0; i<n; ++i) { scanf("%d", &animals[i].e); }

		sort(animals, animals+n, [](const Animal &a1, const Animal &a2) {
			return a1.s < a2.s;
		});

		build(1, 1, m);
		for (int i=0; i<n; ++i) {
			if (animals[i].e < animals[i].s) { continue; }
			increase(animals[i].t, 1, animals[i].e);
			int mx = query(animals[i].t^1, 1, 1, animals[i].s);
			update(animals[i].t, 1, animals[i].e, mx+1);
		}

		int last = 1;
		memset(ans, -1, sizeof(ans));
		for (int i=1; i<=m; ++i) {
			int v = max(query(0, 1, 1, i), query(1, 1, 1, i));
			for (; last<=v; ++last) { ans[last] = i; }
		}

		for (int i=1; i<=n; ++i) {
			printf("%d%c", ans[i], (i == n) ? '\n' : ' ');
		}
	}

	return 0;
}
