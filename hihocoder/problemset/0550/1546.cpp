#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MOD 1000000007

int64_t a[MAXN];
int64_t pow2[MAXN];

int main() {
	int n; int64_t k;
	scanf("%d%" SCNd64 "", &n, &k);
	for (int i=0; i<n; ++i) { scanf("%" SCNd64 "", &a[i]); }
	sort(a, a+n);
	pow2[0] = 1;
	for (int i=1; i<n; ++i) { pow2[i] = (2 * pow2[i-1]) % MOD; }
	int64_t ans = 0;
	for (int i=0, e=n-1; i<=e; ++i) {
		while (e >= i && a[i]+a[e] > k) { --e; }
		int dist = e - i;
		ans = (ans + (dist>=0 ? pow2[dist] : 0)) % MOD;
	}

	printf("%" PRId64 "\n", ans);
	return 0;
}
