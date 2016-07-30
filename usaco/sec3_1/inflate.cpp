/*
ID: cenhao11
PROG: inflate
LANG: C++11
*/

/*
 * Time complexity is O(m^2), don't know why this can pass...
 */

#include <stdio.h>
#include <string.h>

#define MAXM 10000

int dp[MAXM + 1];

int main()
{
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);

	int m, n;
	scanf("%d%d", &m, &n);
	memset(dp, 0, sizeof(dp));

	int score, minute, tmp;
	for (int i=0; i<n; ++i) {
		scanf("%d %d", &score, &minute);
		for (int j=minute; j<=m; ++j) {
			tmp = dp[j-minute] + score;
			dp[j] = (dp[j] < tmp) ? tmp : dp[j];
		}
	}

	printf("%d\n", dp[m]);
	return 0;
}

