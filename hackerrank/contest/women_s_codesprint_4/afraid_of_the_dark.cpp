#include <bits/stdc++.h>
using namespace std;

#define MAXN 120000
bool s[MAXN+1];
int adj[MAXN+1], cnt[MAXN+1], skip[MAXN+1], ans[MAXN+1];

struct Edge { int v, nxt; } e[MAXN*2+1];

int dfs(int cur, int par) {
	int mn = MAXN*2;
	cnt[cur] = 1;
	for (int i=adj[cur], v; i!=-1; i=e[i].nxt) {
		if ((v=e[i].v) == par) { continue; }
		cnt[cur] += dfs(v, cur);
		mn = min(skip[v], mn);
	}

	if (!s[cur]) { mn = min(mn, cnt[cur]); }
	skip[cur] = mn;
	return cnt[cur];
}

void dfs2(int cur, int par, int pv, int n) {
	int mn = MAXN*2, smn = MAXN*2, mnv = -1, smnv = -1;
	for (int i=adj[cur]; i!=-1; i=e[i].nxt) {
		int v = e[i].v;
		int val = (v == par) ? pv : skip[v];
		if (val <= mn) {
			smn = mn; smnv = mnv;
			mn = val; mnv = v;
		} else if (val < smn) {
			smn = val; smnv = v;
		}
	}

	ans[cur] = max(0, n-mn);
	for (int i=adj[cur], v; i!=-1; i=e[i].nxt) {
		if ((v=e[i].v) == par) { continue; }
		int input = v == mnv ? smn : mn;
		if (!s[cur]) { input = min(input, n-cnt[v]); }
		dfs2(v, cur, input, n);
	}
}

int main() {
	int T; scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		int n, off = 0, efirst = 0; scanf("%d", &n);
		for (int i=1; i<=n; ++i) {
			int v; scanf("%d", &v);
			s[i] = v == 1;
			if (!s[i]) { ++off; }
		}

		memset(adj, -1, sizeof(adj));
		for (int i=1; i<n; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			e[efirst] = { v, adj[u] }; adj[u] = efirst++;
			e[efirst] = { u, adj[v] }; adj[v] = efirst++;
		}

		if (off % 2 == 0) {
			for (int i=1; i<=n; ++i) { printf("%d\n", n); }
			continue;
		}

		dfs(1, 0);
		dfs2(1, 0, 0, n);
		for (int i=1; i<=n; ++i) { printf("%d\n", ans[i]); }
	}

	return 0;
}
