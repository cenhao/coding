/*
ID: cenhao11
PROG: kimbits
LANG: C++11
*/

#include <stdio.h>
#include <string.h>

#define MAXN 31

int comb[MAXN+1][MAXN+1];

int getComb(int n, int m) {
	if (comb[n][m] != -1) {
		return comb[n][m];
	}

	if (m > n) {
		comb[n][m] = 0;
	} else if (n == 1 || m == 0) {
		comb[n][m] = 1;
	} else {
		comb[n][m] = getComb(n-1, m) + getComb(n-1, m-1);
	}

	return comb[n][m];
}

int dp[MAXN+1][MAXN+1];

void preprocess(int n, int l) {
	memset(comb, -1, sizeof(comb));
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<=l; ++i) { dp[0][i] = 1; }
	for (int i=1; i<=n; ++i) {
		dp[i][0] = 0;
		for (int j=1; j<=l; ++j) {
			dp[i][j] = dp[i][j-1] + getComb(i-1, j-1);
		}
	}
}

int find(unsigned int aim, unsigned int sum, int n, int l) {
	for (int i=0; i<=n; ++i) {
		sum += dp[i][l];

		if (sum >= aim) {
			if (i == 0) { return 0; }
			int res =find(aim - (sum-dp[i][l]), 0U, i-1, l-1);
			res |= 1 << (i-1);
			return res;
		}
	}

	return 0;
}

int main() {
	freopen("kimbits.in", "r", stdin);
	freopen("kimbits.out", "w", stdout);

	int n, l;
	unsigned int aim;
	scanf("%d %d %u", &n, &l, &aim);

	preprocess(n, l);
	int res = find(aim, 0U, n, l);

	for (int i=n-1; i>=0; --i) {
		printf("%c", (res & (1<<i)) ? '1' : '0');
	}

	printf("\n");
	return 0;
}

