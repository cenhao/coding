/*
ID: cenhao11
PROG: fence9
LANG: C++11
*/

/* The problem can be solved with Pick's theorem:
 * if a polygon is constructed with integer coordinates, the points
 * inside the polygon is a, the point on the edge of the polygon is
 * b, the size of the polygon is S, then we have: S = a + b/2 - 1.
 *
 * And it can be proved the the points on a segment is gcd(dx, dy) + 1.
 *
 * But I didn't solved this problem with Pick's theorem as it's a triangle.
 * With some simple calculation we can solve the problem with the gcd above.
 */

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
	while (b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}

int calcPoints(int dx, int dy) {
	if (dx == 0 || dy == 0) { return 0; }

	int squarePoints = (dx+1) * (dy+1); // points in square
	int diagPoints = gcd(dx, dy) + 1; // points in diagonal
	int triPoints = (squarePoints - diagPoints) / 2;// points in triangle
	int points = triPoints - dx - dy + 1;

	return points;
}

int main() {
	freopen("fence9.in", "r", stdin);
	freopen("fence9.out", "w", stdout);

	int n, m, p;
	scanf("%d %d %d", &n, &m, &p);

	int dx, dy, ans;

	int p1 = calcPoints(n, m);
	int p2 = calcPoints(abs(n-p), m);

	if (n == 0) {
		ans = p2;
	} else if (n < p) {
		ans = p1 + p2;
		ans += m - 1;
	} else if (n > p) {
		ans = p1 - p2;
		ans -= gcd(n-p, m) - 1;
	} else {
		ans = p1;
	}

	printf("%d\n", ans);
	return 0;
}
