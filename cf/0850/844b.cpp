#include <bits/stdc++.h>

#define MAXN 50

int ccnt[MAXN][2];
int rcnt[2];

int main() {
	memset(ccnt, 0, sizeof(ccnt));
	int n, m; scanf("%d%d", &n, &m);
	int64_t ans = 0;
	for (int i=0; i<n; ++i) {
		rcnt[0] = rcnt[1] = 0;
		for (int j=0; j<m; ++j) {
			int v; scanf("%d", &v);
			++rcnt[v]; ++ccnt[j][v];
			ans += (1LL << (rcnt[v]-1)) + (1LL << (ccnt[j][v]-1)) - 1;
		}
	}

	printf("%" PRId64 "\n", ans);
	return 0;
}
