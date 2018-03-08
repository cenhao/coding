#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define MOD 1000000009
int a[MAXN];
int cnt[MAXN][MAXN+1];

int main() {
	int n, m, K; scanf("%d%d%d", &n, &m, &K);
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }
	sort(a, a+n);
	memset(cnt, 0, sizeof(cnt));
	cnt[0][1] = 1;

	for (int i=1; i<n; ++i) {
		cnt[i][1] = 1;
		for (int j=0; j<i; ++j) {
			if ((a[i]-a[j]) % K != 0) { continue; }
			for (int k=1; k<m; ++k) {
				cnt[i][k+1] = (cnt[i][k+1] + cnt[j][k]) % MOD;
			}
		}
	}

	int ans = 0;
	for (int i=0; i<n; ++i) {
		ans = (ans + cnt[i][m]) % MOD;
	}

	printf("%d\n", ans);
	return 0;
}
