#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int64_t n, k; scanf("%" SCNd64 " %" SCNd64 "", &n, &k);
		map<int64_t, int64_t, greater<int64_t>> cnt;
		cnt[n] = 1;
		int64_t entered = 0;

		int64_t l, r;
		while (entered < k) {
			auto it = cnt.begin();
			l = (it->first-1) / 2;
			r = (it->first-1) / 2 + ((it->first&1) ? 0 : 1);
			entered += it->second;
			cnt[l] += it->second; cnt[r] += it->second;
			cnt.erase(it);
		}

		printf("Case #%d: %" PRId64 " %" PRId64 "\n", t, r, l);
	}

	return 0;
}
