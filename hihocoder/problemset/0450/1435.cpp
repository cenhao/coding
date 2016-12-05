#include <stdio.h>
#include <string.h>

#define MAXN 100000

int children[MAXN+1], mark[MAXN+1], lfirst;
struct Link {
	int cn;
	int nxt;
} links[MAXN];

bool dfs(int start) {
	if (mark[start] != 0) { return mark[start] > 0; }

	mark[start] = 1;
	for (int cur=children[start]; cur!=-1; cur=links[cur].nxt) {
		if (dfs(links[cur].cn)) {
			return true;
		}
	}

	mark[start] = -1;
	return false;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d %d", &n, &m);
		memset(children, -1, sizeof(children));
		lfirst = 0;

		int u, v;
		for (int i=0; i<m; ++i) {
			scanf("%d %d", &u, &v);
			links[lfirst].cn = v;
			links[lfirst].nxt = children[u];
			children[u] = lfirst++;
		}

		bool circle = false;
		memset(mark, 0, sizeof(mark));
		for (int i=1; i<=n; ++i) {
			if (mark[i] != 0) { continue; }
			if (dfs(i)) {
				circle = true;
				break;
			}
		}

		printf(circle ? "YES\n" : "NO\n");
	}

	return 0;
}
