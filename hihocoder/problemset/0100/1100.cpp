#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int disk[MAXN];
int pick[MAXN];

int main() {
	int n, m, h, r; scanf("%d %d %d %d", &n, &m, &h, &r);
	for (int i=0; i<n; ++i) { scanf("%d", &disk[i]); }
	sort(disk, disk+n);

	for (int i=0; i<n; ++i) {
		pick[i] = (disk[i] <= r) ? 1 : 0;
		if (i > 0 && disk[i]-disk[i-1]<=m) {
			int v = min(h-1, pick[i-1]);
			if (disk[i-v] <= r && disk[i] <= r+v) {
				pick[i] = max(pick[i], v+1);
			}
		}
	}

	int ans = 0;
	for (int i=n-1; i>=0 && ans <= h; --i) {
		if (pick[i]) {
			ans += pick[i];
			i -= pick[i] - 1;
		}
	}

	ans = min(ans, h);
	printf("%d\n", ans);
	return 0;
}
