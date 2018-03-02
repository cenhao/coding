#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXK 50
struct Num { int v, p; } a[MAXN];
int pp[MAXK+5], ap[MAXK+5];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i=0; i<n; ++i) {
		scanf("%d", &a[i].v);
		a[i].p = i;
	}
	sort(a, a+n, [](const Num &n1, const Num &n2) { return n1.v > n2.v; });

	set<int> pset;
	int64_t ans = 0;
	for (int i=0; i<n; ++i) {
		auto it = pset.lower_bound(a[i].p);
		int pcnt = 0;
		pp[pcnt++] = a[i].p;
		for (auto pit=set<int>::reverse_iterator(it); pit!=pset.rend() && pcnt<=k; ++pit) {
			pp[pcnt++] = *pit;
		}
		if (pcnt <= k) { pp[pcnt++] = -1; }

		int ncnt = 0;
		for (auto nit=it; nit!=pset.end() && ncnt<k; ++nit) {
			ap[ncnt++] = *nit;
		}
		if (ncnt < k) { ap[ncnt++] = n; }

		for (int j=pcnt-2; j>=0; --j) {
			int ai = min(ncnt-1, k-j-1);
			ans += int64_t(a[i].v) * (pp[j]-pp[j+1]) * (ap[ai]-a[i].p);
		}

		pset.insert(a[i].p);
	}

	printf("%" PRId64 "\n", ans);
	return 0;
}
