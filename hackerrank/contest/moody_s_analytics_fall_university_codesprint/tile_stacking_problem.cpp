#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
#define MOD 1000000007

int dp[MAXN+1], tmp[MAXN+1];

int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for (int i=1; i<=m; ++i) {
		int h = 0, r = 0;
		int64_t sum = 0;
		for (int j=1; j<=n; ++j) {
			while (h < j) { sum += dp[h++]; }
			while (r < j-k) { sum -= dp[r++]; }
			tmp[j] = sum % MOD;
		}
		for (int j=1; j<=n; ++j) {
			dp[j] = (dp[j] + tmp[j]) % MOD;
		}
	}

	printf("%d\n", dp[n]);
	return 0;
}
