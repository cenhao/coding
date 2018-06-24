#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t n; scanf("%" SCNd64 "", &n);
	int64_t l = 1, r = n;
	while (l <= r) {
		int64_t m = (l + r) >> 1, nn = n;
		int64_t vsm = 0, psm = 0;
		while (nn > 0) {
			int64_t ve = min(nn, m);
			vsm += ve;
			nn -= ve;
			int64_t se = nn / 10;
			psm += se;
			nn -= se;
		}
		if (vsm >= psm) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	printf("%" PRId64 "\n", l);
	return 0;
}
