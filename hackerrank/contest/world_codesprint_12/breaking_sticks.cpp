#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000

bool is_prime[MAXN+1];
int primes[MAXN], pcnt;
int64_t fact[64], fcnt[64];

void init_prime() {
	memset(is_prime, true, sizeof(is_prime));
	pcnt = 0;
	for (int i=2; i<=MAXN; ++i) {
		if (is_prime[i]) { primes[pcnt++] = i; }
		for (int j=0; j<pcnt && i*primes[j]<=MAXN; ++j) {
			is_prime[i*primes[j]] = false;
			if (i % primes[j] == 0) { break; }
		}
	}
}

int main() {
	init_prime();
	int n; scanf("%d", &n);
	int64_t ans = 0;
	for (int i=0; i<n; ++i) {
		int64_t v; scanf("%" SCNd64 "", &v);
		int64_t vv = v;
		int fi = 0;
		for (int j=0; j<pcnt && vv > 1; ++j) {
			if (vv % primes[j] == 0) {
				fact[fi] = primes[j]; fcnt[fi] = 0;
				while (vv % primes[j] == 0) {
					vv /= primes[j];
					++fcnt[fi];
				}
				++fi;
			}
		}

		if (vv > 1) { fact[fi] = vv; fcnt[fi++] = 1; }

		int64_t tmp = 1;
		ans += tmp;
		for (int j=fi-1; j>=0; --j) {
			while (fcnt[j]-- > 0) {
				tmp *= fact[j];
				ans += tmp;
			}
		}
	}

	printf("%" PRId64 "\n", ans);
	return 0;
}
