#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

struct Node {
	int id, nxt;
} nodes[MAXN*2];
int ncnt;
int adj[MAXN];
int in[MAXN], out[MAXN];
int sid[MAXN];

void dfs(int cur, int par) {
	for (int i=adj[cur]; i!=-1; i=nodes[i].nxt) {
		if (nodes[i].id != par) { dfs(nodes[i].id, cur); }
	}

	int scnt = 0;
	for (int i=adj[cur]; i!=-1; i=nodes[i].nxt) {
		if (nodes[i].id != par) { sid[scnt++] = nodes[i].id; }
	}

	sort(sid, sid+scnt, [](int a, int b) {
		return ::out[a] > ::out[b];
	});

	int cost = in[cur]-out[cur], need = in[cur];
	for (int i=0; i<scnt; ++i) {
		if (need - cost < in[sid[i]]) {
			need = cost + in[sid[i]];
		}

		cost += in[sid[i]] - out[sid[i]];
	}

	in[cur] = need; out[cur] = need - cost;
}

int main() {
	memset(nodes, -1, sizeof(nodes));
	memset(adj, -1, sizeof(adj));
	ncnt = 0;

	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d %d", &in[i], &out[i]); }

	for (int i=1; i<n; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		--u; --v;
		nodes[ncnt] = { v, adj[u] };
		adj[u] = ncnt++;
		nodes[ncnt] = { u, adj[v] };
		adj[v] = ncnt++;
	}

	dfs(0, -1);
	printf("%d\n", in[0]);

	return 0;
}
