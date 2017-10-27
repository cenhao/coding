#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

struct Edge {
	int v, nxt;
}edges[MAXN];

int adj[MAXN+1], efirst;
int sg[MAXN+1];

int dfs(int cur) {
	if (sg[cur] != -1) { return sg[cur]; }
	sg[cur] = 0;
	for (int i=adj[cur]; i!=-1; i=edges[i].nxt) {
		sg[cur] ^= dfs(edges[i].v) + 1;
	}
	return sg[cur];
}

int main() {
	int Q; scanf("%d", &Q);
	for (int q=0; q<Q; ++q) {
		efirst = 0;
		memset(adj, -1, sizeof(adj));
		memset(sg, -1, sizeof(sg));
		int n; scanf("%d", &n);
		for (int i=1; i<n; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			edges[efirst] = { v, adj[u] };
			adj[u] = efirst++;
		}

		int root = -1;
		for (int i=1; i<=n; ++i) {
			if (sg[i] != -1) { continue; }
			root = i;
			dfs(i);
		}

		printf("%d", sg[root] == 0 ? 0 : 1);
		int nsg = 0;
		for (int i=adj[root]; i!=-1; i=edges[i].nxt) {
			nsg ^= sg[edges[i].v];
		}
		printf("%d", nsg == 0 ? 0 : 1);
	}

	printf("\n");
	return 0;
}
