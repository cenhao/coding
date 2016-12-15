#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 50000
#define RANGE 26
#define CAL_START(l, r, st, rn) \
	(((((r-l)%RANGE)*rn)%RANGE+st)%RANGE)

char initstr[MAXN+1];

struct STN {
	int all;
	int inc;
	int stepstart, steprange;
	int l, r;
	int lc, rc;
} nodes[MAXN << 2];
int nfirst = 0;

int build(int l, int r) {
	int cur = nfirst++;
	nodes[cur].all = -1;
	nodes[cur].inc = nodes[cur].stepstart = nodes[cur].steprange = 0;
	nodes[cur].l = l; nodes[cur].r = r;

	if (l == r) {
		nodes[cur].lc = nodes[cur].rc = -1;
	} else {
		int le = (l + r) >> 1;
		nodes[cur].lc = build(l, le);
		nodes[cur].rc = build(le+1, r);
	}

	return cur;
}

void update(int cur, int l, int r, int op, int v, int rn) {
	if (l == nodes[cur].l && r == nodes[cur].r) {
		if (l == r) {
			nodes[cur].all = (op == 1) ? v : (nodes[cur].all + v) % RANGE;
		} else {
			int le = (nodes[cur].l + nodes[cur].r) >> 1;
			if (nodes[cur].all >=0 && op == 4) {
				update(nodes[cur].lc, nodes[cur].l, le, 1, nodes[cur].all, 0);
				update(nodes[cur].rc, le+1, nodes[cur].r, 1, nodes[cur].all, 0);
				nodes[cur].all = -1;
			}

			if (op == 1) {
				nodes[cur].all = v;
				nodes[cur].inc = nodes[cur].stepstart = nodes[cur].steprange = 0;
			} else if (op == 2) {
				if (nodes[cur].all >= 0) {
					nodes[cur].all = (nodes[cur].all + v) % RANGE;
				} else {
					nodes[cur].inc = (nodes[cur].inc + v) % RANGE;
				}
			} else {
				nodes[cur].stepstart = (nodes[cur].stepstart + v) % RANGE;
				nodes[cur].steprange = (nodes[cur].steprange + rn) % RANGE;

				if (nodes[cur].steprange == 0) {
					nodes[cur].inc = (nodes[cur].inc + nodes[cur].stepstart) % RANGE;
					nodes[cur].stepstart = nodes[cur].steprange = 0;
				}
			}
		}

		return ;
	}

	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	if (nodes[cur].all >= 0) {
		update(nodes[cur].lc, nodes[cur].l, le, 1, nodes[cur].all, 0);
		update(nodes[cur].rc, le+1, nodes[cur].r, 1, nodes[cur].all, 0);
		nodes[cur].all = -1;
	} else if (op == 1) { // not all && set all
		if (nodes[cur].inc > 0) {
			update(nodes[cur].lc, nodes[cur].l, le, 2, nodes[cur].inc, 0);
			update(nodes[cur].rc, le+1, nodes[cur].r, 2, nodes[cur].inc, 0);
		}
		if (nodes[cur].stepstart > 0 || nodes[cur].steprange > 0) {
			update(nodes[cur].lc, nodes[cur].l, le, 4, nodes[cur].stepstart, nodes[cur].steprange);
			update(nodes[cur].rc, le+1, nodes[cur].r, 4,
				   CAL_START(nodes[cur].l, le+1, nodes[cur].stepstart, nodes[cur].steprange),
				   nodes[cur].steprange);
		}

		nodes[cur].inc = nodes[cur].stepstart = nodes[cur].steprange = 0;
	}

	if (r <= le) {
		update(nodes[cur].lc, l, r, op, v, rn);
	} else if (l > le) {
		update(nodes[cur].rc, l, r, op, v, rn);
	} else {
		update(nodes[cur].lc, l, le, op, v, rn);
		update(nodes[cur].rc, le+1, r, op, CAL_START(l, le+1, v, rn), rn);
	}
}

int query(int cur, int pos) {
	if (nodes[cur].all >= 0) {
		return nodes[cur].all;
	}

	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	int ret = (pos <= le) ? query(nodes[cur].lc, pos) : query(nodes[cur].rc, pos);
	ret = (nodes[cur].inc + ret) % RANGE;
	ret = (CAL_START(nodes[cur].l, pos, nodes[cur].stepstart, nodes[cur].steprange)+ret) % RANGE;
	return ret;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	scanf("%s", initstr);

	build(0, n-1);
	for (int i=0; i<n; ++i) { update(0, i, i, 1, initstr[i]-'A', 0); }

	char tmp[5];
	int offset = 0, op;
	for (int i=0; i<m; ++i) {
		scanf("%s %d", tmp, &op);
		if (op == 1) {
			int l, r; char v; scanf("%d %d %c", &l, &r, &v);
			l = (l+offset-1)%n; r = (r+offset-1)%n; v -= 'A';
			if (l > r) {
				update(0, l, n-1, 1, (int)v, 0);
				update(0, 0, r, 1, (int)v, 0);
			} else {
				update(0, l, r, 1, (int)v, 0);
			}
		} else if (op == 2) {
			int l, r, v; scanf("%d %d %d", &l, &r, &v);
			l = (l+offset-1)%n; r = (r+offset-1)%n;
			if (l > r) {
				update(0, l, n-1, 2, v, 0);
				update(0, 0, r, 2, v, 0);
			} else {
				update(0, l, r, 2, v, 0);
			}
		} else if (op == 3) {
			int v; scanf("%d", &v);
			offset = (offset + v) % n;
		} else {
			int l, r; scanf("%d %d", &l, &r);
			l = (l+offset-1)%n; r = (r+offset-1)%n;
			if (l > r) {
				update(0, l, n-1, 4, 1, 1);
				update(0, 0, r, 4, CAL_START(l, n, 1, 1), 1);
			} else {
				update(0, l, r, 4, 1, 1);
			}
		}
	}

	for (int i=0; i<n; ++i) { printf("%c", query(0, (i+offset)%n) + 'A'); }
	printf("\n");

	return 0;
}


