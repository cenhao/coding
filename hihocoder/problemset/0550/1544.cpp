#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
#define MAXS 20

bool is_busy[MAXN+1], is_first[MAXN+1];
int cost[MAXN*2+2];
int reach[MAXN*2][MAXS];

int main() {
	int n, m, t, k1, k2;
	scanf("%d%d%d%d%d", &n, &m, &t, &k1, &k2);
	memset(is_busy, false, sizeof(is_busy));
	memset(is_first, false, sizeof(is_first));
	for (int i=0; i<n; ++i) {
		int l, r;scanf("%d%d", &l, &r);
		for (int j=l; j<r; ++j) { is_busy[j] = true; }
		is_first[l] = true;
	}

	int cnt = 0;
	for (int i=0; i<t; ++i) {
		if (is_busy[i]) {
			if (is_first[i]) {
				cost[cnt++] = k1;
			} else {
				cost[cnt-1] += k1;
			}
		} else {
			cost[cnt++] = k2;
		}
	}

	for (int i=cnt; i<2*cnt; ++i) { cost[i] = cost[i-cnt]; }
	for (int i=1; i<2*cnt; ++i) { cost[i] += cost[i-1]; }

	for (int i=0; i<2*cnt; ++i) {
		int past = i == 0 ? 0 : cost[i-1];
		auto it = upper_bound(&cost[i], cost+2*cnt, m+past);
		reach[i][0] = distance(cost, it);
		if (reach[i][0] == i) {
			printf("-1\n");
			return 0;
		}
	}

	for (int j=1; j<MAXS; ++j) {
		for (int i=0; i<2*cnt; ++i) {
			reach[i][j] = reach[i][j-1] >= 2*cnt ? 2*cnt : reach[reach[i][j-1]][j-1];
		}
	}

	int ans = MAXN * 2;
	for (int i=0; i<cnt; ++i) {
		int step = 0, p = i;
		for (int j=MAXS-1; j>=0; --j) {
			if (reach[p][j] < i+cnt) {
				step += (1 << j);
				p = reach[p][j];
			} else {
				ans = min(ans, step + (1<<j));
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
