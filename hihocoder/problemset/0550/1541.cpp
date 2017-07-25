#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define EPS 1e-7

struct Edge {
	int v, nxt;
} e[MAXN*2];

int id[MAXN+1];
int adj[MAXN+1];
int rmq[20][MAXN*2+1];

void dfs(int cur, int par, int &cnt) {
	rmq[0][(id[cur] = cnt++)] = cur;
	for (int i=adj[cur], v; i!=-1; i=e[i].nxt) {
		if ((v = e[i].v) == par) { continue; }
		dfs(v, cur, cnt);
		rmq[0][cnt++] = cur;
	}
}

void rmq_init(int rng) {
	for (int i=1; (1<<i)<rng; ++i) {
		int ii = i - 1, len = 1 << (i-1);
		for (int j=0, end=rng+1-(1<<i); j<end; ++j) {
			rmq[i][j] = min(rmq[ii][j], rmq[ii][j+len]);
		}
	}
}

int lca(int u, int v) {
	int uid = id[u], vid = id[v];
	if (uid > vid) { swap(uid, vid); }
	int dist = vid - uid + 1;
	int len = log2(dist) + EPS;
	if (dist == (dist & (~(dist-1)))) {
		return rmq[len][uid];
	}

	return min(rmq[len][uid], rmq[len][vid-(1<<len)+1]);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int ecnt = 0;
		memset(adj, -1, sizeof(adj));

		int n, m; scanf("%d%d", &n, &m);
		for (int i=1; i<n; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			e[ecnt] = {v, adj[u]}; adj[u] = ecnt++;
			e[ecnt] = {u, adj[v]}; adj[v] = ecnt++;
		}

		int cnt = 0;
		dfs(1, -1, cnt);
		rmq_init(cnt);

		for (int i=0; i<m; ++i) {
			int u1, v1, u2, v2; scanf("%d%d%d%d", &u1, &v1, &u2, &v2);
			int lca1 = lca(u1, v1);
			int lca2 = lca(u2, v2);
			int lca12 = lca(lca1, lca2);
			if (lca12 != lca1) {
				if (lca12 != lca2) {
					printf("NO\n");
				} else {
					if (lca(lca1, u2) != lca1 && lca(lca1, v2) != lca1) {
						printf("NO\n");
					} else {
						printf("YES\n");
					}
				}
			} else {
				if (lca(lca2, u1) != lca2 && lca(lca2, v1) != lca2) {
					printf("NO\n");
				} else {
					printf("YES\n");
				}
			}
		}
	}

	return 0;
}
