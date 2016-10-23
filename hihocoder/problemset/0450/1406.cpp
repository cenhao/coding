#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 200
#define INF 0x7fff0000

int dp[MAXN+1][MAXN+1];

int main() {
	int n; scanf("%d", &n);
	memset(dp, 0, sizeof(dp));

	for (int i=2; i<=n; ++i) {
		for (int i1=1, end=n-i+1; i1<=end; ++i1) {
			dp[i1][i] = INF;
			for (int i2=0; i2<i; ++i2) {
				int v = i1+i2 + max(dp[i1][i2], dp[i1+i2+1][i-i2-1]);
				dp[i1][i] = min(dp[i1][i], v);
			}
		}
	}

	printf("%d\n", dp[1][n]);
	return 0;
}
