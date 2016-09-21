#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 100

bool link[MAXN+1][MAXN+1];
int dp[MAXN+1][MAXN+1];
int tdp[2][MAXN+1];
int score[MAXN+1];
int n, m;

void process(int sta, int parent) {
	for (int i=1; i<=n; ++i) {
		if (link[sta][i] && i!=parent) {
			process(i, sta);
		}
	}

	memset(tdp, -1, sizeof(tdp));
	tdp[0][0] = 0;
	int cnt = 0, cur = 0, pre;
	for (int i=1; i<=n; ++i) {
		if (!link[sta][i] || i==parent) { continue; }
		++cnt; cur = cnt & 1; pre = (cnt-1) & 1;
		for (int i2=0; i2<m; ++i2) {
			tdp[cur][i2] = tdp[pre][i2];
			for (int i3=1; i3<=i2 && dp[i][i3]>=0; ++i3) {
				if (tdp[pre][i2-i3] >= 0) {
					tdp[cur][i2] = max(tdp[cur][i2], tdp[pre][i2-i3]+dp[i][i3]);
				}
			}
		}
	}

	dp[sta][0] = 0;
	for (int i=1; i<=m && tdp[cur][i-1]>=0; ++i) {
		dp[sta][i] = tdp[cur][i-1] + score[sta];
	}
}

int process() {
	memset(dp, -1, sizeof(dp));
	process(1, 0);
	return dp[1][m];
}

int main() {
	memset(link, 0, sizeof(link));

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i) { scanf("%d", &score[i]); }
	for (int i=1; i<n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		link[a][b] = link[b][a] = true;
	}

	printf("%d\n", process());
	return 0;
}
