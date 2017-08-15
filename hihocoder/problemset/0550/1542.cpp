#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

struct Edge { int v, nxt; } e[MAXN*2];
int adj[MAXN+1], ecnt;
int ans[MAXN+1];

void dfs(int cur, int par) {
	ans[cur] = par;
	for (int i=adj[cur]; i!=-1; i=e[i].nxt) {
		if (e[i].v == par) { continue; }
		dfs(e[i].v, cur);
	}
}

int main() {
	int n, k; scanf("%d%d", &n, &k);
	ecnt = 0;
	memset(adj, -1, sizeof(adj));
	for (int i=1; i<n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		e[ecnt] = { v, adj[u] }; adj[u] = ecnt++;
		e[ecnt] = { u, adj[v] }; adj[v] = ecnt++;
	}

	dfs(k, 0);
	for (int i=1; i<=n; ++i) { printf("%d%c", ans[i], (i == n) ? '\n' : ' '); }
	return 0;
}
