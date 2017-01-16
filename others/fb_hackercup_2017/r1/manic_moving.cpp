#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXN 100
#define MAXK 5000

int dist[MAXN+1][MAXN+1];
int move[MAXK+1][2];

// 0 just pick up i-th item, with i-th item only -> at src[i] from dst[i-1]
// 1 with i-th item, just unload (i-1)-th item -> at dst[i-1] from src[i]
// 2 just unload i-th item, empty -> at dst[i] from src[i] (0 -> 2)
// 2.1 just unload i-th item, empty -> at dst[i] from dst[i-1] (1 -> 2)
// 3 just pick up (i+1)-th item, with i-th item -> at src[i+1] from src[i] (0 -> 3)
// 3.1 just pick up (i+1)-th item, with i-th item -> at src[i+1] from dst[i-1] (1 -> 3)
int cost[MAXK+1][4];

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int n, m, k; scanf("%d%d%d", &n, &m, &k);

		memset(dist, -1, sizeof(dist));
		for (int i=0; i<=n; ++i) { dist[i][i] = 0; }
		for (int i=0; i<m; ++i) {
			int u, v, d; scanf("%d%d%d", &u, &v, &d);
			if (d < dist[u][v] || dist[u][v] < 0) { dist[u][v] = dist[v][u] = d; }
		}

		for (int k=1; k<=n; ++k) { /* floyd */
			for (int i=1; i<=n; ++i) {
				for (int j=i+1; j<=n; ++j) {
					if (dist[i][k] < 0 || dist[k][j] < 0) { continue; }

					int new_dist = dist[i][k] + dist[k][j];
					if (dist[i][j] < 0 || new_dist < dist[i][j]) {
						dist[i][j] = dist[j][i] = new_dist;
					}
				}
			}
		}

		for (int i=1; i<=k; ++i) { scanf("%d %d", &move[i][0], &move[i][1]); }

		cost[0][0] = cost[0][1] = cost[0][3] = -1;
		cost[0][2] = 0;
		move[0][0] = move[0][1] = 1;

		for (int i=1; i<=k; ++i) {
			cost[i][0] = -1;
			if (dist[move[i-1][1]][move[i][0]] >= 0 && cost[i-1][2] >= 0) {
				cost[i][0] = dist[move[i-1][1]][move[i][0]] + cost[i-1][2];
			}

			cost[i][1] = -1;
			if (dist[move[i][0]][move[i-1][1]] >= 0 && cost[i-1][3] >= 0) {
				cost[i][1] = dist[move[i][0]][move[i-1][1]] + cost[i-1][3];
			}

			cost[i][2] = -1;
			if (dist[move[i][0]][move[i][1]] >= 0 && cost[i][0] >= 0) {
				cost[i][2] = dist[move[i][0]][move[i][1]] + cost[i][0];
			}
			if (dist[move[i-1][1]][move[i][1]] >= 0 && cost[i][1] >= 0) {
				int v = dist[move[i-1][1]][move[i][1]] + cost[i][1];
				if (cost[i][2] < 0 || v < cost[i][2]) { cost[i][2] = v; }
			}

			cost[i][3] = -1;
			if (i == k) { break; }
			if (dist[move[i][0]][move[i+1][0]] >= 0 && cost[i][0] >= 0) {
				cost[i][3] = dist[move[i][0]][move[i+1][0]] + cost[i][0];
			}
			if (dist[move[i-1][1]][move[i+1][0]] >= 0 && cost[i][1] >= 0) {
				int v = dist[move[i-1][1]][move[i+1][0]] + cost[i][1];
				if (cost[i][3] < 0 || v < cost[i][3]) { cost[i][3] = v; }
			}
		}

		printf("Case #%d: %d\n", t, cost[k][2]);
	}

	return 0;
}
