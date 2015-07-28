/*
ID: cenhao11
PROG: ariprog
LANG: C++11
*/

#include <stdio.h>
#include <string.h>

#define MAXN 30
#define MAXM 255

bool IsBisquary[2 * MAXM * MAXM];

int main()
{
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	memset(IsBisquary, 0, sizeof(IsBisquary));
	int lastBisquary = m * m * 2;
	int found = 0;

	for (int i=0; i<=m; ++i) {
		for (int j=i; j<=m; ++j) {
			IsBisquary[i*i + j*j] = true;
		}
	}

	for (int step=1; step*(n-1)<=lastBisquary; ++step) {
		for (int i=0; i+step*(n-1)<=lastBisquary; ++i) {
			int cnt;
			for (cnt=0; cnt<n && IsBisquary[i+cnt*step]; ++cnt);
			if (cnt == n) {
				++found;
				printf("%d %d\n", i, step);
			}
		}
	}

	if (found == 0) { printf("NONE\n"); }

	return 0;
}
