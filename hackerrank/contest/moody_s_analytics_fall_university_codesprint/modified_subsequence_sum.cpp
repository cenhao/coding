#include <bits/stdc++.h>
using namespace std;

#define MAXN 300000
int64_t a[MAXN];
int q[MAXN];
int64_t dp[MAXN];

inline int64_t get_y(int64_t idx, int64_t k) {
	return dp[idx] - k*idx*(idx+2);
}

inline int64_t get_x(int64_t idx, int64_t k) {
	return -2*k*idx;
}

inline int64_t get_dp(int64_t i, int64_t j, int64_t k) {
	return dp[j]+a[i]-k*int64_t(i-j-1)*(i-j-1);
}

int main() {
	int n, k; scanf("%d%d", &n, &k);
	int h = 0, r = -1;
	for (int i=0; i<n; ++i) {
		scanf("%" SCNd64 "", &a[i]);
		dp[i] = a[i];
		while (h < r) {
			int64_t y_h1 = get_y(q[h+1], k), y_h = get_y(q[h], k);
			int64_t x_h1 = get_x(q[h+1], k), x_h = get_x(q[h], k);
			if (y_h1-y_h < i*(x_h1-x_h)) { break; }
			++h;
		}
		if (h <= r) {
			dp[i] = max(dp[i], get_dp(i, q[h], k));
		}
		while (h < r) {
			int64_t y_r = get_y(q[r], k), y_r1 = get_y(q[r-1], k), y_i = get_y(i, k);
			int64_t x_r = get_x(q[r], k), x_r1 = get_x(q[r-1], k), x_i = get_x(i, k);
			if ((y_r-y_r1)*(x_i-x_r) <= (y_i-y_r)*(x_r-x_r1)) { break; }
			--r;
		}

		q[++r] = i;
	}

	int64_t mx = dp[0];
	for (int i=1; i<n; ++i) { mx = max(dp[i], mx); }
	printf("%" PRId64 "\n", mx);

	return 0;
}
