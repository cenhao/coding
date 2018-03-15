#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000
#define LC(x) (x << 1)
#define RC(x) ((x<<1)+1)
#define LE(x) ((nodes[x].l+nodes[x].r)>>1)

struct STN { int l, r, v; } nodes[MAXN*4+1];
struct Island { int p, h; } ild[MAXN+1];
struct PMap { int p, id; } pmap[MAXN+1];
bool drowned[MAXN+1];

void build(int cur, int l, int r) {
	nodes[cur] = { l, r, -1 };
	if (l == r) { return; }
	int le = LE(cur);
	build(LC(cur), l, le);
	build(RC(cur), le+1, r);
}

void update(int cur, int p, int v) {
	if (nodes[cur].l == p && nodes[cur].r == p) {
		nodes[cur].v = v;
		return;
	}

	int lc = LC(cur), rc = RC(cur), le = LE(cur);
	if (p <= le) {
		update(lc, p, v);
	} else {
		update(rc, p, v);
	}
	nodes[cur].v = max(nodes[lc].v, nodes[rc].v);
}

int query(int cur, int l, int r, int tar) {
	if (l > r || tar >= nodes[cur].v) { return -1; }
	if (nodes[cur].l == nodes[cur].r) { return l; }

	int lc = LC(cur), rc = RC(cur), le = LE(cur);
	if (r <= le) {
		return query(lc, l, r, tar);
	} else if (l > le) {
		return query(rc, l, r, tar);
	}

	int tmp = query(lc, l, le, tar);
	return tmp >= 0 ? tmp : query(rc, le+1, r, tar);
}

int find(int x, int n) {
	int l=0, r=n-1;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (pmap[m].p >= x) {
			r = m-1;
		} else {
			l = m+1;
		}
	}
	return l;
}

int main() {
	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d%d", &ild[i].p, &ild[i].h);
		pmap[i-1] = { ild[i].p, i };
	}

	sort(pmap, pmap+n, [](const PMap &p1, const PMap &p2) {
		return p1.p < p2.p;
	});
	build(1, 0, n-1);

	for (int i=1; i<=n; ++i) {
		int x = find(ild[i].p, n);
		update(1, x, ild[i].h);
	}

	memset(drowned, false, sizeof(drowned));
	int q; scanf("%d", &q);

	for (int i=0; i<q; ++i) {
		char cmd[2]; int v; scanf("%s%d", cmd, &v);
		if (cmd[0] == 'd') {
			int x = find(v, n);
			if (v == pmap[x].p) {
				drowned[pmap[x].id] = true;
				update(1, x, -1);
			}
		} else {
			if (drowned[v]) {
				printf("DROWNED\n");
			} else {
				int x = find(ild[v].p, n);
				int idx = query(1, x+1, n-1, ild[v].h);
				if (idx < 0) {
					printf("IMPOSSIBLE\n");
				} else {
					printf("%d\n", pmap[idx].p);
				}
			}
		}
	}

	return 0;
}
