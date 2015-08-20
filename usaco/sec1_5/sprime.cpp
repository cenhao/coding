/*
ID: cenhao11
PROG: sprime
LANG: C++11
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MX 100000000
#define MAX_PRIME_CNT 10000

int primeCnt = 0;
int prime[MAX_PRIME_CNT];
bool isPrime[MAX_PRIME_CNT];

void GenPrime(int end) {
	memset(isPrime, 0xff, sizeof(isPrime));
	isPrime[1] = false;

	for (int i=2; i<end; ++i) {
		if (isPrime[i]) {
			prime[primeCnt++] = i;
			for (int j=i+i; j<MAX_PRIME_CNT; j+=i) {
				isPrime[j] = false;
			}
		}
	}
}

bool TestPrime(int p) {
	int end = int(sqrt(p));
	int idx = 0;

	while (idx < primeCnt && prime[idx] <= end) {
		if (p % prime[idx] == 0) {
			return false;
		}

		++idx;
	}

	return true;
}

void Solve(int p, int n) {
	if (!TestPrime(p)) {
		return;
	}

	if (n == 1) {
		printf("%d\n", p);
	} else {
		for (int i=1; i<10; i+=2) {
			Solve(p*10 + i, n-1);
		}
	}
}

int main() {
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);

	int n;
	scanf("%d", &n);

	int end = 1;
	for (int i=0; i<n; ++i) { end *= 10; }
	GenPrime(int(sqrt(end))+1);

	int p1[] = {2, 3, 5, 7};
	for (auto p : p1) {
		Solve(p, n);
	}

	return 0;
}
