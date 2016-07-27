/*
ID: cenhao11
PROG: agrinet
LANG: C++11
*/

#include <stdio.h>

#define MAXN 100
#define INF 0x7fffff00

int dist[MAXN][MAXN];
int greed[MAXN];

int prim(int n) {
	for (int i=0; i<n; ++i) { greed[i] = dist[0][i]; }
	greed[0] = INF;
	int res = 0;

	for(int i=1; i<n; ++i) {
		int mn = INF;
		int pick;
		for (int j=0; j<n; ++j) {
			if (greed[j] < mn) {
				mn = greed[j];
				pick = j;
			}
		}

		res += mn;
		greed[pick] = INF;

		for (int j=0; j<n; ++j) {
			if (dist[pick][j] < greed[j] && greed[j] != INF) {
				greed[j] = dist[pick][j];
			}
		}
	}

	return res;
}

int main() {
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);
	int n;
	scanf("%d", &n);

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			scanf("%d", &dist[i][j]);
		}
	}

	printf("%d\n", prim(n));
	return 0;
}
