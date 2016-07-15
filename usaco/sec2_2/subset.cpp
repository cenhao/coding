/*
ID: cenhao11
PROG: subset
LANG: C++11
*/

#include <stdio.h>
#include <string.h>

#define MAXN 39
#define MAXSIZE ((((1+MAXN) * MAXN) >> 1) >> 1) /* (1 + 39) * 39 / 2 / 2 */

unsigned int dp[MAXSIZE + 1];

void process(int n, int target) {
	memset(dp, 0, sizeof(dp));
	dp[0] = 1U;

	for (int i=1; i<=n; ++i) {
		for (int j=target-i; j>=0; --j) {
			dp[j+i] += dp[j];
		}
	}
}

int main() {
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);

	int n;
	scanf("%d", &n);

	int sum = ((1+n) * n) >> 1;

	if (sum & 1) {
		printf("0\n");
	} else {
		int target = sum >> 1;
		process(n, target);
		printf("%d\n", dp[target] >> 1);
	}

	return 0;
}
