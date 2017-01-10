#include <cmath>
#include <cstdio>
using namespace std;

#define CX 50
#define CY 50
#define ESP 10e-8

const double pi = atan2(1, 1) * 4;
const double hpi = atan2(1, 1) * 2;

int main() {
	int t; scanf("%d", &t);
	for (int i=1; i<=t; ++i) {
		int p, x, y; scanf("%d %d %d", &p, &x, &y);
		x -= CX; y -= CY;
		double v = 0;
		if (x != 0 || y != 0) {
			v = atan2(y, x);
			if (v >= ESP + hpi) {
				v = 2 * pi - v + hpi;
			} else {
				v = hpi - v;
			}

			v = v * 100 / (2 * pi);
		}

		bool white = true;

		if (p > 0 && v <= p + ESP) {
			if (x * x + y * y <= 2500) {
				white = false;
			}
		}

		printf("Case #%d: %s\n", i, white ? "white" : "black");
	}

	return 0;
}
