#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define EPS 1e-5

bool within_square(int x, int y, bool simple, double k1, double k2, int x1, int y1, int x3, int y3) {
	if (simple) {
		return (x <= max(x1, x3) && x >= min(x1, x3) &&
				y <= max(y1, y3) && y >= min(y1, y3));
	}

	static double c1 = y1 - k1 * x1;
	static double c2 = y3 - k1 * x3;
	static double c12 = fabs(c1 - c2);

	double d1 = fabs(k1*x-y+c1);
	double d2 = fabs(k1*x-y+c2);
	if (d1 + d2 - EPS > c12) { return false; }

	static double c3 = y1 - k2 * x1;
	static double c4 = y3 - k2 * x3;
	static double c34 = fabs(c3 - c4);

	double d3 = fabs(k2*x-y+c3);
	double d4 = fabs(k2*x-y+c4);
	if (d3 + d4 - EPS > c34) { return false; }

	return true;
}

int main() {
	int w, h; scanf("%d %d", &w, &h);
	int xc, yc, r; scanf("%d %d %d", &xc, &yc, &r);
	int x1, y1, x3, y3; scanf("%d %d %d %d", &x1, &y1, &x3, &y3);
	if (x1 > x3) {
		swap(x1, x3);
		swap(y1, y3);
	} else if (x1 == x3 && y1 > y3) {
		swap(y1, y3);
	}

	bool simple = abs(x3 - x1) == abs(y3 - y1);
	double k1, k2;
	if (!simple) {
		k1 = tan(atan2(double(y3-y1), double(x3-x1)) + atan2(1.0, 1.0));
		k2 = tan(atan2(double(y3-y1), double(x3-x1)) - atan2(1.0, 1.0));
	}

	int r2 = r * r;
	for (int i=0; i<h; ++i) {
		for (int j=0; j<w; ++j) {
			if ((j-xc) * (j-xc) + (i-yc) * (i-yc) <= r2) {
				printf("#");
			} else if (within_square(j, i, simple, k1, k2, x1, y1, x3, y3)) {
				printf("#");
			} else {
				printf(".");
			}
		}
		printf("\n");
	}

	return 0;
}
