/*
ID: cenhao11
PROG: nocows
LANG: C++11
*/

/*
 * My original idea is a way less efficent DP.
 * while dp[i][j][k] stands for a the i-th layer, the entire tree with j nodes,
 * and the only k nodes in the i-th layer.
 * The state transform equation will be:
 * dp[i][j][k] = sum(dp[i-1][j-k][L] * comb(L, k)) where L >= k / 2
 * so to calculate a dp[i][j][k] will require O(n),
 * and going down one layer requires O(n^2). so the the overall time complexity
 * is O(kn^3).
 *
 * The solution in usaco is much better and only requires O(kn^2)
 */

#include <stdio.h>
#include <string.h>

#define MAXD 200
#define MAXK 100
#define MOD 9901

int dp[2][MAXD+1][MAXD+1];
int combination[MAXD+1][MAXD+1];
int inverse[MAXD+1];

int getInverse(int n) {
	if (inverse[n] < 0) {
		inverse[n] = 1;
		int cur = n;
		int pow = MOD - 2;
		while (pow) {
			if (pow & 1) {
				inverse[n] = (inverse[n] * cur) % MOD;
			}
			pow >>= 1;
			cur = (cur * cur) % MOD;
		}
	}

	return inverse[n];
}

int getCombination(int n, int m) {
	if (combination[n][m] < 0) {
		combination[n][m] = 1;
		for (int i=m+1; i<=n; ++i) {
			combination[n][m] = (combination[n][m] * i) % MOD;
		}
		for (int i=n-m; i>1; --i) {
			combination[n][m] = (combination[n][m] * getInverse(i)) % MOD;
		}
	}

	return combination[n][m];
}

int main() {
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);

	int n, k;
	scanf("%d %d", &n, &k);

	if ((n & 1) == 0) {
		printf("0\n");
		return 0;
	}

	memset(dp, 0, sizeof(dp));
	memset(combination, 0xff, sizeof(combination));
	memset(inverse, 0xff, sizeof(inverse));
	dp[1][3][2] = 1;

	for (int i=2; i<k; ++i) {
		int cur = i & 1;
		int prev = (i - 1) & 1;
		memset(dp[cur], 0, sizeof(dp[cur]));
		for (int j=2*i+1; j<=n; j+=2) {
			for (int x=2*i-1; x<j; x+=2) {
				int left = j - x;
				int req = left / 2;
				for (int y=2; y<x; y+=2) {
					if (y >= req && dp[prev][x][y]) {
						int val = (getCombination(y, req) * dp[prev][x][y]) % MOD;
						dp[cur][j][left] = (dp[cur][j][left] + val) % MOD;
					}
				}
			}
		}
	}

	int res = 0;
	int cur = (k-1) & 1;
	for (int i=2; i<n; i+=2) { res = (res + dp[cur][n][i]) % MOD; }

	printf("%d\n", res);
	return 0;
}
