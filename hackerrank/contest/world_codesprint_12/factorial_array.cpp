#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MOD 1000000000
#define LC(x) (x << 1)
#define RC(x) ((x<<1) + 1)

int64_t fact[40];

struct STN {
	int l, r, inc;
	int cnt[40];
} nodes[MAXN*4];

void init() {
	int64_t v = 1;
	for (int i=1; i<40; ++i) {
		v = (v * i) % MOD;
		fact[i] = v;
	}
}

void build(int cur, int l, int r) {
	nodes[cur].l = l; nodes[cur].r = r; nodes[cur].inc = 0;
	memset(nodes[cur].cnt, 0, sizeof(nodes[cur].cnt));

	if (l == r) { return; }

	int le = (l + r) >> 1;
	build(LC(cur), l, le);
	build(RC(cur), le+1, r);
}

void add_first_to_second(int f, int s) { // first, second
	int inc = nodes[f].inc;
	for (int i=1; i+inc<40; ++i) { nodes[s].cnt[i+inc] += nodes[f].cnt[i]; }
}

void increase(int cur, int l, int r) {
	if (nodes[cur].l == l && nodes[cur].r == r) {
		++nodes[cur].inc;
		return;
	}

	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	int lc = LC(cur), rc = RC(cur);
	if (r <= le) {
		increase(lc, l, r);
	} else if (l > le) {
		increase(rc, l, r);
	} else {
		increase(lc, l, le);
		increase(rc, le+1, r);
	}
	memset(nodes[cur].cnt, 0, sizeof(nodes[cur].cnt));
	add_first_to_second(lc, cur);
	add_first_to_second(rc, cur);
}

void update(int cur, int p, int v) {
	if (nodes[cur].l == p && nodes[cur].r == p) {
		nodes[cur].inc = 0;
		memset(nodes[cur].cnt, 0, sizeof(nodes[cur].cnt));
		if (v < 40) { nodes[cur].cnt[v] = 1; }
		return;
	}

	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	int lc = LC(cur), rc = RC(cur);
	if (nodes[cur].inc > 0) {
		nodes[lc].inc += nodes[cur].inc;
		nodes[rc].inc += nodes[cur].inc;
		nodes[cur].inc = 0;
	}

	update(p<=le ? lc : rc, p, v);
	memset(nodes[cur].cnt, 0, sizeof(nodes[cur].cnt));
	add_first_to_second(lc, cur);
	add_first_to_second(rc, cur);
}

void query(int cur, int l, int r, int inc, int *cnt) {
	inc += nodes[cur].inc;
	if (l == nodes[cur].l && r == nodes[cur].r) {
		for (int i=0; i+inc<40; ++i) {
			cnt[i+inc] += nodes[cur].cnt[i];
		}
		return;
	}

	int lc = LC(cur), rc = RC(cur);
	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	if (r <= le) {
		query(lc, l, r, inc, cnt);
	} else if (l > le) {
		query(rc, l, r, inc, cnt);
	} else {
		query(lc, l, le, inc, cnt);
		query(rc, le+1, r, inc, cnt);
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	init();
	build(1, 1, n);
	for (int i=1; i<=n; ++i) {
		int v; scanf("%d", &v);
		if (v < 40) { update(1, i, v); }
	}

	for (int i=0; i<m; ++i) {
		int cmd; scanf("%d", &cmd);
		if (cmd == 1) {
			int l, r; scanf("%d%d", &l, &r);
			increase(1, l, r);
		} else if (cmd == 2) {
			int l, r; scanf("%d%d", &l, &r);
			int cnt[40]; memset(cnt, 0, sizeof(cnt));
			query(1, l, r, 0, cnt);
			int64_t ans = 0;
			for (int i=1; i<40; ++i) {
				ans = (ans + cnt[i] * fact[i]) % MOD;
			}

			printf("%" PRId64 "\n", ans);
		} else {
			int p, v; scanf("%d%d", &p, &v);
			update(1, p, v);
		}
	}

	return 0;
}
