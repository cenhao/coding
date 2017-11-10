#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
int a[MAXN];

int main() {
	int n; scanf("%d", &n);
	int mn = 0x7fffffff;
	for (int i=0; i<n; ++i) {
		scanf("%d", &a[i]);
		mn = min(mn, a[i]);
	}
	int64_t ans = 0;
	for (int i=0; i<n; ++i) {
		ans += a[i] - mn;
	}

	printf("%" PRId64 "\n", ans);
	return 0;
}
