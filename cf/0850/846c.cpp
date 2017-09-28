#include <bits/stdc++.h>
using namespace std;

#define MAXN 5000

int64_t dp[4][MAXN];
int pick[4][MAXN];

int main() {
	int n; scanf("%d", &n);
	int64_t sum = 0LL;
	for (int i=0; i<n; ++i) {
		int v; scanf("%d", &v);
		sum += v;
		dp[0][i] = sum;
	}

	const int adj[4] = { 1, -1, 1, -1 };
	for (int i=1; i<4; ++i) {
		for (int j=0; j<n; ++j) {
			dp[i][j] = adj[i] * dp[0][j];
			pick[i][j] = -1;
			for (int k=0; k<=j; ++k) {
				int64_t v = dp[i-1][k] + adj[i] * (dp[0][j]-dp[0][k]);
				if (v > dp[i][j]) {
					pick[i][j] = k;
					dp[i][j] = v;
				}
			}
		}
	}

	int ans[3];
	for (int i=3, pos=n-1; i>=1; --i) {
		if (pos == -1) {
			ans[i-1] = 0;
		} else {
			ans[i-1] = pick[i][pos] + 1;
			pos = pick[i][pos];
		}
	}

	printf("%d %d %d\n", ans[0], ans[1], ans[2]);
	return 0;
}
