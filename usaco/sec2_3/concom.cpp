/*
ID: cenhao11
PROG: concom
LANG: C++11
*/

#include <stdio.h>
#include <string.h>

#define MAXN 100

int dshares[MAXN+1][MAXN+1]; // direct shares
int tshares[MAXN+1][MAXN+1]; // total sahres
bool control[MAXN+1][MAXN+1];

void getShares(int master, int branch, int n, int curpos) {
	for (int i=1; i<=n; ++i) {
		if (i == master) { continue; }
		tshares[master][i] += dshares[branch][i];
		if (tshares[master][i] > 50 && !control[master][i]) {
			control[master][i] = true;
			if (i < curpos) { getShares(master, i, n, curpos); }
		}
	}
}

int main() {
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);

	int n;
	int mx = 0;
	scanf("%d", &n);
	memset(dshares, 0, sizeof(dshares));
	memset(tshares, 0, sizeof(tshares));
	memset(control, 0, sizeof(control));

	int a, b, c;
	for (int i=1; i<=n; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		dshares[a][b] = c;
		tshares[a][b] = c;
		if (c > 50) { control[a][b] = true; }
		mx = (a > mx) ? a : mx;
		mx = (b > mx) ? b : mx;
	}

	for (int i=1; i<=mx; ++i) {
		for (int j=1; j<=mx; ++j) {
			if (i == j || !control[i][j]) { continue; }
			getShares(i, j, mx, j);
		}

		for (int j=1; j<=mx; ++j) {
			if (i != j && control[i][j]) { printf("%d %d\n", i, j); }
		}
	}

	return 0;
}
