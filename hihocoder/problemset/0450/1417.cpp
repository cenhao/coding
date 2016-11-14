#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int zcnt[32]; // zero cnt
int ocnt[32]; // one cnt

int main() {
	memset(zcnt, 0, sizeof(zcnt));
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		int a; scanf("%d", &a);
		for (int i1=0; i1<32; ++i1) {
			if ((1<<i1) & a) {
				++ocnt[i1];
			} else {
				++zcnt[i1];
			}
		}
	}

	int64_t sum = 0LL;
	for (int i=0; i<32; ++i) {
		sum += (int64_t)zcnt[i] * ocnt[i];
	}

	printf("%"PRId64"\n", sum);
	return 0;
}
