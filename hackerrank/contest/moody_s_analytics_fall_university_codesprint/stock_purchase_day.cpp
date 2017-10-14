#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
struct PriceInfo { int p, d; } pi[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &pi[i].p);
		pi[i].d = i+1;
	}

	sort(pi, pi+n, [](const PriceInfo &pi1, const PriceInfo &pi2) -> bool {
		return pi1.p != pi2.p ? pi1.p < pi2.p : pi1.d < pi2.d;
	});

	int mx = -1;
	for (int i=0; i<n; ++i) {
		pi[i].d = mx = max(mx, pi[i].d);
	}

	int q; scanf("%d", &q);
	for (int i=0; i<q; ++i) {
		int x; scanf("%d", &x);
		int l = 0, r = n-1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (pi[m].p <= x) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		printf("%d\n", (l>0) ? pi[l-1].d : -1);
	}

	return 0;
}
