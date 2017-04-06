/*
 * Young's tableaus & hook length formula
 */

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int64_t inverse(int64_t v, int pow) {
	int64_t ans = 1;
	int64_t base = v;
	while (pow > 0) {
		if (pow & 1) { ans = (ans * base) % MOD; }
		base = (base * base) % MOD;
		pow >>= 1;
	}

	return ans;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	int64_t nf = 1;
	int64_t dom = 1;

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			nf = (nf * (i*m + j + 1)) % MOD;
			dom = (dom * (m+n-i-j-1)) % MOD;
		}
	}

	int64_t inv = inverse(dom, MOD-2);
	int64_t ans = (nf * inv) % MOD;
	printf("%" PRId64 "\n", ans);
	return 0;
}
