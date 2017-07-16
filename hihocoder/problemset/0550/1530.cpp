#include <bits/stdc++.h>
using namespace std;

#define RNG 40000

bool is_prime[RNG];
int primes[RNG], pcnt = 0;

int get_primes(int mx) {
	int rng = sqrt(mx+1);
	memset(is_prime, true, sizeof(bool) * (rng+1));
	is_prime[0] = is_prime[1] = false;

	for (int64_t i=2; i<=rng; ++i) {
		if (is_prime[i]) { primes[pcnt++] = i; }
		for (int j=0; j<pcnt & i*primes[j]<=rng; ++j) {
			is_prime[i*primes[j]] = false;
			if (i % primes[j] == 0) { break; }
		}
	}

	return pcnt;
}

int my_pow(int a, int n) {
	int base = a, ans = 1;
	while (n > 0) {
		if (n & 1) { ans *= base; }
		base *= base;
		n >>= 1;
	}
	return ans;
}

int my_pow(int a, int n, int mod) {
	int64_t base = a, ans = 1;
	while (n > 0) {
		if (n & 1) { ans = (ans * base) % mod; }
		base = (base*base) % mod;
		n >>= 1;
	}
	return ans;
}

int main() {
	int a, b, p; scanf("%d%d%d", &a, &b, &p);
	get_primes(p);

	int euler = 1;
	for (int i=0; i<pcnt && p!=1; ++i) {
		if (p % primes[i] != 0) { continue; }
		int cnt = 0;
		while (p % primes[i] != 0) {
			p /= primes[i];
			++cnt;
		}

		euler *= my_pow(p, cnt-1) * (p-1);
	}

	if (p != 1) { euler *= p-1; }

	int64_t ans = a;
	ans = (ans * my_pow(b, euler-1, p)) % p;

	printf("%" PRId64 "\n", ans);
	return 0;
}
