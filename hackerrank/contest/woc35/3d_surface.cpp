#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

const int mov[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int a[MAXN+2][MAXN+2];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	memset(a, 0, sizeof(a));
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) { scanf("%d", &a[i][j]); }
	}

	int ans = n*m * 2;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			for (int k=0; k<4; ++k) {
				ans += max(0, a[i][j]-a[i+mov[k][0]][j+mov[k][1]]);
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
