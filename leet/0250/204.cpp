class Solution {
public:
	int countPrimes(int n) {
		vector<bool> is_prime(n, true);
		vector<int> primes;
		int cnt = 0;
		for (int i=2; i<n; ++i) {
			if (is_prime[i]) {
				++cnt;
				primes.push_back(i);
			}
			for (int j=0; j<primes.size() && i*primes[j]<n; ++j) {
				is_prime[primes[j]*i] = false;
				if (i % primes[j] == 0) { break; }
			}
		}
		return cnt;
	}
};
class Solution {
public:
	int countPrimes(int n) {
		if (n < 2) { return 0; }
		vector<bool> is_prime(n, true);
		int cnt = 1;
		for (int i=3; i<n; i+=2) {
			if (is_prime[i]) {
				++cnt;
				for (int j=i+i; j<n; j+=i) { is_prime[j] = false; }
			}
		}
		return cnt;
	}
};
