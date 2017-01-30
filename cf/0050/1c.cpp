#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

#define EPS 1e-3 /* why so low */
const double PI = 4 * atan2(1, 1);

double dist(double a, double b) {
	return sqrt(a*a+b*b);
}

double calc_angle(double a, double b, double c) {
	double cos_c = (c*c-a*a-b*b) / (-2*a*b);
	return acos(cos_c);
}

double fgcd(double a, double b) {
	while (fabs(b) > EPS) {
		double tmp = fmod(a, b);
		a = b; b = tmp;
	}

	return a;
}

int main() {
	double x[3], y[3], d[3], p = 0;
	for (int i=0; i<3; ++i) { scanf("%lf %lf", &x[i], &y[i]); }
	for (int i=0; i<3; ++i) {
		int ii = (i+1) % 3;
		d[i] = dist(x[i]-x[ii], y[i]-y[ii]);
		p += d[i];
	}

	p /= 2.0;
	double s = sqrt(p*(p-d[0])*(p-d[1])*(p-d[2]));
	double r = d[0]*d[1]*d[2] / (s*4);

	double a[3];
	for (int i=0; i<3; ++i) {
		a[i] = calc_angle(r, r, d[i]);
	}

	a[2] = 2*PI - a[0] - a[1];
	double angle = fgcd(a[0], fgcd(a[1], a[2]));
	printf("%.6lf\n", r * r * sin(angle) * PI / angle);

	return 0;
}
