#include <algorithm>
using namespace std;

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXM 10000

struct Stack {
	int val;
	int cnt;
	bool operator < (const Stack &s) const {
		return val > s.val;
	}
} stacks[MAXM*2];
int scnt;

int a[MAXM], p[MAXM], s[MAXM];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) { scanf("%d", &a[i]); }
	for (int i=0; i<m; ++i) { scanf("%d", &p[i]); }
	for (int i=0; i<m; ++i) { scanf("%d", &s[i]); }

	scnt = 0;
	for (int i=0; i<m; ++i) {
		int sc = a[i] / s[i];
		if (sc > 0) {
			stacks[scnt].val = s[i] * p[i];
			stacks[scnt++].cnt = sc;
		}
		int rc = a[i] % s[i];
		if (rc > 0) {
			stacks[scnt].val = rc * p[i];
			stacks[scnt++].cnt = 1;
		}
	}
	sort(stacks, stacks+scnt);

	int64_t sum = 0LL;
	for (int i=0; i<scnt && n>0; ++i) {
		int take = min(n, stacks[i].cnt);
		sum += take * (int64_t)stacks[i].val;
		n -= take;
	}

	printf("%"PRId64"\n", sum);
	return 0;
}
