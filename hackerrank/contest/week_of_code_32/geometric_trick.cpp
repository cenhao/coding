#include <bits/stdc++.h>
using namespace std;

#define MAXN 500000

char s[MAXN+1];
int primes[MAXN], pcnt = 0;
bool is_prime[MAXN+1];
int firstp[MAXN+1]; // first prime factor of the key
uint64_t hv[MAXN+1]; // hash value

void generate_prime(int n) {
	memset(is_prime, true, sizeof(is_prime));
	for (int i=0; i<=n; ++i) {
		if (is_prime[i]) {
			primes[pcnt++] = i;
			firstp[i] = i;
		}
		for (int j=2; j<pcnt && primes[j]*i<=n; ++j) {
			is_prime[i*primes[j]] = false;
			firstp[i*primes[j]] = primes[j];
			if (i % primes[j] == 0) { break; }
		}
	}
}

void generate_hash_value(int n) {
	// something that looks like FNV hashing
	hv[0] = 1;
	for (int i=1; i<=n; ++i) {
		hv[i] = ((hv[i-1]*37 + 123847) << 32) + rand();
	}
}

int main() {
	int n; scanf("%d", &n);
	scanf("%s", s);

	generate_prime(n);
	generate_hash_value(n);

	int ans = 0;
	unordered_map<uint64_t, vector<int>> hlist;
	for (int i=1; i<=n; ++i) {
		if (s[i-1] == 'b') { continue; }

		uint64_t v = 0;
		for (int q=i; q!=1; q/=firstp[q]) { v ^= hv[firstp[q]]; }

		auto it = hlist.find(v);
		if (it == hlist.end()) {
			it = hlist.insert(make_pair(v, move(vector<int>()))).first;
		}

		for (auto idx : it->second) {
			int mid = sqrt(1LL * idx * i);
			if (s[mid-1] == 'b' && (s[i-1] != s[idx-1])) { ++ans; }
		}

		it->second.push_back(i);
	}

	printf("%d\n", ans);
	return 0;
}
