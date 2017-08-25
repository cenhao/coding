#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define LC(x) (x << 1)
#define RC(x) ((x<<1) + 1)

struct Edge {
	int x, y1, y2, io;
} e[MAXN*2];

int ys[MAXN*2], ycnt;

int get_y_hash(int y, int ycnt) {
	auto ptr = lower_bound(ys, ys+ycnt, y);
	return distance(ys, ptr);
}

struct STN {
	int l, r, state; /* 0 unknow, 1 full, 2 empty */
} nodes[MAXN*4];

void build(int cur, int l, int r) {
	nodes[cur] = { l, r, 1 };
	if (l+1 == r) { return; }
	int le = (l + r) >> 1;
	build(LC(cur), l, le);
	build(RC(cur), le, r);
}

void update(int cur, int l, int r, int io) {
	if (nodes[cur].l == l && nodes[cur].r == r) {
		nodes[cur].state = io;
		return;
	}

	int le = (nodes[cur].l + nodes[cur].r) >> 1, lc = LC(cur), rc = RC(cur);
	if (nodes[cur].state != 0) {
		nodes[lc].state = nodes[rc].state = nodes[cur].state;
		nodes[cur].state = 0;
	}

	if (r <= le) {
		update(lc, l, r, io);
	} else if (l >= le) {
		update(rc, l, r, io);
	} else {
		update(lc, l, le, io);
		update(rc, le, r, io);
	}

	if (nodes[lc].state == nodes[rc].state) {
		nodes[cur].state = nodes[lc].state;
	}
}

void query(int cur, int &l, int &r) {
	if (nodes[cur].state != 0) {
		if (nodes[cur].state == 1) { l = r = -1; }
		else { l = nodes[cur].l; r = nodes[cur].r; }
		return;
	}
	int ll, lr; query(LC(cur), ll, lr);
	int rl, rr; query(RC(cur), rl, rr);

	if (ll >= 0) {
		l = ll; r = max(lr, rr);
	} else {
		l = rl; r = rr;
	}
}

int main() {
	int n; scanf("%d", &n);
	int x1, x2, y1, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	e[0] = { x1, y1, y2, 2 };
	e[1] = { x2, y1, y2, 1 };
	ys[0] = y1; ys[1] = y2;

	for (int i=1; i<n; ++i) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int idx1 = i * 2, idx2 = i * 2 + 1;
		e[idx1] = { x1, y1, y2, 1 };
		e[idx2] = { x2, y1, y2, 2 };
		ys[idx1] = y1; ys[idx2] = y2;
	}

	sort(ys, ys+n*2);
	ycnt = 1;
	for (int i=1; i<n*2; ++i) {
		if (ys[i] != ys[ycnt-1]) { ys[ycnt++] = ys[i]; }
	}

	for (int i=0; i<n*2; ++i) {
		e[i].y1 = get_y_hash(e[i].y1, ycnt);
		e[i].y2 = get_y_hash(e[i].y2, ycnt);
	}
	sort(e, e+n*2, [](const Edge &e1, const Edge &e2) -> bool {
		return (e1.x == e2.x) ? (e1.io > e2.io) : (e1.x < e2.x);
	});

	build(1, 0, ycnt-1);
	int last = e[0].x - 1, d, u, sta, end;
	bool found = false;

	for (int i=0; i<=n*2; ++i) {
		if (i == n*2 || e[i].x != last) {
			int l, r; query(1, l, r);
			if (l >= 0 && !found) {
				found = true;
				d = l; u = r;
				sta = last;
			} else if (l < 0 && found) {
				end = last;
				break;
			}

			if (i < n*2) {
				last = e[i].x;
			} else {
				break;
			}
		}

		update(1, e[i].y1, e[i].y2, e[i].io);
	}

	printf("%d %d %d %d\n", sta, ys[d], end, ys[u]);
	return 0;
}
