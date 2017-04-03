#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int dist[MAXN+1][MAXN+1];
int leaf[MAXN+1], leafid[MAXN+1], lcnt;
bool isleaf[MAXN+1];
int level[MAXN+1][MAXN+1], used[MAXN+1];
int down[MAXN+1], up[MAXN+1];
int p[MAXN+1];

bool dfs_wrapped(int par, int cur, int depth);

bool dfs(int par, int cur, int depth) {
	p[cur] = par;
	if (isleaf[cur]) {
		for (int i=1; i<=lcnt; ++i) {
			if (down[leaf[i]] < 0 || up[leaf[i]] < 0) { continue; }
			if (down[leaf[i]]+up[leaf[i]] != dist[cur][leaf[i]]) { return false; }
		}

		down[cur] = up[cur] = 0;
		return true;
	}

	int c;
	for (c=used[depth+1]+1; c<=level[depth+1][0]; ++c) {
		if (!dfs_wrapped(cur, level[depth+1][c], depth+1)) { break; }
	}

	--c;
	if (c == used[depth+1]) { return false; }
	used[depth+1] = c;
	return true;
}

bool dfs_wrapped(int par, int cur, int depth) {
	for (int i=1; i<=lcnt; ++i) { if (down[leaf[i]] >= 0) { ++down[leaf[i]]; } }
	bool ret = dfs(par, cur, depth);
	for (int i=1; i<=lcnt; ++i) {
		if (down[leaf[i]] >= 0) {
			if (down[leaf[i]] > 0) { --down[leaf[i]]; }
			else { ++up[leaf[i]]; }
		}
	}

	return ret;
}

int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	memset(used, 0, sizeof(used));
	for (int i=1; i<=m; ++i) { scanf("%d", &level[i][0]); }
	for (int i=1; i<=m; ++i) {
		for (int j=1; j<=level[i][0]; ++j) {
			scanf("%d", &level[i][j]);
		}
	}

	lcnt = k;
	memset(isleaf, false, sizeof(isleaf));
	memset(leafid, 0, sizeof(leafid));
	for (int i=1; i<=k; ++i) {
		scanf("%d", &leaf[i]);
		isleaf[leaf[i]] = true;
	}
	memset(dist, 0, sizeof(dist));

	for (int i=1; i<=k; ++i) {
		for (int j=1; j<=k; ++j) {
			scanf("%d", &dist[leaf[i]][leaf[j]]);
		}
	}

	memset(down, -1, sizeof(down));
	memset(up, -1, sizeof(up));
	dfs_wrapped(0, level[1][1], 1);

	for (int i=1; i<=n; ++i) {
		printf("%d%c", p[i], i == n ? '\n' : ' ');
	}

	return 0;
}
