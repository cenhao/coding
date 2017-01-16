#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 300
#define MAXM 300

int dp[MAXN+1];
int ddp[MAXN+1][MAXN+1];

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int n, m; scanf("%d%d", &n, &m);

		memset(ddp, -1, sizeof(ddp));
		ddp[0][0] = ddp[1][0] = 0;
		int cur, pre;
		for (int i=0; i<n; ++i) {
			memset(dp, -1, sizeof(dp)); dp[0] = 0;
			for (int j=0; j<m; ++j) {
				int v; scanf("%d", &v);

				for (int k=j+1; k>0; --k) {
					if (dp[k-1] < 0) { continue; }

					int cost = k*k - (k-1)*(k-1) + v;
					if (dp[k] < 0) {
						dp[k] = dp[k-1] + cost;
					} else {
						dp[k] = min(dp[k], dp[k-1]+cost);
					}
				}
			}

			cur = i & 1, pre = (cur+1) & 1;
			for (int j=0; j<=n; ++j) { ddp[cur][j] = ddp[pre][j]; }
			for (int j=1; j<=m; ++j) {
				for (int k=n; k-j>=i; --k) { // will need at least (i+1) pie by (i+1)th day
					if (ddp[pre][k-j] < 0) { continue; }
					if (ddp[cur][k] < 0) {
						ddp[cur][k] = ddp[pre][k-j] + dp[j];
					} else {
						ddp[cur][k] = min(ddp[cur][k], ddp[pre][k-j]+dp[j]);
					}
				}
			}
		}

		printf("Case #%d: %d\n", t, ddp[cur][n]);
	}

	return 0;
}
