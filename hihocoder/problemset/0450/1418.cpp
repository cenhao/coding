#include <stdio.h>
#include <string.h>

#define MAXN 100
#define MAXS 100000
#define MOD 1000000007

int a[MAXN+1];
int dp[MAXN+1][2*MAXS+1];

int dfs(int cur, int target, int end) {
	int ot = target + MAXS;
	if (dp[cur][ot] >= 0) { return dp[cur][ot]; }
	if (cur == end) {
		if (target == a[cur]) {
			dp[cur][ot] = 1;
		} else {
			dp[cur][ot] = 0;
		}
	} else {
		dp[cur][ot] = (dfs(cur+1, target-a[cur], end) +
				dfs(cur+1, a[cur]-target, end)) % MOD;
	}

	return dp[cur][ot];
}

int main() {
	int n, s; scanf("%d%d", &n, &s);
	for (int i=1; i<=n; ++i) { scanf("%d", &a[i]); }
	a[0] = 0;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", dfs(0, s, n));
	return 0;
}
