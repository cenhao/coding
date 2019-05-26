#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int a[MAXN], b[MAXN];

int main() {
	int n, c; cin >> n >> c;
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }
	for (int i=0; i<n; ++i) { scanf("%d", &b[i]); }
	int64_t dist = a[0], left = c - b[0];
	for (int i=1; i<n; ++i) {
		if (left < b[i]) {
			left = c;
			dist += 2 * a[i-1];
		}
		dist += a[i] - a[i-1];
		left -= b[i];
	}

	dist += a[n-1];

	printf("%" PRId64 "\n", dist);
	return 0;
}
