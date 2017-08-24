#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int main() {
	int n; scanf("%d", &n);
	int64_t cnt[4] = {1, 0, 0, 0};
	for (int i=0; i<n; ++i) {
		int a; scanf("%d", &a);
		cnt[a] += cnt[a-1];
	}
	printf("%" PRId64 "\n", cnt[3]);
	return 0;
}
