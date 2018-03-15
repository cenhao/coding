#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define MAXK 900
int a[MAXN], fc[MAXN], tc[MAXN];
int dp[MAXN+1][MAXN+1][MAXK+1];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) {
		scanf("%d", &a[i]);
		int tmp = a[i], f = 0, t = 0;
		while (tmp % 2 == 0) {
			tmp /= 2; ++t;
		}
		while (tmp % 5 == 0) {
			tmp /= 5; ++f;
		}
		fc[i] = f; tc[i] = t;
	}

	memset(dp, -1, sizeof(dp));
	for (int i=0; i<=n; ++i) { dp[i][0][0] = 0; }
	for (int i=1; i<=n; ++i) {
		for (int j=1, jend=min(m, i); j<=jend; ++j) {
			for (int k=0, kend=MAXK-fc[i-1]; k<=kend; ++k) {
				dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
				if (dp[i-1][j-1][k] == -1) { continue; }
				int tmp = dp[i-1][j-1][k] + tc[i-1];
				if (dp[i][j][k+fc[i-1]] == -1 || tmp > dp[i][j][k+fc[i-1]]) {
					dp[i][j][k+fc[i-1]] = tmp;
				}
			}
		}
	}
	int mx = -1;
	for (int i=0; i<=MAXK; ++i) {
		mx = max(mx, min(i, dp[n][m][i]));
	}

	printf("%d\n", mx);
	return 0;
}
