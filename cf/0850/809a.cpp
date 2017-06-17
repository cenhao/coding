#include <bits/stdc++.h>
using namespace std;

#define MAXN 300000
#define MOD 1000000007

int x[MAXN];
int two_pow[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &x[i]); }
	sort(x, x+n);
	int ans = 0;
	two_pow[0] = 1;
	for (int i=1; i<n; ++i) { two_pow[i] = (two_pow[i-1] << 1) % MOD; }
	for (int i=1; i<n; ++i) {
		int delta = x[i] - x[i-1];
		int mul = (((int64_t(two_pow[n-i]-1)*(two_pow[i]-1))%MOD))*delta) % MOD;
		ans = (ans + mul) % MOD;
	}

	printf("%d\n", ans);
	return 0;
}
