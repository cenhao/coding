#include <bits/stdc++.h>
using namespace std;

#define MAXN 50

int e[MAXN+1][MAXN*MAXN+1];
int pid[MAXN+1];

int find(int x) {
	if (pid[x] != pid[pid[x]]) { pid[x] = find(pid[x]); }
	return pid[x];
}

void merge(int x, int y) {
	int px = find(x), py = find(y);
	pid[py] = px;
}

int flood(int cur, int id) {
	int mn = e[cur][0];
	pid[cur] = id;
	for (int i=1; i<=e[cur][0]; ++i) {
		if (pid[e[cur][i]] == 0) { mn = min(mn, flood(e[cur][i], id)); }
	}
	return mn;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i) { e[i][0] = 0; }
	for (int i=0; i<m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		e[u][++e[u][0]] = v; e[v][++e[v][0]] = u;
	}

	bool possible = (n >= m);
	for (int i=1; possible && i<=n; ++i) {
		if (e[i][0] > 2) { possible = false; }
	}

	if (!possible) {
		printf("NO\n");
		return 0;
	}

	memset(pid, 0, sizeof(pid));
	int pcnt = 0, lcnt = 0;
	for (int i=1; i<=n; ++i) {
		if (pid[i] == 0) {
			lcnt += (flood(i, i) == 2) ? 1 : 0;
			++pcnt;
		}
	}

	if (m == n) {
		printf(pcnt > 1 ? "NO\n" : "YES\n0\n");
		return 0;
	} else if (lcnt > 0) {
		printf("NO\n");
		return 0;
	}

	printf("YES\n%d\n", n-m);

	for (int i=1, add=0; i<=n; ++i) {
		if (e[i][0] > 1) { continue; }
		int pi = find(i);
		for (int j=i+(n==1?0:1); j<=n; ++j) {
			if (e[j][0] > 1) { continue; }
			int pj = find(j);
			if (pi != pj || add == n-m-1) {
				printf("%d %d\n", i, j);
				e[i][++e[i][0]] = j; e[j][++e[j][0]] = i;
				merge(pi, pj);
				++add;
				break;
			}
		}

		if (e[i][0] < 2) { --i; }
	}

	return 0;
}
