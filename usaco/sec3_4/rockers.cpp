/*
ID: cenhao11
PROG: rockers
LANG: C++11
*/

/*
 * DP: dp[n][m][t] = max(dp[k][m][t+records[n]], dp[k][m+1][0]) + 1
 * where k = n+1 ~ N
 */

#include <stdio.h>
#include <string.h>

#include <algorithm>
using namespace std;

#define MAXN 20
#define MAXM 20
#define MAXT 20

int n, m, t;
int dp[MAXN][MAXM][MAXT+1];
int records[MAXN];

int dfs(int sn, int sm, int st) {
	if (sm >= m) { return 0; }
	if (dp[sn][sm][st] >= 0) { return dp[sn][sm][st]; }

	if (st+records[sn] > t) {
		dp[sn][sm][st] = 0;
	} else {
		int tmp;
		int mx = 0;
		for (int i=sn+1; i<n; ++i) {
			tmp = dfs(i, sm, st+records[sn]);
			if (tmp <= 0) {
				tmp = dfs(i, sm+1, 0);
			}

			mx = max(mx, tmp);
		}

		dp[sn][sm][st] = 1 + mx;
	}

	return dp[sn][sm][st];
}

int process() {
	memset(dp, -1, sizeof(dp));
	int mx = 0;
	for (int i=0; i<n; ++i) {
		mx = max(mx, dfs(i, 0, 0));
	}

	return mx;
}

int main() {
	freopen("rockers.in", "r", stdin);
	freopen("rockers.out", "w", stdout);

	scanf("%d %d %d", &n, &t, &m);
	for (int i=0; i<n; ++i) { scanf("%d", &records[i]); }
	printf("%d\n", process());
	return 0;
}
