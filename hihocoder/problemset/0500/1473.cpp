#include <cstdio>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int l, f, d; scanf("%d %d %d", &l, &f, &d);
		if (f > l || f > d) {
			printf("NO\n");
			continue;
		}

		int g = gcd(l, d);
		if (l-g+f < l) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}
