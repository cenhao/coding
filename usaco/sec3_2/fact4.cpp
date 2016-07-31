/*
ID: cenhao11
PROG: fact4
LANG: C++11
*/

#include <stdio.h>

int main() {
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);

	int n;
	scanf("%d", &n);
	int cnt2 = 0;
	int res = 1;

	for (int i=1; i<=n; ++i) {
		int tmp = i;
		while (tmp % 2 == 0) {
			tmp /= 2;
			++cnt2;
		}
		while (tmp % 5 == 0) {
			tmp /= 5;
			--cnt2;
		}

		res = (res * tmp) % 10;
	}

	if (cnt2 > 0) {
		int v[4] = {2, 4, 8, 6};
		res = (res * v[(cnt2-1) % 4]) % 10;
	}

	printf("%d\n", res);
	return 0;
}
