#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

struct Link {
	int v, nxt;
	int diff;
} links[MAXN*2];

int adj[MAXN+1];
int gid[MAXN+1];
int off[MAXN+1];

void assign_gid(int cur, int id, int v) {
	gid[cur] = id; off[cur] = v;
	for (int i=adj[cur]; i!=-1; i=links[i].nxt) {
		if (gid[links[i].v] != 0) { continue; }
		assign_gid(links[i].v, id, v-links[i].diff);
	}
}

int main() {
	memset(adj, -1, sizeof(adj));
	memset(gid, 0, sizeof(gid));
	int m, n, q; scanf("%d %d %d", &n, &m, &q);
	for (int i=0; i<m; ++i) {
		int u, v, d; scanf("%d %d %d", &u, &v, &d);
		int eid = i * 2;
		links[eid].v = v; links[eid].diff = d; links[eid].nxt = adj[u];
		adj[u] = eid++;
		links[eid].v = u; links[eid].diff = -d; links[eid].nxt = adj[v];
		adj[v] = eid;
	}

	int gcnt = 0;
	for (int i=1; i<=n; ++i) {
		if (gid[i] == 0) { assign_gid(i, ++gcnt, 0); }
	}

	for (int i=0; i<q; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		if (gid[u] != gid[v]) {
			printf("-1\n");
		} else {
			printf("%d\n", off[u] - off[v]);
		}
	}

	return 0;
}
