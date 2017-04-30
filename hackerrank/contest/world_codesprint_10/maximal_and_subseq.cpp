#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MOD 1000000007

int64_t a[MAXN], b[MAXN];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	for (int i=0; i<n; ++i) { scanf("%" SCNd64 "", &a[i]); }

	int64_t mx = 0;
	for (int i=60; i>=0; --i) {
		int64_t mask = 1LL << i;
		int cnt = 0;
		for (int j=0; j<n; ++j) {
			if (mx == 0 || (a[j] & mx) == mx) {
				if (a[j] & mask) { ++cnt; }
			}
		}

		if (cnt >= k) { mx |= mask; }
	}

	int cnt = 0;
	for (int i=0; i<n; ++i) {
		if ((a[i] & mx) == mx) { ++cnt; }
	}

	int64_t ans = 1LL;
	for (int i=k+1; i<=cnt; ++i) { ans = (ans * i) % MOD; }
	int64_t dom = 1LL;
	for (int i=cnt-k; i>=1; --i) { dom = (dom * i) % MOD; }
	int pow = MOD - 2;
	int64_t cur = dom;
	dom = 1;

	while (pow > 0) {
		if (pow & 1) { dom = (dom * cur) % MOD; }
		cur = (cur * cur) % MOD;
		pow >>= 1;
	}

	ans = (ans * dom) % MOD;
	printf("%" PRId64 "\n%" PRId64 "\n", mx, ans);
	return 0;
}
