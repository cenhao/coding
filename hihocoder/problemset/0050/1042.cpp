/* The idea of this solution is that we first transform the pond to the bottom right,
 * so that we can guarantee that if start from the top left corner, the biggest area
 * be covered.
 * Then enumerate the bottom right, and adjust the size and length accordingly,
 * depending on how many corner of the pond is in the area:
 * 1. if there's only one corner, then only the size is reduced.
 * 2. if there're two corners, then size is reduced and length is increased.
 * 3. if all four corners is inside, then only the size is reduced.
 *
 * However, this is not the ultimate solution, for example:
 * 6 9 21 1 6 1 5 should give 19, this solution only gives 18.
 */
#include <stdio.h>

#define ESP 10e-6

int main() {
	int n, m, len; scanf("%d %d %d", &n, &m, &len);
	int l, r, t, b; scanf("%d %d %d %d", &l, &r, &t, &b);

	double mid = m / 2.0;
	double smid = (l + r) / 2.0;
	if (smid + ESP < mid) {
		int tl = m - r, tr = m - l;
		l = tl; r = tr;
	}

	mid = n / 2.0;
	smid = (t + b) / 2.0;
	if (smid + ESP < mid) {
		int tt = n - b, tb = n - t;
		t = tt; b = tb;
	}

	int mx = 0;

	for (int i=1; i<=n; ++i) {
		if (2 * (i+1) > len) { break; }
		for (int j=1; j<=m; ++j) {
			if (2 * (i+j) > len) { break; }

			int size = i * j;
			int length = 2 * (n + m);
			if (i >= b && j >= r) {
				size -= (r-l) * (b-t);
			} else if (j > r && i > t) {
				int extra = 2 * (i - t);
				if (length + extra > len) { continue; }
				size -= (r-l) * (i-t);
			} else if (j > l && i > b) {
				int extra = 2 * (j - l);
				if (length + extra > len) { continue; }
				size -= (j-l) * (b-t);
			} else if (j > l && i > t) {
				size -= (j-l) * (i-t);
			}

			mx = size > mx ? size : mx;
		}
	}

	printf("%d\n", mx);
	return 0;
}
