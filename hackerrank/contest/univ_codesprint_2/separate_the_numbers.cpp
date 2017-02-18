#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXS 32
#define MAXHS 17
char buff[MAXS+1];

int64_t find(char *buff, int start, int len, int64_t pre) {
	if (start >= len || buff[start] == '0') { return 0; }

	for (int i=1; start+i<=len && i<MAXHS; ++i) {
		if (pre == -1 && start+i == len) { return 0LL; }

		int64_t sum = 0;
		for (int j=start; j<start+i; ++j) {
			sum = sum * 10 + buff[j]-'0';
		}

		if (pre == -1 || sum == pre+1) {
			if (start+i == len || sum+1 == find(buff, start+i, len, sum)) {
				return sum;
			}
		}

		if (pre >= 0 && sum > pre + 1) { return 0LL; }
	}

	return 0LL;
}

int main() {
	int q; scanf("%d", &q);
	for (int i=0; i<q; ++i) {
		scanf("%s", buff);
		int len = strlen(buff);
		int64_t x = find(buff, 0, len, -1);
		if (x > 0) {
			printf("YES %" PRId64 "\n", x);
		} else {
			printf("NO\n");
		}
	}

	return 0;
}
