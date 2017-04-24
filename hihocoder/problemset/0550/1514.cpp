#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int h[3][MAXN];

int sum(int a, int b, int c) {
	return abs(a-b) + abs(b-c) + abs(c-a);
}

int main() {
	int n[3]; scanf("%d %d %d", &n[0], &n[1], &n[2]);
	for (int i=0; i<3; ++i) {
		for (int j=0; j<n[i]; ++j) { scanf("%d", &h[i][j]); }
		sort(h[i], h[i]+n[i]);
	}

	int mn = sum(h[0][0], h[1][0], h[2][0]), p[3] = {0, 0, 0};
	while (p[0]!=n[0]-1 || p[1]!=n[1]-1 || p[2]!=n[2]-1) {
		int smn = 0x7fffffff, pos;
		for (int i=0; i<3; ++i) {
			if (p[i] == n[i]-1) { continue; }
			++p[i];
			int tmp = sum(h[0][p[0]], h[1][p[1]], h[2][p[2]]);
			--p[i];

			if (tmp < smn) {
				pos = i; smn = tmp;
			}
		}

		++p[pos];
		mn = min(smn, mn);
	}

	printf("%d\n", mn);
	return 0;
}
