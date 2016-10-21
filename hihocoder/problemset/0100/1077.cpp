#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 1000000

int w[MAXN+1];

struct STN {
	int l, r;
	int mn;
	int lc, rc;
} stn[MAXN*4];
int first = 0;

int build(int l, int r) {
	int sn = first++;
	stn[sn].l = l; stn[sn].r = r;
	if (l == r) {
		stn[sn].mn = w[l];
		stn[sn].lc = stn[sn].rc = -1;
	} else {
		int le = (l + r) >> 1;
		stn[sn].lc = build(l, le); 
		stn[sn].rc = build(le+1, r);
		stn[sn].mn = min(stn[stn[sn].lc].mn, stn[stn[sn].rc].mn);
	}

	return sn;
}

int query(int l, int r, int sn) {
	if (stn[sn].l == l && stn[sn].r == r) {
		return stn[sn].mn;
	}

	int le = (stn[sn].l + stn[sn].r) >> 1;
	if (r <= le) {
		return query(l, r, stn[sn].lc);
	} else if (l > le) {
		return query(l, r, stn[sn].rc);
	} else {
		return min(query(l, le, stn[sn].lc), query(le+1, r, stn[sn].rc));
	}
}

void update(int idx, int v, int sn) {
	if (stn[sn].l == idx && stn[sn].r == idx) {
		stn[sn].mn = v;
	} else {
		int le = (stn[sn].l + stn[sn].r) >> 1;
		update(idx, v, (idx <= le) ? stn[sn].lc : stn[sn].rc);
		stn[sn].mn = min(stn[stn[sn].lc].mn, stn[stn[sn].rc].mn);
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) { scanf("%d", &w[i]); }

	int r = build(1, n);

	int q; scanf("%d", &q);
	for (int i=0; i<q; ++i) {
		int command, a, b; scanf("%d %d %d", &command, &a, &b);
		if (command == 0) {
			printf("%d\n", query(a, b, r));
		} else {
			update(a, b, r);
		}
	}

	return 0;
}
