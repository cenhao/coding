#include <bits/stdc++.h>
using namespace std;

#define MAXN 20
#define LB(x) (x & (~(x-1)))

int64_t dp[1<<MAXN];
int64_t sum[1<<MAXN];
int64_t a[MAXN];

int main() {
	int n; scanf("%d", &n);
	unordered_map<int, int64_t> vm;
	for (int i=0; i<n; ++i) {
		scanf("%" PRId64 "", &a[i]);
		vm[1<<i] = a[i];
	}
	int all = 1 << n;
	sum[0] = 0;
	for (int i=1; i<all; ++i) {
		int lb = LB(i);
		sum[i] = sum[i-lb] + vm[lb];
	}

	memset(dp, 0, sizeof(dp));
	for (int i=1; i<all; ++i) {
		for (int j=0; j<n; ++j) {
			if (((1<<j)&i) == 0) { continue; }
			int rest = i & (~(1<<j));
			dp[i] = max(dp[i], sum[rest]%vm[1<<j]+dp[rest]);
		}
	}

	printf("%" PRId64 "\n", dp[(1<<n)-1]);
	return 0;
}
