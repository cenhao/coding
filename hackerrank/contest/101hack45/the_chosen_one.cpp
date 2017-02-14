#include <cinttypes>
#include <cstdint>
#include <cstdio>
using namespace std;

#define MAXN 500000

int64_t a[MAXN], b[MAXN];

int64_t gcd(int64_t a, int64_t b) {
	while (b != 0) {
		int64_t tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%" SCNd64 "", &a[i]);
		b[i] = a[i];
	}

	if (n <= 2) {
		printf("%" PRId64 "\n", a[0] + ((n==1) ? 1 : 0));
		return 0;
	}

	int pos;
	while (true) {
		int64_t tmp = b[0];
		for (pos=1; pos<n; ++pos) {
			tmp = gcd(tmp, b[pos]);
			if (tmp == 1) { break; }
		}

		if (tmp == 1) {
			if (pos == 1 && gcd(b[1], b[2]) != 1) { pos = 0; }
			a[pos] = (pos == 0) ? a[1] : a[pos-1];
			tmp = a[0];
			for (int i=1; i<n; ++i) { tmp = gcd(tmp, a[i]); }
			printf("%" PRId64 "\n", tmp);
			break;
		}

		for (int i=0; i<n; ++i) { b[i] /= tmp; }
	}

	return 0;
}
