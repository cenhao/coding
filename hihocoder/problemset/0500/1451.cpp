/*
 * for n >= 16, f(n) = f(n-5) * 4
 * http://oeis.org/
 */

#include <cinttypes>
#include <cstdint>
#include <cstdio>
using namespace std;

#define MOD 1000000007LL

const int table[16] = {0, 1, 2, 3, 4, 5, 6, 9, 12, 16, 20, 27, 36, 48, 64, 81};

int main() {
	int n;
	while (EOF != scanf("%d", &n)) {
		if (n < 16) {
			printf("%d\n", table[n]);
			continue;
		}

		int off = n - 15;
		int exp = off / 5 + ((off % 5 == 0) ? 0 : 1);
		int64_t pw = 4, v = table[n - exp*5];

		while (exp > 0) {
			if (exp & 1) { v = (v * pw) % MOD; }
			exp >>= 1;
			pw = (pw * pw) % MOD;
		}

		printf("%" PRId64 "\n", v);
	}

	return 0;
}
