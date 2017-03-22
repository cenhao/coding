#include <bits/stdc++.h>
using namespace std;

#define MAXN 50
#define INF 100000

const int adj[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
const int len[3] = { 1, 2, 3 };

int dp[3][3][MAXN+1][MAXN+1][MAXN+1][3];

int dfs(int x, int y, int a, int b, int c, int d) {
	if (a < 0 || b < 0 || c < 0) { return INF; }
	if (a+b+c == 0) { return 0; }
	if (dp[x][y][a][b][c][d] != -1) { return dp[x][y][a][b][c][d]; }

	dp[x][y][a][b][c][d] = INF;

	int aa = a-adj[x][0], bb = b-adj[x][1], cc = c-adj[x][2];
	for (int i=0; i<3; ++i) {
		int dist = max(len[x], len[i]);
		if (dist == d) { continue; }

		int tmp;
		if (dist < d) {
			tmp = dfs(i, y, aa, bb, cc, d-dist-1)+dist+1;
		} else {
			tmp = dfs(y, i, aa, bb, cc, dist-d-1)+d+1;
		}

		dp[x][y][a][b][c][d] = min(dp[x][y][a][b][c][d], tmp);
	}

	return dp[x][y][a][b][c][d];
}

int main() {
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<3; ++i) {
		dp[0][0][1][0][0][i] = 1;
		dp[1][0][0][1][0][i] = 1;
		dp[2][0][0][0][1][i] = 1;
	}

	int q; scanf("%d", &q);
	while (q--) {
		int n, m, k; scanf("%d %d %d", &n, &m, &k);
		int mn = INF;

		for (int i=0; i<3; ++i) {
			for (int j=0; j<3; ++j) {
				for (int d=0; d<3; ++d) {
					mn = min(mn, dfs(i, j, n, m, k, d));
				}
			}
		}

		printf("%d\n", mn);
	}

	return 0;
}
