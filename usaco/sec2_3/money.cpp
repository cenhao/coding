/*
ID: cenhao11
PROG: money
LANG: C++11
*/

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXN 10000
#define MAXV 25

int64_t dp[MAXN+1];

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);

	int n, v, c;
	scanf("%d %d", &v, &n);
	memset(dp, 0, sizeof(dp));
	dp[0] = 1LL;
	for (int i=0; i<v; ++i) {
		scanf("%d", &c);
		for (int j=c; j<=n; ++j) {
			dp[j] += dp[j-c];
		}
	}

	printf("%" PRId64 "\n", dp[n]);
	return 0;
}
