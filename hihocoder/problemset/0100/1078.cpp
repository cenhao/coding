#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 100000

struct STN {
	bool all;
	int sum;
	int l, r;
	int lc, rc;
} nodes[4*MAXN];
int nfirst;

int build(int l, int r) {
	int cur = nfirst++;
	nodes[cur].all = false;
	nodes[cur].l = l; nodes[cur].r = r;
	nodes[cur].lc = nodes[cur].rc = -1;

	if (l != r) {
		int le = (l + r) >> 1;
		nodes[cur].lc = build(l, le);
		nodes[cur].rc = build(le+1, r);
	}

	return cur;
}

void update(int cur, int l, int r, int v) {
	if (nodes[cur].l == l && nodes[cur].r == r) {
		nodes[cur].all = true;
		nodes[cur].sum = v * (r - l + 1);
		return;
	}

	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	if (nodes[cur].all) {
		nodes[cur].all = false;
		int ov = nodes[cur].sum / (nodes[cur].r-nodes[cur].l+1);
		update(nodes[cur].lc, nodes[cur].l, le, ov);
		update(nodes[cur].rc, le+1, nodes[cur].r, ov);
	}

	if (r <= le) {
		update(nodes[cur].lc, l, r, v);
	} else if (l > le) {
		update(nodes[cur].rc, l, r, v);
	} else {
		update(nodes[cur].lc, l, le, v);
		update(nodes[cur].rc, le+1, r, v);
	}

	nodes[cur].sum = nodes[nodes[cur].lc].sum + nodes[nodes[cur].rc].sum;
}

int query(int cur, int l, int r) {
	if (nodes[cur].all) {
		return nodes[cur].sum / (nodes[cur].r-nodes[cur].l+1) * (r-l+1);
	} else if (nodes[cur].l == l && nodes[cur].r == r) {
		return nodes[cur].sum;
	}

	int le = (nodes[cur].l + nodes[cur].r) >> 1;

	if (r <= le) {
		return query(nodes[cur].lc, l, r);
	} else if (l > le) {
		return query(nodes[cur].rc, l, r);
	} else {
		return query(nodes[cur].lc, l, le) +
			query(nodes[cur].rc, le+1, r);
	}
}

int main() {
	int n; scanf("%d", &n);

	nfirst = 0;
	build(1, n);

	for (int i=1; i<=n; ++i) {
		int v; scanf("%d", &v);
		update(0, i, i, v);
	}

	int q; scanf("%d", &q);
	int t, l, r;
	for (int i=0; i<q; ++i) {
		scanf("%d %d %d", &t, &l, &r);
		if (t == 0) {
			printf("%d\n", query(0, l, r));
		} else {
			int v; scanf("%d", &v);
			update(0, l, r, v);
		}
	}

	return 0;
}
