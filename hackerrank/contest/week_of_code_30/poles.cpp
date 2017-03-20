#include <bits/stdc++.h>
using namespace std;

#define MAXN 5000
#define INF 0x7fffffffffffffffLL

int64_t dp[MAXN+1][MAXN+1];
int opt[MAXN+1][MAXN+1];
int lat[MAXN+1], w[MAXN+1];
int64_t cost[MAXN+1][MAXN+1];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	for (int i=1; i<=n; ++i) {
		scanf("%d %d", &lat[i], &w[i]);
		int64_t sum = 0, wsum = 0;
		for (int j=i; j>=1; --j) {
			sum = cost[j][i] = sum + (wsum*(lat[j+1]-lat[j]));
			wsum += w[j];
		}
	}

	memset(dp, 0x70, sizeof(dp));
	dp[0][0] = 0;
	for (int sp=1; sp<=n; ++sp) {
		for (int step=1, end=min(k, n+1-sp); step<=end; ++step) {
			int p = sp+step-1, s = step;
			if (s == p) {
				dp[s][p] = 0;
				opt[s][p] = p-1;
			} else {
				dp[s][p] = INF;
				int end = (s == k) ? p-1 : opt[s+1][p];
				for (int o=opt[s][p-1]; o<=end; ++o) {
					if (dp[s-1][o]+cost[o+1][p] < dp[s][p]) {
						dp[s][p] = dp[s-1][o]+cost[o+1][p];
						opt[s][p] = o;
					}
				}
			}
		}
	}

	printf("%" PRId64 "\n", dp[k][n]);
	return 0;
}
