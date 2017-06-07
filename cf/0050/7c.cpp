#include <bits/stdc++.h>
using namespace std;

int egcd(int a, int b, int &s, int &t) {
	if (b == 0) {
		s = 1; t = 0;
		return a;
	}

	int r = egcd(b, a % b, s, t);
	int tmp = s;
	s = t;
	t = tmp - a/b * t;
	return r;
}

int main() {
	int a, b, c; scanf("%d %d %d", &a, &b, &c);

	int64_t x, y;
	bool possible = false;
	if (a == 0) {
		if (c % b == 0) {
			possible = true;
			x = 0; y = -c / b;
		}
	} else if (b == 0) {
		if (c % a == 0) {
			possible = true;
			y = 0; x = -c / a;
		}
	} else {
		int s, t;
		int g = egcd(a, b, s, t);
		if (c % g == 0) {
			possible = true;
			x = 1LL * s * (-c) / g; y = 1LL * t * (-c) / g;
		}
	}

	if (possible) {
		printf("%" PRId64 " %" PRId64 "\n", x, y);
	} else {
		printf("-1\n");
	}

	return 0;
}
