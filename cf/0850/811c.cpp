#include <bits/stdc++.h>
using namespace std;

#define MAXN 5000

int lend[MAXN+1];
int rend[MAXN+1];
int a[MAXN+1];
int dp[MAXN];
int vis[MAXN+1];

int main() {
	memset(lend, 0x7f, sizeof(lend));
	memset(rend, -1, sizeof(rend));
	memset(dp, 0, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &a[i]);
		lend[a[i]] = min(lend[a[i]], i);
		rend[a[i]] = max(rend[a[i]], i);
	}

	for (int i=1; i<=n; ++i) {
		bool invalid = false;
		int val = 0, rmx = -1;
		for (int j=i; j<=n; ++j) {
			if (lend[a[j]] < i) { invalid = true; }

			dp[j] = max(dp[j], dp[j-1]);
			if (invalid) {
				dp[j] = max(dp[j], dp[i-1]);
			} else {
				if (vis[a[j]] != i) {
					vis[a[j]] = i;
					val ^= a[j];
				}
				rmx = max(rmx, rend[a[j]]);
				if (j == rmx) {
					dp[j] = max(dp[j], dp[i-1] + val);
				}
			}
		}
	}

	printf("%d\n", dp[n]);
	return 0;
}
