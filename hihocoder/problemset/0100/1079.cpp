#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;

#define MAXN 100000

struct Poster {
	int l, r;
} posters[MAXN];

int x[MAXN*2];
unordered_map<int, int> dis;

struct STN {
	int l, r;
	int lc, rc;
	int n;
} nodes[MAXN*4];
int nfirst;
bool vis[MAXN*2];
int ans;

int build(int l, int r) {
	int cur = nfirst++;
	nodes[cur].l = l; nodes[cur].r = r;
	nodes[cur].lc = nodes[cur].rc = -1;
	nodes[cur].n = -1;

	if (l == r-1) { return cur; }

	int le = (l + r) >> 1;
	nodes[cur].lc = build(l, le);
	nodes[cur].rc = build(le, r);
	return cur;
}

void update(int cur, int l, int r, int pn) {
	if (l == nodes[cur].l && r == nodes[cur].r) {
		nodes[cur].n = pn;
		return;
	}

	int le = (nodes[cur].l + nodes[cur].r) >> 1;
	if (nodes[cur].n != -1) {
		update(nodes[cur].lc, nodes[cur].l, le, nodes[cur].n);
		update(nodes[cur].rc, le, nodes[cur].r, nodes[cur].n);
		nodes[cur].n = -1;
	}

	if (r <= le) {
		update(nodes[cur].lc, l, r, pn);
	} else if (l >= le) {
		update(nodes[cur].rc, l, r, pn);
	} else {
		update(nodes[cur].lc, l, le, pn);
		update(nodes[cur].rc, le, r, pn);
	}
}

void query(int cur) {
	if (nodes[cur].n != -1) {
		if (!vis[nodes[cur].n]) {
			++ans;
			vis[nodes[cur].n] = true;
		}
	} else {
		if (nodes[cur].lc != -1) { query(nodes[cur].lc); }
		if (nodes[cur].rc != -1) { query(nodes[cur].rc); }
	}
}

int main() {
	int n, l; scanf("%d %d", &n, &l);
	for (int i=0; i<n; ++i) {
		scanf("%d %d", &posters[i].l, &posters[i].r);
		x[i*2] = posters[i].l; x[i*2+1] = posters[i].r;
	}

	sort(x, x+n*2);
	int last = -1, cnt = 0;
	for (int i=0, end=n*2; i<end; ++i) {
		if (x[i] == last) { continue; }
		last = x[i];
		dis.insert(pair<int, int>(last, cnt++));
	}

	nfirst = 0;
	build(0, cnt-1);
	for (int i=0; i<n; ++i) {
		update(0, dis[posters[i].l], dis[posters[i].r], i);
	}

	ans = 0;
	memset(vis, 0, sizeof(vis));
	query(0);

	printf("%d\n", ans);
	return 0;
}
