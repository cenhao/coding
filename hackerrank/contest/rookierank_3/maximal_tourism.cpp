#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

struct Edge {
	int v, nxt;
} e[MAXN*2+10];

int adj[MAXN+1];
int gid[MAXN+1];
int cnt[MAXN+1];

void dfs(int cur, int id) {
	gid[cur] = id;
	++cnt[id];

	for (int i=adj[cur]; i!=-1; i=e[i].nxt) {
		int v = e[i].v;
		if (gid[v] == -1) { dfs(v, id); }
	}
}

int main() {
	memset(adj, -1, sizeof(adj));

	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		int idx = i*2 + 1;
		e[idx] = { v, adj[u] }; adj[u] = idx;
		++idx;
		e[idx] = { u, adj[v] }; adj[v] = idx;
	}

	memset(gid, -1, sizeof(gid));
	memset(cnt, 0, sizeof(cnt));
	int nid = 0;
	gid[0] = -2;
	for (int i=1; i<=n; ++i) {
		if (gid[i] == -1) { dfs(i, nid++); }
	}

	int mx = -1;
	for (int i=0; i<nid; ++i) { mx = max(mx, cnt[i]); }
	printf("%d\n", mx);

	return 0;
}
