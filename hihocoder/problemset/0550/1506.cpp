#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

double dp[MAXN+1][MAXN+1];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	memset(dp, 0, sizeof(dp));

	dp[0][0] = 1;
	for (int i=1; i<=n; ++i) {
		double p; scanf("%lf", &p);
		dp[i][0] = dp[i-1][0] * (1-p);
		for (int j=1, end=min(i, m); j<=end; ++j) {
			dp[i][j] = dp[i-1][j] * (1-p) + dp[i-1][j-1] * p;
		}
	}

	printf("%lf\n", dp[n][m]);
	return 0;
}
