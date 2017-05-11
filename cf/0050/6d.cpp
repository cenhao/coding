#include <bits/stdc++.h>
using namespace std;

#define INF 10000
#define MAXN 10
#define MAXH (15+1)

int dp[MAXN][MAXH+1][MAXH+1]; // i, f, h
int pre[MAXN][MAXH+1][MAXH+1][2];
int h[MAXH];

int main() {
	int n, a, b; scanf("%d %d %d", &n, &a, &b);
	for (int i=0; i<n; ++i) {
		scanf("%d", &h[i]);
		++h[i];
	}

	memset(dp, 0x7f, sizeof(dp));
	dp[0][0][h[0]] = 0;

	for (int i=1; i<n; ++i) {
		for (int f=0; f<=MAXH; ++f) {
			for (int j=0; j<=MAXH; ++j) {
				for (int k=0; k<=MAXH; ++k) {
					if (dp[i-1][j][k] >= INF || k-f*b > 0) { continue; }
					int cur_h = max(h[i] - j * b - f * a, 0);
					if (dp[i-1][j][k] + f < dp[i][f][cur_h]) {
						dp[i][f][cur_h] = dp[i-1][j][k] + f;
						pre[i][f][cur_h][0] = j;
						pre[i][f][cur_h][1] = k;
					}
				}
			}
		}
	}

	printf("%d\n", dp[n-1][0][0]);
	int cur_p = n-2, cur_f = pre[n-1][0][0][0], cur_h = pre[n-1][0][0][1], cnt = 0;
	int nxt_f, nxt_h;
	while (cur_p != 0) {
		for (int i=0; i<cur_f; ++i) {
			printf("%d%c", cur_p+1, ++cnt==dp[n-1][0][0] ? '\n' : ' ');
		}

		nxt_f = pre[cur_p][cur_f][cur_h][0];
		nxt_h = pre[cur_p][cur_f][cur_h][1];
		cur_f = nxt_f; cur_h = nxt_h;
		--cur_p;
	}

	return 0;
}
