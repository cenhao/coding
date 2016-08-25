/*
 * If not the circular shape of the problem, that the boards are
 * put in a line, this problem can be solve by a simple DP.
 *
 * To cover the scenarios that goes back a circle, one way is to
 * shift the boards by one, and to cover all posiblities, we will
 * have to shift L times. So the complexity is O(LMN)
 *
 * This would work if L is small.
 *
 * A better solution would be binary searching the possible number,
 * and try it out if that can be solution. For that it has to shift
 * L times at most, and for each shift it takes at most N to check,
 * so complexity for this would O(LN*logN)
 */

#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 1000
#define MAXM 1000

int n, m, l;
int dp[MAXN+1][MAXM+1];
int board[MAXN+1];

void shift() {
	int tmp = board[n];
	for (int i=n-1; i>0; --i) { board[i+1] = board[i]; }
	board[1] = tmp;
}

int process() {
	int ans = 0;

	for (int lv=0; lv<l; ++lv) {
		memset(dp, 0x7f, sizeof(dp));

		for (int lv2=1; lv2<=n; ++lv2) {
			int pre = max(0, lv2-l);
			for (int lv3=0; lv3<=m; ++lv3) {
				if (lv3 == 0) {
					dp[lv2][lv3] = min(board[lv2], dp[lv2-1][0]);
				} else {
					dp[lv2][lv3] = max(dp[pre][lv3-1], min(board[lv2], dp[lv2-1][lv3]));
				}
			}
		}

		ans = max(dp[n][m], ans);
		shift();
	}

	return ans;
}

int main() {
	scanf("%d%d%d", &n, &m, &l);
	for (int i=1; i<=n; ++i) { scanf("%d", &board[i]); }
	printf("%d\n", process());
	return 0;
}
