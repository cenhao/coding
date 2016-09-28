#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define INF 1000001
#define MAXN 100
#define MAXV 2

int val[MAXN+1];
int link[MAXN+1][MAXN+1];
int dp[MAXN+1][2][MAXN*MAXV+1];

int n;

int process(int s, int p) { // start, parent
	for (int i=0; i<=val[s]; ++i) { dp[s][0][i] = dp[s][1][i] = 0; }
	int sum = val[s];
	for (int i=1; i<=n; ++i) {
		if (i == p || link[s][i] >= INF) { continue; }
		sum += process(i, s);

		for (int i2=sum; i2>val[s]; --i2) {
			for (int i3=1, end=min(i2, val[i]); i3<=end; ++i3) {
				dp[s][0][i2] = min(dp[s][0][i2], dp[s][0][i2-i3]+dp[i][0][i3]+2*link[s][i]);
				dp[s][1][i2] = min(dp[s][1][i2],
						min(dp[s][0][i2-i3]+dp[i][1][i3]+link[s][i], dp[s][1][i2-i3]+dp[i][0][i3]+2*link[s][i]));
			}
		}
	}

	return val[s] = sum;
}

void process() {
	memset(dp, 0x0f, sizeof(dp));
	process(1, 0);

	int m; scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		int q; scanf("%d", &q);

		int l=0, r=val[1], m;

		while (l <= r) {
			m = (l + r) / 2;
			if (dp[1][1][m] <= q) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		printf("%d\n", r);
	}
}

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) { scanf("%d", &val[i]); }

	memset(link, 0x0f, sizeof(link));
	for (int i=1; i<n; ++i) {
		int u, v, d; scanf("%d %d %d", &u, &v, &d);
		link[u][v] = link[v][u] = d;
	}

	process();
	return 0;
}
