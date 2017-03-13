#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

#define MAXN 50000
#define LC(x) (x << 1)
#define RC(x) ((x<<1)+1)
#define UNDEF 0
#define STOCKED 1
#define UNSTOCKED 2

int s[MAXN];
int r[MAXN][2];

struct STN {
	int state;
	int l, r;
} nodes[MAXN*3*4+1];

void build(int cur, int l, int r) {
	nodes[cur].l = l; nodes[cur].r = r;
	nodes[cur].state = UNSTOCKED;

	if (l == r) { return; }

	int le = (l + r) >> 1;
	build(LC(cur), l, le);
	build(RC(cur), le+1, r);
}

void update(int cur, int l, int r) {
	if (l == nodes[cur].l && r == nodes[cur].r) {
		nodes[cur].state = STOCKED;
		return;
	}

	int lc = LC(cur), rc = RC(cur);
	if (nodes[cur].state != UNDEF) {
		nodes[lc].state = nodes[rc].state = nodes[cur].state;
		nodes[cur].state = UNDEF;
	}

	int le = (nodes[cur].l+nodes[cur].r) / 2;
	if (r <= le) {
		update(lc, l, r);
	} else if (l > le) {
		update(rc, l, r);
	} else {
		update(lc, l, le);
		update(rc, le+1, r);
	}

	if (nodes[lc].state == nodes[rc].state) { nodes[cur].state = nodes[lc].state; }
}

bool query(int cur, int p) {
	if (nodes[cur].state != UNDEF) {
		return nodes[cur].state == STOCKED;
	}

	int le = (nodes[cur].l+nodes[cur].r) / 2;
	return (p <= le) ?  query(LC(cur), p) : query(RC(cur), p);
}

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		map<int, int> idmap;

		int n; scanf("%d", &n);
		for (int i=0; i<n; ++i) {
			scanf("%d", &s[i]);
			idmap[s[i]] = i;
		}

		int v; scanf("%d", &v);
		for (int i=0; i<v; ++i) {
			scanf("%d %d", &r[i][0], &r[i][1]);
			idmap[r[i][0]] = i; idmap[r[i][1]] = i;
		}

		int cnt = 0;
		for (auto &ent : idmap) { ent.second = cnt++; }
		build(1, 0, cnt-1);

		for (int i=0; i<v; ++i) {
			update(1, idmap[r[i][0]], idmap[r[i][1]]);
		}

		int ans = 0;
		for (int i=0; i<n; ++i) {
			if (query(1, idmap[s[i]])) { ++ans; }
		}

		printf("%d\n", ans);
	}
}
