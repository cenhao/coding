#include <stdio.h>

int d[4], m[4];

void find(int idx, int v, int *res) {
	if (idx == 4) {
		if ((v / 100 < 24) && (v % 100) < 60) {
			int tmp = 60 * (v / 100) + v % 100;
			if (tmp > *res) { *res = tmp; }
		}

		return;
	}

	v *= 10;
	for (int i=0; i<4; ++i) {
		if (m[i] == 0) {
			m[i] = 1;
			find(idx+1, v+d[i], res);
			m[i] = 0;
		}
	}
}

int solve() {
	m[0] = m[1] = m[2] = m[3] = 0;

	int res = -1;
	for (int i=0; i<4; ++i) {
		m[i] = 1;
		find(1, d[i], &res);
		m[i] = 0;
	}

	return res;
}

int main() {
	scanf("%d %d %d %d", &d[0], &d[1], &d[2], &d[3]);
	int res = solve();

	if (res == -1) {
		printf("NOT POSSIBLE\n");
	} else {
		printf("%02d:%02d\n", res / 60, res % 60);
	}
}
