#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXM 1000

int f[MAXN+1], w[MAXN+1], letters[MAXM];
int dp[MAXM][MAXN+1];

int find(int x) {
	if (f[f[x]] != f[x]) { f[x] = find(f[x]); }
	return f[x];
}

void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (w[fx] >= w[fy]) {
		f[fy] = fx; w[fx] += w[fy];
	} else {
		f[fx] = fy; w[fy] += w[fx];
	}
}

int main() {
	int n, k, m; scanf("%d %d %d", &n, &k, &m);
	for (int i=1; i<=n; ++i) { f[i] = i; w[i] = 1; }
	for (int i=0; i<k; ++i) {
		int x, y; scanf("%d %d", &x, &y);
		merge(x, y);
	}

	for (int i=0; i<m; ++i) {
		scanf("%d", &letters[i]);
		letters[i] = find(letters[i]);
	}

	for (int i=0; i<m; ++i) { dp[i][0] = 0; dp[i][1] = 1; }
	for (int i=2; i<=m; ++i) {
		for (int j=0, end=m-i; j<=end; ++j) {
			if (letters[j] == letters[j+i-1]) {
				dp[j][i] = 2+dp[j+1][i-2];
			} else {
				dp[j][i] = max(dp[j][i-1], dp[j+1][i-1]);
			}
		}
	}

	printf("%d\n", dp[0][m]);
	return 0;
}
