#include <bits/stdc++.h>
using namespace std;

#define MAXA 100
#define MAXN 50000
#define LC(x) (x << 1)
#define RC(x) ((x << 1) + 1)

const int p[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int pcnt[101][25];

void init() {
	memset(pcnt, 0, sizeof(pcnt));
	for (int i=2; i<=100; ++i) {
		for (int j=0, tmp=i; j<25; ++j) {
			while (tmp % p[j] == 0) {
				++pcnt[i][j]; tmp /= p[j];
			}
		}
	}
}

struct STN {
	bool all;
	int l, r, cnt[25];
} stn[MAXN*4];

void build(int cur, int l, int r) {
	memset(stn[cur].cnt, 0, sizeof(stn[cur].cnt));
	stn[cur].l = l; stn[cur].r = r;
	stn[cur].all = l == r;
	if (stn[cur].all) { return; }
	int le = (l + r) >> 1;
	build(LC(cur), l, le);
	build(RC(cur), le+1, r);
}

int64_t calc(int64_t a, int n, int m) {
	int64_t ret = 1, base = a;
	while (n > 0) {
		if (n & 1) { ret = (ret * base) % m; }
		base = (base * base) % m;
		n >>= 1;
	}

	return ret;
}

void update(int cur, int l, int r, int v) {
	if (l == stn[cur].l && r == stn[cur].r) {
		stn[cur].all = true;
		int mul = r-l + 1;
		for (int i=0; i<25; ++i) { stn[cur].cnt[i] = pcnt[v][i] * mul; }
		return;
	}

	int le = (stn[cur].l + stn[cur].r) >> 1;
	int lc = LC(cur), rc = RC(cur);
	if (stn[cur].all) {
		int div = stn[cur].r - stn[cur].l + 1;
		int mul = stn[lc].r - stn[lc].l + 1;
		for (int i=0; i<25; ++i) { stn[lc].cnt[i] = stn[cur].cnt[i]/div*mul; }
		mul = stn[rc].r - stn[rc].l + 1;
		for (int i=0; i<25; ++i) { stn[rc].cnt[i] = stn[cur].cnt[i]/div*mul; }
		stn[lc].all = stn[rc].all = true;
	}
	stn[cur].all = false;
	if (r <= le) {
		update(lc, l, r, v);
	} else if (l > le) {
		update(rc, l, r, v);
	} else {
		update(lc, l, le, v);
		update(rc, le+1, r, v);
	}

	for (int i=0; i<25; ++i) {
		stn[cur].cnt[i] = stn[lc].cnt[i] + stn[rc].cnt[i];
	}
}

void query(int cur, int l, int r, int *res) {
	if (stn[cur].l == l && stn[cur].r == r) {
		for (int i=0; i<25; ++i) { res[i] += stn[cur].cnt[i]; }
		return;
	}

	if (stn[cur].all) {
		int div = stn[cur].r - stn[cur].l + 1, mul = r - l + 1;
		for (int i=0; i<25; ++i) {
			res[i] += stn[cur].cnt[i] / div * mul;
		}
	} else {
		int le = (stn[cur].l + stn[cur].r) >> 1;
		int lc = LC(cur), rc = RC(cur);
		if (r <= le) {
			query(lc, l, r, res);
		} else if (l > le) {
			query(rc, l, r, res);
		} else {
			query(lc, l, le, res);
			query(rc, le+1, r, res);
		}
	}
}

int main() {
	init();
	int n; scanf("%d", &n);
	build(1, 0, n-1);
	for (int i=0; i<n; ++i) {
		int a; scanf("%d", &a);
		update(1, i, i, a);
	}
	int q; scanf("%d", &q);
	for (int i=0; i<q; ++i) {
		int cmd; scanf("%d", &cmd);
		if (cmd == 1) {
			int l, r, x; scanf("%d%d%d", &l, &r, &x);
			update(1, l-1, r-1, x);
		} else {
			int l, r, ll, rr, m;
			scanf("%d%d%d%d%d", &l, &r, &ll, &rr, &m);
			int num[25], dom[25];
			memset(num, 0, sizeof(num));
			memset(dom, 0, sizeof(dom));
			query(1, l-1, r-1, num);
			query(1, ll-1, rr-1, dom);
			bool ok = true;
			for (int j=0; j<25 && ok; ++j) {
				num[j] -= dom[j];
				ok = (num[j] >= 0);
			}

			if (!ok) {
				printf("-1\n");
			} else {
				int64_t ans = 1;
				for (int j=0; j<25; ++j) {
					if (num[j] > 0) {
						ans = (ans * calc(p[j], num[j], m)) % m;
					}
				}

				printf("%" PRId64 "\n", ans);
			}
		}
	}

	return 0;
}
