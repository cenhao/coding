#include <bits/stdc++.h>
using namespace std;

#define MAXN 5000

int a[MAXN], sa[MAXN];
int64_t dp[2][MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &a[i]);
		sa[i] = a[i];
	}

	sort(sa, sa+n);
	memset(dp, 0, sizeof(dp));

	for (int i=0; i<n; ++i) {
		int cur = i & 1, pre = (i + 1) & 1;
		int64_t mn = 0x7fffffffffffffffLL;
		for (int j=0; j<n; ++j) {
			mn = min(dp[pre][j], mn);
			dp[cur][j] = abs(a[i]-sa[j])+mn;
		}
	}

	int64_t ans = 0x7fffffffffffffffLL;
	for (int i=0, cur=(n-1)&1; i<n; ++i) {
		ans = min(ans, dp[cur][i]);
	}

	printf("%" PRId64 "\n", ans);
	return 0;
}
