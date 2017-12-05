#include <bits/stdc++.h>
using namespace std;

bool test(int64_t n, int64_t l, int64_t m) {
	int64_t sm = 1, mlimit = m, mgr = 1;
	for (int i=1; i<l && mlimit>=0; ++i) {
		int64_t need = n - sm;
		int64_t mneed = need / mgr + (need % mgr ? 1 : 0);
		if (mneed <= mlimit) { return true; }
		sm += mgr = mlimit * mgr;
		--mlimit;
	}

	return false;
}

int main() {
	int64_t n, layer; scanf("%" SCNd64 "%" SCNd64 "", &n, &layer);
	int64_t l = 0, r = n-1;

	while (l <= r) {
		int64_t m = (l + r) >> 1;
		if (test(n, layer, m)) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	printf("%" PRId64 "\n", l);
	return 0;
}
