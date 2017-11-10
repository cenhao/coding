#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXM 100000
#define MAXP 100

int64_t d[MAXN+1], dp[2][MAXN+1], cost[MAXN+1];
int q[MAXN], mn_sta[MAXN+1];

inline int64_t y(int i, int j) {
	return dp[i][j]-cost[j]+int64_t(j)*mn_sta[j];
}

inline bool should_fpop(int i, int first, int second, int ms) {
	return y(i, first)-y(i, second) >= int64_t(ms) * (first-second);
}

inline bool should_rpop(int i, int f, int s, int t) {
	return (y(i, f) - y(i, s)) * (s-t) >= (y(i, s)-y(i, t)) * (f-s);
}

int main() {
	int n, m, p; scanf("%d%d%d", &n, &m, &p);
	d[1] = 0;
	for (int i=2; i<=n; ++i) {
		int v; scanf("%d", &v);
		d[i] = d[i-1] + v;
	}
	for (int i=1; i<=m; ++i) {
		int pos, play; scanf("%d%d", &pos, &play);
		mn_sta[i] = play - d[pos];
	}

	sort(mn_sta+1, mn_sta+m+1, [](int ms1, int ms2) { return ms1 < ms2; });

	cost[0] = dp[1][0] = 0;
	for (int i=1; i<=m; ++i) {
		cost[i] = dp[1][i] = dp[1][i-1]+int64_t(i-1)*(mn_sta[i]-mn_sta[i-1]);
	}
	for (int i=2; i<=p; ++i) {
		int cur = i & 1, pre = (i-1) & 1;
		dp[cur][0] = 0;
		int h = 0, r = 0;
		for (int j=1; j<=m; ++j) {
			dp[cur][j] = dp[pre][j];
			while (h < r-1 && should_fpop(pre, q[h], q[h+1], mn_sta[j])) { ++h; }

			if (h < r) {
				int64_t k = q[h];
				dp[cur][j] = min(dp[cur][j], dp[pre][k]+cost[j]-cost[k]-k*(mn_sta[j]-mn_sta[k]));
			}

			while (h < r-1 && should_rpop(pre, q[r-2], q[r-1], j)) { --r; }
			q[r++] = j;
		}
	}

	printf("%" PRId64 "\n", dp[p&1][m]);
	return 0;
}
