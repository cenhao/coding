#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int64_t dp[MAXN];
int a[MAXN], b[MAXN];
int q[MAXN], h, r;

inline double slope(int i, int j) {
	return (dp[j] - dp[i]) / double(b[j] - b[i]);
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }
	for (int i=0; i<n; ++i) { scanf("%d", &b[i]); }

	q[0] = dp[0] = 0;
	h = 0; r = 1;

	for (int i=1; i<n; ++i) {
		while (h < r-1 && slope(q[h+1], q[h]) > -a[i]) { ++h; }
		dp[i] = dp[q[h]] + int64_t(a[i]) * b[q[h]];
		while (h < r-1 && slope(i, q[r-1]) > slope(q[r-1], q[r-2])) { --r; }
		q[r++] = i;
	}

	printf("%" PRId64 "\n", dp[n-1]);
	return 0;
}
