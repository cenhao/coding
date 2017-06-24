/*
 * scanning for the lowest index to the highest index for the nodes
 * given an edge [u, v], and u < v, add 1 to tree array as count of
 * edges with the lower indexed node's id no more than u.
 *
 * Then the result of each query can be calculated by rearranging
 * the order.
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
vector<int> adj[MAXN+1];
int bits[MAXN+1];
int ans[MAXN];

struct Query {
	int l, r, id;
} q[MAXN];

void update(int pos, int mxn) {
	while (pos <= mxn) {
		++bits[pos];
		pos += (pos & (~(pos-1)));
	}
}

int query(int pos) {
	int sum = 0;
	while (pos > 0) {
		sum += bits[pos];
		pos -= (pos & (~(pos-1)));
	}
	return sum;
}

int query(int l, int r) {
	return query(r) - query(l);
}

int main() {
	int n, Q; scanf("%d %d", &n, &Q);
	for (int i=1; i<n; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		if (u > v) { swap(u, v); }
		adj[v].push_back(u);
	}

	for (int i=0; i<Q; ++i) {
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].id = i;
	}

	sort(q, q+Q, [](const Query &q1, const Query &q2) {
		return q1.r < q2.r;
	});

	memset(bits, 0, sizeof(bits));
	int qpos = 0;
	for (int i=1; i<=n && qpos < Q; ++i) {
		for (auto ent : adj[i]) { update(ent, n); }
		while (qpos < Q && q[qpos].r <= i) {
			ans[q[qpos].id] = q[qpos].r - q[qpos].l + 1 - query(q[qpos].l-1, q[qpos].r);
			++qpos;
		}
	}

	for (int i=0; i<Q; ++i) { printf("%d\n", ans[i]); }
	return 0;
}
