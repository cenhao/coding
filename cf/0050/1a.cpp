#include <cinttypes>
#include <cstdint>
#include <cstdio>
using namespace std;

int main() {
	int n, m, a; scanf("%d %d %d", &n, &m, &a);
	int64_t v = n / a + ((n % a) ? 1 : 0);
	int64_t h = m / a + ((m % a) ? 1 : 0);
	int64_t ans = v * h;
	printf("%" PRId64 "\n", ans);
	return 0;
}
