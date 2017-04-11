#include <bits/stdc++.h>
using namespace std;

#define MAXN 500

bool vis[MAXN+1];
int mat[MAXN+1][MAXN+1];

bool dfs(int cur, int n, int par) {
	if (vis[cur]) { return false; }

	vis[cur] = true;
	for (int i=1; i<=n; ++i) {
		if (mat[cur][i] > 1) { return false; }
		if (mat[cur][i] && i != par && !dfs(i, n, cur)) {
			return false;
		}
	}

	return true;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d %d", &n, &m);
		memset(mat, 0, sizeof(mat));
		memset(vis, 0, sizeof(vis));
		for (int i=0; i<m; ++i) {
			int u, v; scanf("%d %d", &u, &v);
			++mat[u][v]; ++mat[v][u];
		}

		bool ok = dfs(1, n, 0);
		if (ok) {
			for (int i=1; i<=n; ++i) {
				if (!vis[i]) {
					ok = false;
					break;
				}
			}
		}

		printf(ok ? "YES\n" : "NO\n");
	}

	return 0;
}
