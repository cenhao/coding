#include <math.h>
#include <stdio.h>

#define MAXN 1000
#define ESP 10e-3
#define RESP 10e-8

int stations[MAXN];

int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	for (int i=0; i<n; ++i) { scanf("%d", &stations[i]); }

	double l = 0, r = m;
	while (r - l >= ESP) {
		int left = k;
		double md = (l + r) / 2.0;

		for (int i=1; i<n; ++i) {
			int need = ceil((stations[i]-stations[i-1]) / md - RESP) - 1;
			left -= need < 0 ? 0 : need;
			if (left < 0) { break; }
		}

		if (left >= 0) {
			r = md;
		} else {
			l = md;
		}
	}

	printf("%.1lf\n", (l+r)/2.0);

	return 0;
}
