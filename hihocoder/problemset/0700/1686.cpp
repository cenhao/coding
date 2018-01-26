#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	unordered_map<int, int> cm;
	int64_t ans = 0;
	for (int i=0; i<n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		ans += cm[x-y];
		++cm[y-x];
	}

	printf("%" PRId64 "\n", ans);

	return 0;
}
