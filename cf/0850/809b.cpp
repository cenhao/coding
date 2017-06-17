#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	int l = 1, r = n-1;
	char ans[4];

	while (l <= r) {
		int m = (l + r) / 2;
		printf("1 %d %d\n", m, m+1);
		fflush(stdout);
		scanf("%s", ans);
		if (ans[0] == 'T') {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	int v1 = l, v2 = -1;
	if (v1 < n) {
		l = l + 1, r = n-1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (m == n) { break; }
			printf("1 %d %d\n", m+1, m);
			fflush(stdout);
			scanf("%s", ans);
			if (ans[0] == 'T') {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		printf("1 %d %d\n", l, v1);
		fflush(stdout);
		scanf("%s", ans);
		if (ans[0] == 'T') { v2 = l; }
	}

	if (v2 < 0) {
		l = 1, r = v1 - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			printf("1 %d %d\n", m, m+1);
			fflush(stdout);
			scanf("%s", ans);
			if (ans[0] == 'T') {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		v2 = l;
	}

	printf("2 %d %d\n", v1, v2);
	fflush(stdout);

	return 0;
}
