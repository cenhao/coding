#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int bw[MAXN];
int adj[MAXN], p[MAXN];
int mv[MAXN][2], amn, amx, amnp, amxp;
int ans[MAXN];

struct Edge { int v, nxt; } e[MAXN * 2];

void dfs(int cur, int par) {
	p[cur] = par;
	mv[cur][0] = mv[cur][1] = (bw[cur] == 0) ? -1 : 1;
	for (int i=adj[cur]; i!=-1; i=e[i].nxt) {
		int v = e[i].v;
		if (v == par) { continue; }
		dfs(v, cur);
		mv[cur][0] = min(mv[cur][0], mv[cur][0]+mv[v][0]);
		mv[cur][1] = max(mv[cur][1], mv[cur][1]+mv[v][1]);
	}

	if (mv[cur][0] < amn) { amn = mv[cur][0]; amnp = cur; }
	if (mv[cur][1] > amx) { amx = mv[cur][1]; amxp = cur; }
}

void dfs1(int cur, int pick, int &cnt) {
	const static int sign[2] = {-1, 1};
	for (int i=adj[cur]; i!=-1; i=e[i].nxt) {
		int v = e[i].v;
		if (v == p[cur]) { continue; }
		if (mv[v][pick] * sign[pick] > 0) { dfs1(v, pick, cnt); }
	}

	ans[cnt++] = cur;
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &bw[i]); }
	memset(adj, -1, sizeof(adj));
	amn = amx = 0;
	for (int i=1; i<n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		--u; --v;
		int uidx = (i-1) * 2, vidx = (i-1) * 2 + 1;
		e[uidx] = { v, adj[u] }; adj[u] = uidx;
		e[vidx] = { u, adj[v] }; adj[v] = vidx;
	}

	dfs(0, -1);
	int cnt = 0, ansv;
	if (amx > abs(amn)) {
		ansv = amx;
		dfs1(amxp, 1, cnt);
	} else {
		ansv = abs(amn);
		dfs1(amnp, 0, cnt);
	}

	sort(ans, ans+cnt);
	printf("%d\n%d\n", ansv, cnt);
	for (int i=0; i<cnt; ++i) {
		printf("%d%c", ans[i]+1, (i==cnt-1) ? '\n' : ' ');
	}

	return 0;
}
