#include <bits/stdc++.h>
using namespace std;

#define MAXN 250

int sum[MAXN+1][MAXN+1];

int main() {
	int n, m, K; scanf("%d %d %d", &n, &m, &K);
	memset(sum, 0, sizeof(sum));

	int v;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			scanf("%d", &v);
			sum[i][j] = -sum[i-1][j-1] + sum[i][j-1] + sum[i-1][j] + v;
		}
	}

	int mx = -1;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			int x = i, y = m;
			while (x <= n && y >= j) {
				int s = sum[x][y] - sum[x][j-1] - sum[i-1][y] + sum[i-1][j-1];
				if (s <= K) {
					mx = max(mx, (x-i+1) * (y-j+1));
					++x;
				} else {
					--y;
				}
			}
		}
	}

	printf("%d\n", mx);
	return 0;
}
