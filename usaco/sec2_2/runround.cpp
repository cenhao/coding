/*
ID: cenhao11
PROG: runround
LANG: C++11
*/

#include <stdio.h>
#include <string.h>

#define MAXD 10

bool vis[MAXD];
unsigned int roundvis[MAXD];
unsigned int digits[MAXD];

unsigned int build(int mn, int cur, int width, bool *vis, unsigned int *roundvis, unsigned int *digits) {
	if (cur < 0) {
		unsigned int sum = 0;

		for (int i=width-1; i>=0; --i) {
			sum = sum * 10 + digits[i];
		}

		if (sum <= mn) { return 0; }
		int idx = width-1;
		int cnt = 0;
		while (true) {
			roundvis[idx] = sum;
			++cnt;
			idx = ((width + idx) - (digits[idx] % width)) % width;
			if (roundvis[idx] == sum) {
				return (cnt >= width && idx == width-1) ? sum : 0;
			}
		}
	}
	for (int i=1; i<MAXD; ++i) {
		if (!vis[i]) {
			vis[i] = true;
			digits[cur] = i;
			int res = build(mn, cur-1, width, vis, roundvis, digits);
			if (res > 0) { return res; }
			vis[i] = false;
		}
	}

	return 0;
}

unsigned int find(unsigned int m, int width) {
	memset(vis, 0, sizeof(vis));
	return build(m, width-1, width, vis, roundvis, digits);
}

unsigned int process(unsigned int m) {
	int n = m;
	int cnt = 0;

	while (n > 0) {
		++cnt;
		n /= 10;
	}

	unsigned int res;
	for (int i=cnt; ; ++i) {
		if (0 < (res = find(m, i))) {
			return res;
		}
	}

	return 0;
}

int main() {
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);

	unsigned int m;
	scanf("%u", &m);

	printf("%d\n", process(m));

	return 0;
}
