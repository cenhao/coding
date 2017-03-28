#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
#define MAXM 10

int dp[1<<MAXM];
int tmp[1<<MAXM];

int main() {
	int t; scanf("%d", &t);

	while (t--) {
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;

		int n, m; scanf("%d %d", &n, &m);
		for (int i=0; i<n; ++i) {
			int v, s; scanf("%d %d", &v, &s);
			int bits = 0;
			for (int j=0; j<s; ++j) {
				int p; scanf("%d", &p);
				bits |= (1 << (p-1));
			}

			memset(tmp, -1, sizeof(tmp));
			for (int j=0, end=1<<m; j<end; ++j) {
				if (dp[j] < 0) { continue; }
				int idx = j ^ bits;
				if (tmp[idx] < 0 || tmp[idx] < v + dp[j]) {
					tmp[idx] = v + dp[j];
				}
			}

			for (int j=0, end=1<<m; j<end; ++j) {
				dp[j] = max(dp[j], tmp[j]);
			}
		}

		printf("%d\n", dp[(1<<m)-1]);
	}

	return 0;
}
