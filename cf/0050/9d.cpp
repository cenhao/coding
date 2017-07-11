#include <bits/stdc++.h>
using namespace std;

#define MAXN 35

int64_t dp[MAXN+1][MAXN+1];

int main() {
	memset(dp, 0, sizeof(dp));
	int n, h; scanf("%d%d", &n, &h);
	dp[0][0] = 1LL;
	for (int i=1; i<=n; ++i) { // # of nodes
		for (int j=1; j<=i; ++j) { // root node
			int l = j-1, r = i-j;
			int ls = (l==0) ? 0 : (log2(l)+1);
			int rs = (r==0) ? 0 : (log2(r)+1);
			for (int lh=ls; lh<=l; ++lh) {
				for (int rh=rs; rh<=r; ++rh) {
					int mxh = max(lh, rh) + 1;
					dp[i][mxh] += dp[l][lh] * dp[r][rh];
				}
			}
		}
	}

	int64_t ans = 0;
	for (int i=h; i<=n; ++i) { ans += dp[n][i]; }
	printf("%" PRId64 "\n", ans);
	return 0;
}
