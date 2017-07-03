#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

struct Data {
	int v, cnt;
} a[MAXN], b[MAXN];

int main() {
	auto cmp = [](const Data &d1, const Data &d2) { return d1.v < d2.v; };

	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) { scanf("%d%d", &a[i].v, &a[i].cnt); }
		for (int i=0; i<m; ++i) { scanf("%d%d", &b[i].v, &b[i].cnt); }
		sort(a, a+n, cmp);
		sort(b, b+m, cmp);
		int64_t ans = 0;
		for (int i=0, pos=0, bcnt=0; i<n; ++i) {
			while (pos < m && b[pos].v < a[i].v) {
				bcnt += b[pos++].cnt;
			}
			ans += int64_t(a[i].cnt) * bcnt;
		}

		printf("%" PRId64 "\n", ans);
	}

	return 0;
}
