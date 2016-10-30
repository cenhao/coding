#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define lowbit(x) (x&(~(x-1)))

int main() {
	int64_t n; scanf("%" SCNd64, &n);
	int cnt = 0;
	while (n > 0LL) {
		int64_t lb = lowbit(n);
		int64_t tmp = n + lb;
		tmp = (tmp - (tmp & n)) / lb;

		if (tmp <= 2LL) { // don't do minus as it doesn't gain
			n -= lb;
		} else { // do minus
			n += lb;
		}

		++cnt;
	}

	printf("%d\n", cnt);
	return 0;
}
