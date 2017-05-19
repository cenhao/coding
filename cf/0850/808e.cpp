#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXM 300000

struct State {
	int64_t mx;
	int cnt[2];
} dp[MAXM+1];

int cnt[3];
int cost[3][MAXN];

int main() {
	memset(cnt, 0, sizeof(cnt));

	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i) {
		int w, c; scanf("%d %d", &w, &c);
		--w;
		cost[w][cnt[w]++] = c;
	}

	for (int i=0; i<3; ++i) { sort(cost[i], cost[i]+cnt[i], greater<int>()); }

	dp[0] = { 0, { 0, 0 } };
	for (int i=1; i<=m; ++i) {
		dp[i] = dp[i-1];
		int tmp = (dp[i-1].cnt[0] >= cnt[0]) ? 0 : cost[0][dp[i-1].cnt[0]];
		if (dp[i-1].mx + tmp > dp[i].mx) {
			dp[i].mx = dp[i-1].mx + tmp;
			dp[i].cnt[0] = dp[i-1].cnt[0] + 1;
			dp[i].cnt[1] = dp[i-1].cnt[1];
		}

		if (i == 1) { continue; }
		tmp = (dp[i-2].cnt[1] >= cnt[1]) ? 0 : cost[1][dp[i-2].cnt[1]];
		if (dp[i-2].mx + tmp > dp[i].mx) {
			dp[i].mx = dp[i-2].mx + tmp;
			dp[i].cnt[0] = dp[i-2].cnt[0];
			dp[i].cnt[1] = dp[i-2].cnt[1] + 1;
		}
	}

	int64_t mx = dp[m].mx, sum = 0;
	for (int i=0; i<cnt[2] && (i+1)*3<=m; ++i) {
		sum += cost[2][i];
		mx = max(mx, dp[m-3*(i+1)].mx + sum);
	}

	printf("%" PRId64 "\n", mx);
	return 0;
}
