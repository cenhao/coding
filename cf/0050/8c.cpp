/*
 * An important fact is that, the order of "roundtrips" for the
 * optimal solution doesn't matter.
 *
 * A roundtrip is from the handbag and pick up one or two objects
 * and come back the the handbag.
 *
 * With this, when we're doing the dp for the bit state, for one
 * object, we only need to check the one with lowest index (lowbit).
 * For two objects, we will need to enumerate all the combinations
 * for the lowest indexed object and another one.
 */

#include <bits/stdc++.h>
using namespace std;

#define MAXN 24
#define LB(x) (x & (~(x-1)))

int s2o[1<<MAXN];
int dp[1<<MAXN], back[1<<MAXN];
int objs[MAXN][2];
int dist[MAXN], dist2[MAXN][MAXN];

int main() {
	memset(dp, -1, sizeof(dp));

	int x0, y0; scanf("%d %d", &x0, &y0);
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d %d", &objs[i][0], &objs[i][1]);
		int dx = objs[i][0]-x0, dy = objs[i][1]-y0;
		dist[i] = dx*dx + dy*dy;
		dist2[i][i] = 0;
		s2o[1<<i] = i;
	}

	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			int dx = objs[i][0]-objs[j][0], dy = objs[i][1]-objs[j][1];
			dist2[i][j] = dist2[j][i] = dx*dx + dy*dy;
		}
	}

	int full = (1 << n) - 1;
	dp[0] = 0;
	for (int s=1; s<=full; ++s) {
		int lb = LB(s);
		int oid = s2o[lb], ns = s ^ lb, tmp = dp[ns] + 2 * dist[oid];
		if (dp[s] < 0 || tmp < dp[s]) {
			dp[s] = tmp;
			back[s] = ns;
		}
		int tns = ns;
		for (int i=LB(tns); tns>0; tns-=i, i=LB(tns)) {
			int noid = s2o[i], nns = ns ^ i;
			int ntmp = dp[nns] + dist[oid] + dist[noid] + dist2[oid][noid];
			if (dp[s] < 0 || ntmp < dp[s]) {
				dp[s] = ntmp;
				back[s] = nns;
			}
		}
	}

	printf("%d\n", dp[full]);

	while (full != 0) {
		printf("0 ");
		int pre = back[full];
		int delta = full ^ pre;
		for (int i=LB(delta); delta>0; delta-=i, i=LB(delta)) {
			printf("%d ", s2o[i]+1);
		}
		full = pre;
	}
	printf("0\n");
	return 0;
}
