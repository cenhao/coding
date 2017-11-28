#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}

	return a;
}

int main() {
	int n; scanf("%d", &n);
	int sm = 0;
	for (int i=2; i<n; ++i) {
		int t = n;
		while (t > 0) {
			sm += t % i;
			t /= i;
		}
	}

	int d = gcd(sm, n-2);
	printf("%d/%d\n", sm/d, (n-2)/d);
	return 0;
}
