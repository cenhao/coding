#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t n; scanf("%" SCNd64 "", &n);
	if (n == 1) {
		printf("2\n");
		return 0;
	}
	int64_t sm = ((1+n+n) * n) / 2;
	int64_t ans = sm + n+n-2;
	printf("%" PRId64 "\n", ans);
	return 0;
}
