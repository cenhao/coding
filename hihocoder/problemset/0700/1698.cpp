#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MOD 1000000009

int64_t f[MAXN+1];

void calc_factorial() {
	int64_t tmp = f[0] = 1;
	for (int i=1; i<=MAXN; ++i) {
		f[i] = tmp = (tmp * i) % MOD;
	}
}

int64_t qp(int64_t v, int p) {
	int64_t ans = 1, base = v;
	while (p > 0) {
		ans = (p&1) ? ((ans * base)%MOD) : ans;
		base = (base * base) % MOD;
		p >>= 1;
	}

	return ans;
}

int64_t comb(int n, int m) {
	int64_t tmp = f[n];
	tmp = (tmp * qp(f[m], MOD-2)) % MOD;
	tmp = (tmp * qp(f[n-m], MOD-2)) % MOD;
	return tmp;
}

int main() {
	calc_factorial();
	int n, a, b; scanf("%d%d%d", &n, &a, &b);

	int64_t ans = 0;
	for (int i=min(a, max(n-b, 2)); i<=a && n-i<=b && n-i>=1; ++i) {
		int64_t av = (comb(a-1, i-1) * f[a]) % MOD;
		int64_t bv = (comb(b-1, n-i-1) * f[b]) % MOD;
		av = (av * bv) % MOD;
		av = (av * (i-1)) % MOD;
		ans = (ans + av) % MOD;
	}

	printf("%" PRId64 "\n", ans);
	return 0;
}
