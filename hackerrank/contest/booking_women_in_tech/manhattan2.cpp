#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define MAXT 1000

const int dir[5][2] = { {0, 0}, {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

int dp[MAXN+2][MAXN+2][MAXT+1];
int candy[MAXN+2][MAXN+2];

struct State {
	int x, y, t, tot;
};

int main() {
	memset(dp, -1, sizeof(dp));
	memset(candy, 0, sizeof(candy));

	int n, m, T; scanf("%d %d %d", &n, &m, &T);
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) { scanf("%d", &candy[i][j]); }
	}

	dp[1][1][0] = candy[1][1];

	for (int t=1; t<=T; ++t) {
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=m; ++j) {
				for (int k=0; k<5; ++k) {
					int x = i-dir[k][0], y = j-dir[k][1], tt = t-1;
					if (dp[x][y][tt] >= 0) {
						dp[i][j][t] = max(dp[i][j][t], dp[x][y][tt]+candy[i][j]);
					}
				}
			}
		}
	}

	int mx = -1; for (int t=0; t<=T; ++t) { mx = max(mx, dp[n][m][t]); }
	if (mx < 0) {
		printf("Too late\n");
	} else {
		printf("%d\n", mx);
	}

	return 0;
}
