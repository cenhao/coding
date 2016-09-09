#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXM 100000

int dp[MAXM+1];

int main() {
	int n, m, need, val;
	scanf("%d %d", &n, &m);
	memset(dp, 0, sizeof(dp));

	for (int i=0; i<n; ++i) {
		scanf("%d %d", &need, &val);
		for (int i2=need; i2<=m; ++i2) {
			dp[i2] = max(dp[i2], dp[i2-need] + val);
		}
	}

	printf("%d\n", dp[m]);
	return 0;
}
