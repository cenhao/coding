/*
ID: cenhao11
PROG: pprime
LANG: C++11
*/

#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAXL 10
#define MAXP 10001
int palGen[MAXL];
int prime[MAXP];
int primeCnt;
bool isPrime[MAXP];

void generatePrime(int end) {
	memset(isPrime, 1, sizeof(isPrime));
	primeCnt = 0;

	for (int i=2; i<=end; ++i) {
		if (isPrime[i]) { prime[primeCnt++] = i; }
		for (int j=i+i; j<=end; j+=i) { isPrime[j] = false; }
	}
}

bool checkPrime(int num) {
	int end = int(sqrt(num));

	int idx = 0;
	while (idx < primeCnt && prime[idx] <= end) {
		if (num % prime[idx] == 0) { return false; }
		++idx;
	}

	return true;
}

int printPalPrime(int base, int startPoint, int start, int end) {
	if (startPoint >= (base+1) / 2) {
		int sum = 0;
		for (int i=0; i<base; ++i) {
			sum *= 10;
			sum += palGen[i];
		}

		if (sum > end) { return -1; }
		if (sum >= start && checkPrime(sum)) {
			printf("%d\n", sum);
		}
		return 0;
	}

	for (int i=(startPoint==0)?1:0; i<=9; ++i) {
		palGen[startPoint] = palGen[base-startPoint-1] = i;
		if (-1 == printPalPrime(base, startPoint+1, start, end)) {
			return -1;
		}
	}

	return 0;
}

void solve(int start, int end) {
	int startBase = 1;
	for (int chk=1; chk*10<start; chk*=10) { ++startBase; }
	int endBase = 1;
	for (int chk=1; chk<end; chk*=10) { ++endBase; }
	for (int i=startBase; i<endBase; ++i) {
		printPalPrime(i, 0, start, end);
	}
}

int main()
{
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);

	int a, b;
	scanf("%d%d", &a, &b);

	generatePrime(int(sqrt(b)));
	solve(a, b);
	return 0;
}
