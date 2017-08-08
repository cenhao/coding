/*
 * This is a combination of LCS and LIS.
 * It's not hard to come up with an O(n^3) algorithm:
 * Let dp[i][j] be the maximum length of using b[j] as the last element in the
 * the sequence, and a[1..i], b[1..j] is used.
 * Do the scanning like LCS, which is O(n^2), and if a[i] == b[j],
 * then try to find a k, where 1. k<j, 2. b[k] < b[j], 3. dp[i-1][k] is maximum,
 * this scanning cost O(n).
 *
 * However this scanning can be optimized to O(1). As we scan each elem in b for
 * each elem in a, a max value can be maintained.
 * Let say we're currently doing the scanning for a[i], and if a[i] == b[j],
 * then we have to find the b[k] < b[j] = a[i], so if in the scanning process,
 * we find a b[j] < a[i], then we can try to update the max value
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 500

int dp[MAXN+1][MAXN+1], pre[MAXN+1][MAXN+1][2];
int a[MAXN+1], b[MAXN+1];
int ans[MAXN+1];

int main() {
	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) { scanf("%d", &a[i]); }
	int m; scanf("%d", &m);
	for (int i=1; i<=m; ++i) { scanf("%d", &b[i]); }

	for (int i=1; i<=n; ++i) {
		int mx = 0, px = 0, py = 0;
		for (int j=1; j<=m; ++j) {
			if (a[i] > b[j] && dp[i-1][j] > mx) { // optimization
				mx = dp[i-1][j];
				px = i-1; py = j;
			}

			if (a[i] == b[j]) {
				dp[i][j] = mx + 1;
				pre[i][j][0] = px; pre[i][j][1] = py;
			} else {
				dp[i][j] = dp[i-1][j];
				pre[i][j][0] = pre[i-1][j][0];
				pre[i][j][1] = pre[i-1][j][1];
			}
		}
	}

	int mx = 0, px, py;
	for (int i=1; i<=m; ++i) {
		if (dp[n][i] > mx) {
			mx = dp[n][i];
			px = n; py = i;
		}
	}

	printf("%d\n", mx);
	if (mx != 0) {
		ans[mx] = -1;
		while (mx--) {
			ans[mx] = b[py];
			int tx = pre[px][py][0], ty = pre[px][py][1];
			px = tx; py = ty;
		}

		for (int i=0; ans[i]!=-1; ++i) {
			if (i != 0) { printf(" "); }
			printf("%d", ans[i]);
		}

		printf("\n");
	}

	return 0;
}
