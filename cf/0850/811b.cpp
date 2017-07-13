/*
 * The core of the algorithm here is the segment tree. But instead of a simple
 * tree, it's rather a segment forest.
 *
 * For a tree, it's recording given a range [a, b], how many items there are,
 * satisfying a <= v <= b.
 * And the idea here is, build a tree for each range [1, k], where 1 <= k <= n,
 * from 1 to n. And as there's no further modification to each tree, so subtrees
 * can be reused.
 *
 * So given a query [l, r, v], find the # of items <= v in segment tree built
 * with items [1, r], say the result is v_r. And get the result for [1, l-1],
 * v_(l-1).
 * Then in range [l, r], # of items <= v is v_r - v_(l-1), call it Vcnt.
 * Then if v is the Vcnt-th item of [l, r], then yes, otherwise no.
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

int a[MAXN+1];
int root[MAXN+1], nfirst;
struct Node{
	int cnt, lc, rc;
} nodes[MAXN*20];

// increase # of value in [l, r], represented by nodes[cur].
void insert(int cur, int pre, int l, int r, int v) {
	nodes[cur] = nodes[pre];
	++nodes[cur].cnt;
	if (l == r) { return ; }

	int le = (l + r) >> 1;
	if (v <= le) {
		nodes[cur].lc = ++nfirst;
		insert(nodes[cur].lc, nodes[pre].lc, l, le, v);
	} else {
		nodes[cur].rc = ++nfirst;
		insert(nodes[cur].rc, nodes[pre].rc, le+1, r, v);
	}
}

int query(int cur, int pre, int l, int r, int v) {
	if (r <= v) { return nodes[cur].cnt - nodes[pre].cnt; }

	int le = (l + r) >> 1;
	int ans = query(nodes[cur].lc, nodes[pre].lc, l, le, v);
	if (v > le) { ans += query(nodes[cur].rc, nodes[pre].rc, le+1, r, v); }

	return ans;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	nfirst = 0;
	nodes[0] = { 0, 0, 0 };
	root[0] = 0;
	for (int i=1; i<=n; ++i) {
		scanf("%d", &a[i]);
		root[i] = ++nfirst;
		insert(root[i], root[i-1], 1, n, a[i]);
	}
	for (int i=0; i<m; ++i) {
		int l, r, v; scanf("%d%d%d", &l, &r, &v);
		if (v < l || v > r) {
			printf("Yes\n");
			continue;
		}

		printf(v-l+1 == query(root[r], root[l-1], 1, n, a[v]) ? "Yes\n" : "No\n");
	}

	return 0;
}
