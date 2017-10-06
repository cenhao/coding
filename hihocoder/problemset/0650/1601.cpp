#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
int a[MAXN], cnt[MAXN];
int dp[MAXN+1][MAXN];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }
	sort(a, a+n);
	int pos = 0;
	memset(cnt, 0, sizeof(cnt));
	cnt[0] = 1;
	for (int i=1; i<n; ++i) {
		if (a[i] != a[pos]) {
			a[++pos] = a[i];
			cnt[pos] = 0;
		}

		++cnt[pos];
	}

	memset(dp, 0, sizeof(dp));
	for (int i=1; i<=m; ++i) {
		for (int j=0, cur=0, mx=0; j<n; ++j) {
			while (cur<j && a[cur]+1<a[j]) {
				mx = max(mx, dp[i-1][cur]);
				++cur;
			}

			dp[i][j] = a[j]*cnt[j] + mx;
		}
	}

	int mx = 0;
	for (int i=0; i<n; ++i) { mx = max(mx, dp[m][i]); }
	printf("%d\n", mx);
	return 0;
}
