#include <bits/stdc++.h>
using namespace std;

#define MAXN 19
#define LB(x) (x & (~(x-1)))

int conn[MAXN];
int64_t dp[1<<MAXN][MAXN];
int s2i[1<<MAXN];

int main() {
	memset(conn, 0, sizeof(conn));
	memset(dp, 0, sizeof(dp));
	int n, m; scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		--u; --v;
		conn[u] |= 1 << v;
		conn[v] |= 1 << u;
	}

	for (int i=0; i<n; ++i) { s2i[1 << i] = i; }

	int full = (1 << n) - 1;
	for (int i=1; i<=full; ++i) {
		if (LB(i) == i) {
			dp[i][s2i[i]] = 1;
			continue;
		}

		int start = i-LB(i);
		for (int j=LB(start), avai=start; avai>0; avai-=j, j=LB(avai)) {
			int idx = s2i[j];
			int pre = (i & (~j)), ok = ((i & (~j)) & conn[idx]);

			for (int k=LB(ok); ok>0; ok-=k, k=LB(ok)) {
				dp[i][idx] += dp[pre][s2i[k]];
			}
		}
	}

	int64_t ans = 0;
	for (int i=1; i<=full; ++i) {
		int lb = LB(i);
		for (int j=0; j<n; ++j) {
			if (dp[i][j] <= 0) { continue; }
			if ((lb|(1<<j)) == i) { continue; }
			if (conn[s2i[lb]] & (1<<j)) {
				ans += dp[i][j];
			}
		}
	}

	printf("%" PRId64 "\n", ans / 2);
	return 0;
}
