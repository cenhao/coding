#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
#define LC(x) (x << 1)
#define RC(x) ((x<<1) + 1)

int a[MAXN+1], pos[MAXN+1];
bool ans[MAXN+1];
struct Query {
	int l, r, v, id;
} q[MAXN+1];

int cnt[MAXN*4+1];

void build(int cur, int l, int r) {
	cnt[cur] = 0;
	if (l == r) { return; }
	int lc = LC(cur), rc = RC(cur);
	int le = (l + r) >> 1;
	build(lc, l, le);
	build(rc, le+1, r);
}

void add(int cur, int start, int end, int pos) {
	++cnt[cur];
	if (start == end && pos == start) { return; }

	int lc = LC(cur), rc = RC(cur);
	int le = (start + end) >> 1;
	if (pos <= le) {
		add(lc, start, le, pos);
	} else {
		add(rc, le+1, end, pos);
	}
}

int query(int cur, int start, int end, int l, int r) {
	if (start == l && end == r) { return cnt[cur]; }
	int lc = LC(cur), rc = RC(cur);
	int le = (start + end) >> 1;
	if (r <= le) {
		return query(lc, start, le, l, r);
	} else if (l > le) {
		return query(rc, le+1, end, l, r);
	}

	return query(lc, start, le, l, le) + query(rc, le+1, end, le+1, r);
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	for (int i=0; i<m; ++i) {
		scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].v);
		q[i].id = i;
	}

	sort(q, q+m, [](const Query &q1, const Query &q2) -> bool {
		return ::a[q1.v] < ::a[q2.v];
	});
	build(1, 1, n);

	int added = 0;
	for (int i=0; i<m; ++i) {
		if (q[i].v > q[i].r || q[i].v < q[i].l) {
			ans[q[i].id] = true;
		} else {
			int cur_v = a[q[i].v];
			while (added < cur_v) { add(1, 1, n, pos[++added]); }
			int no_more = query(1, 1, n, q[i].l, q[i].r);
			ans[q[i].id] = no_more == (q[i].v - q[i].l + 1);
		}
	}

	for (int i=0; i<m; ++i) {
		printf(ans[i] ? "Yes\n" : "No\n");
	}

	return 0;
}
