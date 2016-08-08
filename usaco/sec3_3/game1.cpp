/*
ID: cenhao11
PROG: game1
LANG: C++11
*/

/* This problem is all about finding the optimal solution starting with
 * length 1.
 *
 * For board length = 1,
 * first player always win by picking the the only value.
 *
 * For board length = 2,
 * first player should pick the larger value.
 * For board length = 3,
 * first player picks the larger value between v[1] and v[3],
 * then the second user picks the larger one in the rest. If dp[i][j] is the
 * largest value first play can win with values [i, .., i+j], then dp[i][2]
 * should be max(v[i] + min(v[i+1], v[i+2]), v[i+2] + min(v[i], v[i+1])). This
 * can be converted to dp[i][2] = max(sum(i, 2) - dp[i][1], sum(i, 2) - dp[i+1][1]).
 * for sum(i, 2) - dp[i][1], it means first player choosing v[i+2], and second 
 * player pick the larger value in (v[i], v[i+1]).
 *
 * So if we continues, for board length = n, the answer would be for the first player
 * to pick the larger value in (v[1], v[n]), and let the second to do his best. So
 * a similar formula applies: dp[i][j] = sum(i+j) - min(dp[i][j-1], dp[i+1][j-1])
 *
 * Hence we have the answer.
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXN 100

int board[MAXN];
int dp[MAXN][MAXN];
int sum[MAXN];

void process(int n) {
	memset(dp, 0, sizeof(dp));
	for (int i=0; i<n; ++i) {
		dp[i][0] = sum[i] = board[i];
	}

	for (int i=1; i<n; ++i) {
		for (int j=n-i-1; j>=0; --j) {
			sum[j] += board[j+i];
			dp[j][i] = sum[j] - min(dp[j][i-1], dp[j+1][i-1]);
		}
	}
}

int main() {
	freopen("game1.in", "r", stdin);
	freopen("game1.out", "w", stdout);

	int n, sum = 0;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &board[i]);
		sum += board[i];
	}

	process(n);
	printf("%d %d\n", dp[0][n-1], sum-dp[0][n-1]);
	return 0;
}
