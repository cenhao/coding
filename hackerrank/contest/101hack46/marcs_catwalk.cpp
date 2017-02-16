#include <algorithm>
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <functional>
using namespace std;

#define MAXN 40

int c[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &c[i]); }
	sort(c, c+n, greater<int>());
	int64_t base = 1LL, ans = 0LL;
	for (int i=0; i<n; ++i) {
		ans += base * c[i];
		base <<= 1;
	}

	printf("%" PRId64 "\n", ans);
	return 0;
}
