/*
 * here dp is for when the value of each combination is no less than
 * the index, with last as the last color.
 *
 * With a given last color, it's important to under stand that the 
 * current combination of color doesn't matter any more. so that
 * we can go from the last color to generate more conbination of
 * colors.
 */
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAXN 100000

int c[MAXN+1][61];
int dp[11][11][11][11][11][11][3];
int lim[6];

void init() {
	memset(c, -1, sizeof(c));
	memset(dp, -1, sizeof(dp));
}

int comb(int n, int m) {
	if (n <= m || m == 0) { return 1; }
	if (c[n][m] >= 0) { return c[n][m]; }
	c[n][m] = (comb(n-1, m-1) + comb(n-1, m)) % MOD;
	return c[n][m];
}

int dfs(int rb, int rg, int br, int bg, int gr, int gb, int last, int n) {
	if (dp[rb][rg][br][bg][gr][gb][last] != -1) {
		return dp[rb][rg][br][bg][gr][gb][last];
	}

	int len = rb+rg+br+bg+gr+gb+1;
	if (len > n) { return dp[rb][rg][br][bg][gr][gb][last] = 0; }

	int res = comb(n-1, len-1);

	if (last == 0) { // r
		if (rb < lim[0]) { // add b
			res = (res + dfs(rb+1, rg, br, bg, gr, gb, 1, n)) % MOD;
		}
		if (rg < lim[1]) {
			res = (res + dfs(rb, rg+1, br, bg, gr, gb, 2, n)) % MOD;
		}
	} else if (last == 1) { // b
		if (br < lim[2]) { // add r
			res = (res + dfs(rb, rg, br+1, bg, gr, gb, 0, n)) % MOD;
		}
		if (bg < lim[3]) { // add g
			res = (res + dfs(rb, rg, br, bg+1, gr, gb, 2, n)) % MOD;
		}
	} else { // g
		if (gr < lim[4]) { // add r
			res = (res + dfs(rb, rg, br, bg, gr+1, gb, 0, n)) % MOD;
		}
		if (gb < lim[5]) { // add b
			res = (res + dfs(rb, rg, br, bg, gr, gb+1, 1, n)) % MOD;
		}
	}

	dp[rb][rg][br][bg][gr][gb][last] = res;
	return res;
}

int main() {
	init();
	int n; scanf("%d", &n);
	for (int i=0; i<6; ++i) { scanf("%d", &lim[i]); }

	int res = 0;
	for (int i=0; i<3; ++i) {
		res = (res + dfs(0, 0, 0, 0, 0, 0, i, n)) % MOD;
	}

	printf("%d\n", res);
	return 0;
}
