/*
ID: cenhao11
PROG: comehome
LANG: C++11
*/

/* dijkstra's algo... But I'm too sleepy to write this code right... */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXP 26
#define INF 0x7fff0000
bool vis[MAXP << 1];
int dp[MAXP << 1];
int dist[MAXP<<1][MAXP<<1];

int main() {
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
	int n;
	scanf("%d", &n);
	memset(dist, -1, sizeof(dist));
	memset(vis, 0, sizeof(vis));

	int d;
	char a[10], b[10];
	int idxa, idxb;
	for (int i=0; i<n; ++i) {
		scanf("%s %s %d\n", a, b, &d);
		idxa = a[0] - ((a[0] >= 'a') ? ('A' + 6) : 'A');
		idxb = b[0] - ((b[0] >= 'a') ? ('A' + 6) : 'A');
		if (dist[idxa][idxb] > d || dist[idxa][idxb] < 0) {
			dist[idxa][idxb] = dist[idxb][idxa] = d;
		}
	}

	for (int i=MAXP*2-1; i>=0; --i) {
		dist[i][i] = 0;
		dp[i] = dist[MAXP-1][i];
	}

	for (int i=MAXP*2-1; i>=0; --i) {
		int pick = -1;
		int mn = INF;
		for (int j=MAXP*2-1; j>=0; --j) {
			if (!vis[j] && dp[j] >= 0 && dp[j] < mn) {
				mn = dp[j];
				pick = j;
			}
		}

		if (pick == -1) { break; }

		vis[pick] = true;
		for (int j=MAXP*2-1; j>=0; --j) {
			if (dist[pick][j] >= 0 && (dp[pick] + dist[pick][j] < dp[j] || dp[j] <= 0)) {
				dp[j] = dp[pick] + dist[pick][j];
			}
		}
	}

	int mn = INF;
	int pick;
	for (int i=MAXP-2; i>=0; --i) {
		if (dp[i] >= 0 && dp[i] < mn) {
			mn = dp[i];
			pick = i;
		}
	}

	printf("%c %d\n", 'A' + pick, mn);
	return 0;
}
