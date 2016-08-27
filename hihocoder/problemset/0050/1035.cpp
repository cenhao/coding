/*
 * Hihocoder 1035. Tree DP.
 * Given dp[n][i][j],
 * i == 0, start with no car
 * i == 1, start with car, if come back, come back with driving
 * i == 2, start with car, but come back walking
 *
 * j == 0, come back
 * j == 1, did not come back
 *
 * so dp[n][1][1] == dp[n][2][1], hence let's skip dp[n][2][1]
 *
 * dp[n][0][0] = sum(dp[child][0][0] + 2*cost_walk)
 * dp[n][1][0] = sum(min(dp[child][0][0]+2*cost_walk, dp[child][1][0]+2*cost_drive))
 *
 * dp[n][0][1] = dp[n][0][0] - max(cost for coming back from one the children)
 * dp[n][2][0] = dp[n][1][0] - max(0, cost for coming back walking from one of the children)
 *
 * The most difficult one is
 * dp[n][1][1], here're two possibilities:
 * 1. end with car: dp[n][1][1] = dp[n][1][0] - max(cost for coming back from one of the children)
 * 2. end with no car: dp[n][1][1] = dp[n][1][0] - max(improvement of coming back walking) -
 * 		max(cost for not coming back from one of the children, walking)
 */

#include <algorithm>
using namespace std;

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXN 1000000

struct Node {
	bool critical;
	int fe; // first edge index
} nodes[MAXN+1];

struct Edge {
	int cc; // cost with car
	int cw; // cost with walk
	int v;
	int nxt;
} edges[MAXN * 2 + 1];

/*
 * dp[node][i][j]
 * i:
 *  0: walk only
 *  1: start with car, but if come back, also with car
 *  2: start with car, come back walking
 * j:
 *  0: come back, only work for i=0/1
 *  1: don't come back
 */
int64_t dp[MAXN+1][3][2];

int ecnt;
int n, m;

inline void read(int u, int v, int cw, int cc) {
	nodes[u].critical = false;
	edges[ecnt].cc = cc; edges[ecnt].cw = cw;
	edges[ecnt].nxt = nodes[u].fe;
	edges[ecnt].v = v;
	nodes[u].fe = ecnt++;

	nodes[v].critical = false;
	edges[ecnt].cc = cc; edges[ecnt].cw = cw;
	edges[ecnt].nxt = nodes[v].fe;
	edges[ecnt].v = u;
	nodes[v].fe = ecnt++;
}

void process(int start, int parent) {
	int64_t dNoWalkBack, dNoCarBack, dWalkBack;
	dNoWalkBack = dNoCarBack = dWalkBack = 0;

	int64_t gain1, gain2;
	gain1 = gain1 = 1LL << 50; // Can't be too large, otherwise it will overflow
	int gc = -1;

	for (int cur=nodes[start].fe; cur != 0; cur=edges[cur].nxt) {
		int child = edges[cur].v;
		if (child != parent) {
			process(child, start);

			if (!nodes[child].critical) { continue; }

			nodes[start].critical |= nodes[child].critical;
			dp[start][0][0] += dp[child][0][0] + 2*edges[cur].cw;
			int64_t tmp = min(dp[child][1][0]+2*edges[cur].cc, dp[child][0][0]+2*min(edges[cur].cc, edges[cur].cw));
			dp[start][1][0] += tmp;
			dNoWalkBack = min(dNoWalkBack, dp[child][0][1]-dp[child][0][0]-edges[cur].cw);
			dNoCarBack = min(dNoCarBack, min(dp[child][1][1]+edges[cur].cc, dp[child][0][1]+min(edges[cur].cw, edges[cur].cc))-tmp);
			dWalkBack = min(dWalkBack, edges[cur].cc+edges[cur].cw+dp[child][2][0]-tmp);

			tmp = dp[child][2][0] + edges[cur].cw + edges[cur].cc - tmp;
			if (tmp < gain1) {
				gain2 = gain1;
				gain1 = tmp;
				gc = child;
			} else if (tmp < gain2) {
				gain2 = tmp;
			}
		}
	}

	if (!nodes[start].critical) { return; }

	dp[start][0][1] = dp[start][0][0] + dNoWalkBack;
	dp[start][1][1] = dp[start][1][0] + dNoCarBack;
	dp[start][2][0] = dp[start][1][0] + dWalkBack;

	for (int cur=nodes[start].fe; cur!=0; cur=edges[cur].nxt) {
		int child = edges[cur].v;
		if (child != parent && nodes[child].critical) {
			int64_t tmp = min(dp[child][1][0]+2*edges[cur].cc, dp[child][0][0]+2*min(edges[cur].cc, edges[cur].cw));
			tmp = dp[child][0][1] - tmp + edges[cur].cw;

			if (child == gc) {
				dp[start][1][1] = min(dp[start][1][1], dp[start][1][0]+tmp+gain2);
			} else {
				dp[start][1][1] = min(dp[start][1][1], dp[start][1][0]+tmp+gain1);
			}
		}
	}
}

int64_t process() {
	memset(dp, 0, sizeof(dp));
	process(1, 0);
	return min(dp[1][0][1], dp[1][1][1]);
}

int main() {
	scanf("%d", &n);
	memset(nodes, 0, sizeof(nodes));
	ecnt = 1;
	for (int i=1; i<n; ++i) {
		int u, v, cw, cc;
		scanf("%d %d %d %d", &u, &v, &cw, &cc);
		read(u, v, cw, cc);
	}

	scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		int cn;
		scanf("%d", &cn);
		nodes[cn].critical = true;
	}

	printf("%" PRId64 "\n", process());
	return 0;
}
