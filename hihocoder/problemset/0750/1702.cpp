#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define MAXT 17
int a[MAXN+1][MAXN+1];
int dp[MAXN+1][MAXN+1][MAXT][2];

int main() {
	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) { scanf("%d", &a[i][j]); }
	}

	memset(dp, -1, sizeof(dp));
	dp[1][0][0][0] = dp[0][1][0][1] = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			for (int k=0, end=min(MAXT, min(i, j)); k<end; ++k) {
				if (dp[i][j-1][k][0]>=0 && (dp[i][j][k][0]==-1 || dp[i][j-1][k][0]+a[i][j]<dp[i][j][k][0])) {
						dp[i][j][k][0] = dp[i][j-1][k][0]+a[i][j];
				}
				if (dp[i-1][j][k][1]>=0 && (dp[i][j][k][1]==-1 || dp[i-1][j][k][1]+a[i][j]<dp[i][j][k][1])) {
					dp[i][j][k][1] = dp[i-1][j][k][1]+a[i][j];
				}

				if (k == 0) { continue; }
				if (dp[i-1][j][k-1][0]>=0 && (dp[i][j][k][1]==-1 || dp[i-1][j][k-1][0]+a[i][j]+(1<<(k-1))<dp[i][j][k][1])) {
					dp[i][j][k][1] = dp[i-1][j][k-1][0]+a[i][j]+(1<<(k-1));
				}
				if (dp[i][j-1][k-1][1]>=0 && (dp[i][j][k][0]==-1 || dp[i][j-1][k-1][1]+a[i][j]+(1<<(k-1))<dp[i][j][k][0])) {
					dp[i][j][k][0] = dp[i][j-1][k-1][1]+a[i][j]+(1<<(k-1));
				}
			}
		}
	}

	int mn = -1;
	for (int i=0; i<MAXT; ++i) {
		if (mn == -1 || (dp[n][n][i][0]>=0 && dp[n][n][i][0] < mn)) { mn = dp[n][n][i][0]; }
		if (mn == -1 || (dp[n][n][i][1]>=0 && dp[n][n][i][1] < mn)) { mn = dp[n][n][i][1]; }
	}

	printf("%d\n", mn);
	return 0;
}
