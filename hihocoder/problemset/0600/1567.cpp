#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int adj[MAXN+1];
struct Node { int v, nxt; } nodes[MAXN * 2];

int dfs(int cur, int par, int &ans) {
	int cnt = 1;
	for (int i=adj[cur]; i!=-1; i=nodes[i].nxt) {
		if (nodes[i].v == par) { continue; }
		cnt += dfs(nodes[i].v, cur, ans);
	}

	if ((cnt % 2) == 0) { ++ans; }
	return cnt;
}

int main() {
	memset(adj, -1, sizeof(adj));
	int n; scanf("%d", &n);
	for (int i=1; i<n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		int uidx = (i-1)*2, vidx = (i-1)*2+1;
		nodes[uidx] = { v, adj[u] }; adj[u] = uidx;
		nodes[vidx] = { u, adj[v] }; adj[v] = vidx;
	}

	int ans = 0;
	int cnt = dfs(1, -1, ans);

	printf("%d\n", (cnt % 2) == 0 ? ans-1 : 0);
	return 0;
}
