#include <bits/stdc++.h>
using namespace std;

#define MAXN 500

int cnt[MAXN+1][MAXN+1];
bool mark[MAXN+1][MAXN+1];

struct Pixel {
	int x, y, t;
} p[MAXN*MAXN];

bool check(int n, int m, int k, int s) {
	memset(mark, 0, sizeof(mark));
	memset(cnt, 0, sizeof(cnt));

	for (int i=0; i<=s; ++i) { mark[p[i].x][p[i].y] = true; }
	for (int i=1; i<=n; ++i) {
		int lcnt = 0;
		for (int j=1; j<=m; ++j) {
			if (mark[i][j]) { ++lcnt; }
			cnt[i][j] = cnt[i-1][j] + lcnt;
			if (mark[i][j] && i>=k && j>=k) {
				int bcnt = cnt[i][j] - cnt[i-k][j] - cnt[i][j-k] + cnt[i-k][j-k];
				if (bcnt == k*k) { return true; }
			}
		}
	}

	return false;
}

int main() {
	int n, m, k, q; scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i=0; i<q; ++i) { scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].t); }
	sort(p, p+q, [](const Pixel &p1, const Pixel &p2) {
		return p1.t < p2.t;
	});

	int l = k*k-1, r = q-1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(n, m, k, mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	printf("%d\n", (l>=q) ? -1 : p[l].t);
	return 0;
}
