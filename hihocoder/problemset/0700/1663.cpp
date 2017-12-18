#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	bool vis[10][10];
	for (int t=0; t<T; ++t) {
		int64_t x, k; scanf("%" SCNd64 "%" SCNd64 "" , &x, &k);
		int64_t ans = -1;
		int cnt = 0;
		int v = 1, r = x % 10;
		memset(vis, false, sizeof(vis));
		while (v != k && !vis[r][v] && x-2*cnt>0) {
			vis[r][v] = true;
			++cnt;
			v = (v * r) % 10;
			r -= 2;
			if (r < 0) { r += 10; }
		}

		if (v == k) { ans = x - 2 * cnt; }

		printf("%" PRId64 "\n", ans);
	}

	return 0;
}
