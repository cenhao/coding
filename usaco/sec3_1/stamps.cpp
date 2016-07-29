/*
ID: cenhao11
PROG: stamps
LANG: C++11
*/

#include <stdio.h>
#include <string.h>

#define MAXN 50
#define MAXK 200
#define MAXS 10000

int dp[MAXK * MAXS + 1];
int stamps[MAXN];

int main() {
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	int n, k, mx = 0;
	scanf("%d %d", &k, &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &stamps[i]);
		mx = (mx < stamps[i]) ? stamps[i] : mx;
	}

	int end = mx * k;
	for (int i=0; i<n; ++i) {
		for (int j=stamps[i]; j<=end; ++j) {
			int idx = j - stamps[i];
			if (dp[idx] >= 0 && dp[idx] < k &&
					(dp[j] == -1 || dp[j] > dp[idx]+1)) {
				dp[j] = dp[idx] + 1;
			}
		}
	}

	mx = 0;
	for (int i=0; i<=end && dp[i]>=0; ++i) {
		mx = i;
	}

	printf("%d\n", mx);
	return 0;
}
