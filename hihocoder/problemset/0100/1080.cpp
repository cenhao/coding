#include <stdio.h>
#include <string.h>

#define MAXN 100000

struct STN {
	int l, r;
	int lc, rc;
	int sum;
	int adjustment;
	int overwrite;
} nodes[MAXN << 2];
int nfirst;

int build(int l, int r) {
	int cur = nfirst++;
	nodes[cur].l = l; nodes[cur].r = r;
	nodes[cur].adjustment = 0;
	nodes[cur].sum = 0;
	nodes[cur].overwrite = -1;

	if (l == r) {
		nodes[cur].lc = nodes[cur].rc = -1;
	} else {
		int le = (l + r) >> 1;
		nodes[cur].lc = build(l, le);
		nodes[cur].rc = build(le+1, r);
	}

	return cur;
}

void update(int cur, int l, int r, int t, int v) {
	if (l == nodes[cur].l && r == nodes[cur].r) {
		if (t == 1) {
			nodes[cur].adjustment = 0;
			nodes[cur].overwrite = v;
		} else {
			nodes[cur].adjustment += v;
		}

		nodes[cur].sum = (nodes[cur].overwrite >= 0)
			? nodes[cur].overwrite * (r-l+1)
			: nodes[nodes[cur].lc].sum + nodes[nodes[cur].rc].sum;
		nodes[cur].sum += nodes[cur].adjustment * (r-l+1);
		return;
	}

	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	if (nodes[cur].overwrite >= 0) {
		update(nodes[cur].lc, nodes[cur].l, le, 1, nodes[cur].overwrite);
		update(nodes[cur].rc, le+1, nodes[cur].r, 1, nodes[cur].overwrite);
		nodes[cur].overwrite = -1;
	}
	if (t == 1 && nodes[cur].adjustment != 0) {
		update(nodes[cur].lc, nodes[cur].l, le, 0, nodes[cur].adjustment);
		update(nodes[cur].rc, le+1, nodes[cur].r, 0, nodes[cur].adjustment);
		nodes[cur].adjustment = 0;
	}

	if (r <= le) {
		update(nodes[cur].lc, l, r, t, v);
	} else if (l > le) {
		update(nodes[cur].rc, l, r, t, v);
	} else {
		update(nodes[cur].lc, l, le, t, v);
		update(nodes[cur].rc, le+1, r, t, v);
	}

	nodes[cur].sum = nodes[nodes[cur].lc].sum + nodes[nodes[cur].rc].sum +
		nodes[cur].adjustment * (nodes[cur].r - nodes[cur].l + 1);
}

int main() {
	nfirst = 0;
	int n, m; scanf("%d %d", &n, &m);
	build(0, n);
	for (int i=0; i<=n; ++i) {
		int v; scanf("%d", &v);
		update(0, i, i, 1, v);
	}

	for (int i=0; i<m; ++i) {
		int t, l, r, v; scanf("%d %d %d %d", &t, &l, &r, &v);
		update(0, l, r, t, v);
		printf("%d\n", nodes[0].sum);
	}

	return 0;
}
