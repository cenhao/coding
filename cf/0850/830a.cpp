#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
#define MAXK 2000

int dp[MAXN+1][MAXK+1], a[MAXN+1], b[MAXK+1];

int main() {
	int n, k, p; scanf("%d%d%d", &n, &k, &p);
	for (int i=1; i<=n; ++i) { scanf("%d", &a[i]); }
	for (int i=1; i<=k; ++i) { scanf("%d", &b[i]); }
	sort(a+1, a+n+1);
	sort(b+1, b+k+1);
	memset(dp, 0x7f, sizeof(dp));
	memset(dp[0], 0, sizeof(dp[0]));
	for (int i=1; i<=n; ++i) {
		for (int j=i; j<=k-n+i; ++j) {
			int dist = max(dp[i-1][j-1], abs(p-b[j])+abs(b[j]-a[i]));
			dp[i][j] = min(dist, dp[i][j-1]);
		}
	}

	printf("%d\n", dp[n][k]);
	return 0;
}
