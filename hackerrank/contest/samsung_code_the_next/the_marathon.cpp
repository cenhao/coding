#include <bits/stdc++.h>
using namespace std;

#define MAXN 140000

struct Edge {
	int v, nxt;
} e[MAXN];
int adj[MAXN+1], ecnt;
int id[MAXN+1];
bool c[MAXN+1], vis[MAXN+1];

bool dfs(int cur, int gid, int &cnt) {
	id[cur] = gid;
	vis[cur] = true;
	bool circle = false;
	for (int i=adj[cur]; i!=-1; i=e[i].nxt) {
		bool tmp = false;
		if ((id[e[i].v] == gid && vis[e[i].v])|| c[e[i].v]) {
			tmp = true;
		} else if (id[e[i].v] == -1) {
			tmp = dfs(e[i].v, gid, cnt);
		}

		if (tmp) {
			++cnt;
			circle = true;
		}
	}

	vis[cur] = false;
	return c[cur] = circle;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d %d", &n, &m);
		memset(adj, -1, sizeof(adj));
		memset(id, -1, sizeof(id));
		memset(c, false, sizeof(c));
		memset(vis, false, sizeof(vis));
		ecnt = 0;
		for (int i=0; i<m; ++i) {
			int u, v; scanf("%d %d", &u, &v);
			e[ecnt] = { v, adj[u] };
			adj[u] = ecnt++;
		}

		int ans = 0, gid = 0;
		for (int i=1; i<=n; ++i) {
			if (id[i] >= 0) { continue; }
			dfs(i, gid++, ans);
		}

		printf("%d\n", ans);
	}

	return 0;
}
