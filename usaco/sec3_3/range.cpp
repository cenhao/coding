/*
ID: cenhao11
PROG: range
LANG: C++11
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
 * DP
 * dp[i][j][0] is the longest row of consecutive 1s that ends with (i, j)
 * dp[i][j][1] is the longest col of consecutive 1s that ends with (i, j)
 * dp[1][j][2] is the largest square of 1s that the bottom right is (i, j)
 *
 * Then we have:
 * dp[i][j][0] = dp[i][j-1][0] + 1;
 * dp[i][j][1] = dp[i-1][j][1] + 1;
 * dp[i][j][2] = min(dp[i-1][j][0], dp[i][j-1][1], dp[i-1][j-1][2]) + 1;
 */

#define MAXN 250

int dp[MAXN+1][MAXN+1][3]; // 0 for backward, 1 for upward, 2 for sub-square
int cnt[MAXN+1];

int main() {
	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);

	int n;
	char input[MAXN+2];
	memset(dp, 0, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));

	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%s", &input[1]);

		for (int j=1; j<=n; ++j) {
			if (input[j] == '1') {
				dp[i][j][0] = dp[i][j-1][0] + 1;
				dp[i][j][1] = dp[i-1][j][1] + 1;
				dp[i][j][2] =
					min(dp[i][j][0], min(dp[i][j][1], dp[i-1][j-1][2]+1));
			} else {
				dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 0;
			}

			++cnt[dp[i][j][2]];
		}
	}

	int sum = 0;
	for (int i=2; i<=n; ++i) { sum += cnt[i]; }
	for (int i=2; i<=n && sum > 0; ++i) {
		printf("%d %d\n", i, sum);
		sum -= cnt[i];
	}

	return 0;
}
