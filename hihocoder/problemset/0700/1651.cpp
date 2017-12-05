#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
#define MOD 1000000007

int dp[MAXN+1][MAXN], pre[MAXN];

int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);

	int presum = 1;
	for (int i=1; i<=n; ++i) {
		for (int j=0; j<m; ++j) {
			dp[i][j] = presum - pre[j];
			if (dp[i][j] < 0) { dp[i][j] += MOD; }
			pre[j] = (pre[j] + dp[i][j]) % MOD;
			if (i-k+1>=1) {
				pre[j] -= dp[i-k+1][j];
				if (pre[j] < 0) { pre[j] += MOD; }
			}
		}

		presum = 0;
		for (int j=0; j<m; ++j) {
			presum = (presum + pre[j]) % MOD;
		}
	}

	printf("%d\n", presum);
	return 0;
}
