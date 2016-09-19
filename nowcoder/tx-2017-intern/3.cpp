#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 100000

long long a[MAXN+1];
int n;

inline long long calcCn2(long long x) {
	return x * (x-1) / 2;
}

long long processMin() {
	long long mn = 0x8f000000LL;
	long long res = 0;
	for (int i=1; i<n; ++i) { mn = min(a[i]-a[i-1], mn); }

	if (mn == 0) {
		long long last = -1;
		long long cnt = 0;
		a[n] = -2;

		for (int i=0; i<=n; ++i) {
			if (a[i] != last) {
				if (cnt > 1) {
					res += calcCn2(cnt);
				}
				cnt = 1;
				last = a[i];
			} else {
				++cnt;
			}
		}
	} else {
		for (int i=1; i<n; ++i) {
			if (a[i] - a[i-1] == mn) { ++res; }
		}
	}

	return res;
}

long long processMax() {
	long long mx = a[n-1] - a[0];
	if (mx == 0) { return calcCn2(n); }
	long long zcnt = 0, ecnt = 0;
	for (int i=0; i<n; ++i) {
		if (a[i] == a[0]) { ++zcnt; }
		else if (a[i] == a[n-1]) { ++ecnt; }
	}

	return zcnt * ecnt;
}

void process() {
	printf("%lld %lld\n", processMin(), processMax());
}

int main() {
	while (EOF != scanf("%d", &n)) {
		for (int i=0; i<n; ++i) { scanf("%lld", &a[i]); }
		if (n == 1) {
			printf("0 0\n");
			continue;
		}

		sort(a, a+n);
		process();
	}

	return 0;
}
