#include <bits/stdc++.h>
using namespace std;

#define MAXNM 4000000
#define INF (MAXNM * 250 + 1)
int mat[MAXNM];
int row_lmx[MAXNM], row_rmx[MAXNM];
int dp[MAXNM];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) {
		int b = i * m;
		for (int j=0; j<m; ++j) { scanf("%d", &mat[b+j]); }
		int mx = 0;
		for (int j=0; j<m; ++j) {
			row_lmx[b+j] = mx;
			mx = max(0, mx+mat[b+j]);
		}
		mx = 0;
		for (int j=m-1; j>=0; --j) {
			row_rmx[b+j] = mx;
			mx = max(0, mx+mat[b+j]);
		}
	}

	memset(dp, 0, sizeof(dp));
	for (int i=0; i<n; ++i) {
		int b = i * m, pb = (i != 0) ? (i-1)*m : -1;
		for (int j=0; j<m; ++j) {
			int v = (pb < 0) ? 0 : dp[pb+j];
			dp[b+j] = v + mat[b+j] + row_lmx[b+j] + row_rmx[b+j];
		}

		int mx = -INF;
		for (int j=0; j<m; ++j) {
			dp[b+j] = max(dp[b+j], mx+mat[b+j]+row_rmx[b+j]);
			int v = (pb < 0) ? 0 : dp[pb+j];
			mx = max(v+mat[b+j]+row_lmx[b+j], mx+mat[b+j]);
		}

		mx = -INF;
		for (int j=m-1; j>=0; --j) {
			dp[b+j] = max(dp[b+j], mx+mat[b+j]+row_lmx[b+j]);
			int v = (pb < 0) ? 0 : dp[pb+j];
			mx = max(v+mat[b+j]+row_rmx[b+j], mx+mat[b+j]);
		}
	}

	int b = (n-1) * m;
	int ans = dp[b];
	for (int i=1; i<m; ++i) { ans = max(ans, dp[b+i]); }
	printf("%d\n", ans);
	return 0;
}
