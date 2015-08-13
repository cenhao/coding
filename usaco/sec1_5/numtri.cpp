/*
ID: cenhao11
PROG: numtri
LANG: C++11
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXR 1005
int dp[2][MAXR];

int main() {
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
	memset(dp, 0, sizeof(dp));

	int r, n;
	scanf("%d", &r);
	for (int i=1; i<=r; ++i) {
		int cur = i & 1;
		int last = (i-1) & 1;
		for (int j=1; j<=i; ++j) {
			scanf("%d", &n);
			dp[cur][j] = max(dp[last][j-1] + n, dp[last][j] + n);
		}
	}

	int cur = r & 1;
	int mx = -1;
	for (int i=1; i<=r; ++i) {
		mx = (mx < dp[cur][i]) ? dp[cur][i] : mx;
	}

	printf("%d\n", mx);
	return 0;
}
