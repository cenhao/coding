#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXN 1000

int a[MAXN];
bool v[MAXN];
int pick[MAXN];

int main() {
	int n; scanf("%d", &n);
	memset(v, 0, sizeof(v));
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }

	int64_t sum = 0LL;
	bool found;
	for (int i=0; i<n; ++i) {
		found = false;
		for (int i1=0; i1<n; ++i1) {
			if (v[i1]) { continue; }
			if (sum + a[i1] >= 0) {
				v[i1] = found = true;
				sum += a[i1];
				pick[i] = i1 + 1;
				break;
			}
		}

		if (!found) { break; }
	}

	if (!found) {
		printf("Impossible\n");
	} else {
		for (int i=0; i<n; ++i) { printf("%d%c", pick[i], (i == n-1) ? '\n' : ' '); }
	}

	return 0;
}
