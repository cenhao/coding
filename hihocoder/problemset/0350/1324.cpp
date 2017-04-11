#include <bits/stdc++.h>
using namespace std;

int order[4][4] = {
	{1, 2, 0, 3}, // up
	{3, 2, 0, 1}, // right
	{3, 0, 2, 1}, // down
	{1, 0, 2, 3} // left
};

int trans[4][4] = {
	{0, 0, 1, 3},
	{2, 1, 0, 1},
	{1, 3, 2, 2},
	{3, 2, 3, 0}
};

int main() {
	int n, x, y; scanf("%d %d %d", &n, &y, &x);

	x = (1<<n) - x; --y;
	int cur = 0;
	int64_t pos = 0;
	while (n--) {
		int N = 1 << n;
		int idx = 0;
		if (x >= N) {
			x -= N;
			idx = 2;
		}

		if (y >= N) {
			y -= N;
			idx += 1;
		}

		pos += order[cur][idx] * (1LL << n) * (1LL << n);
		cur = trans[cur][idx];
	}

	printf("%" PRId64 "\n", pos+1);

	return 0;
}
