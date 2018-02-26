#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
double p[MAXN][2];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%lf%lf", &p[i][0], &p[i][1]); }
	double dist = 0;
	for (int i=1; i<n; ++i) {
		double dx = p[i][0] - p[i-1][0], dy = p[i][1] - p[i-1][1];
		dist += sqrt(dx*dx + dy*dy);
	}

	dist /= 2.0;
	double x, y;
	for (int i=1; i<n; ++i) {
		double dx = p[i][0] - p[i-1][0], dy = p[i][1] - p[i-1][1];
		double cd = sqrt(dx*dx + dy*dy);
		if (cd >= dist) {
			dx *= dist/cd;
			dy *= dist/cd;
			x = p[i-1][0] + dx;
			y = p[i-1][1] + dy;
			break;
		} else {
			dist -= cd;
		}
	}

	printf("%.1lf %.1lf\n", x, y);
	return 0;
}
