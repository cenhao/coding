#include <bits/stdc++.h>
using namespace std;

#define MAXN 300
struct Q {
	int sm, p;
} q[MAXN+1][MAXN+1][MAXN+1];
int sm[MAXN+1][MAXN+1];
int len[MAXN+1][MAXN+1];

int main() {
	int n, m;
	int64_t K;
	scanf("%d%d%" SCNd64 "", &n, &m, &K);

	memset(sm, 0, sizeof(sm));
	for (int i=1; i<=m; ++i) {
		for (int j=i; j<=m; ++j) {
			len[i][j] = 1;
			q[i][j][0] = { 0, 0 };
		}
	}

	int mx = -1;
	for (int i=1; i<=n; ++i) {
		int rsm = 0;
		for (int j=1; j<=m; ++j) {
			int v; scanf("%d", &v);
			rsm += v; sm[i][j] = sm[i-1][j] + rsm;
			for (int k=j; k>=1; --k) {
				int sub = sm[i][j] - sm[i][k-1];
				if (sub > q[k][j][len[k][j]].sm) {
					q[k][j][len[k][j]++] = { sub, i };
				}
				int64_t tar = sub - K;
				int l = 0, r = len[k][j] - 1;

				while (l <= r) {
					int m = (l + r) >> 1;
					if (q[k][j][m].sm >= tar) {
						r = m - 1;
					} else {
						l = m + 1;
					}
				}

				int w = j - k + 1;
				int h = (l>=len[k][j]) ? 0 : (i - q[k][j][l].p);
				int sz = w * h;
				if (sz > 0) { mx = max(sz, mx); }
			}
		}
	}

	printf("%d\n", mx);
	return 0;
}
