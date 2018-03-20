#include <bits/stdc++.h>
using namespace std;

#define INF 0x7fffffff

bool same_direction(int a, int b, int c, int d) {
	int64_t ad = int64_t(a) * d;
	int64_t bc = int64_t(b) * c;
	if (ad != bc) { return false; }
	if (ad != 0) { return true; }
	if (a == c && a == 0) {
		return int64_t(b) * d > 0;
	} else if (b == d && b == 0) {
		return int64_t(a) * c > 0;
	}
	return false;
}

int gcd(int a, int b) {
	while (b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int64_t lcm(int a, int b) {
	if (a == 0 || b == 0) { return 0; }
	int64_t d = gcd(a, b);
	return a / d * b;
}

int calc(int64_t v, int p, int n) {
	if (v > 0) {
		return (n-p) / v;
	} else if (v < 0) {
		return (p-1) / (-v);
	}
	return INF;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	int x, y; scanf("%d%d", &x, &y);
	int a, b; scanf("%d%d", &a, &b);
	int c, d; scanf("%d%d", &c, &d);

	int abv = min(calc(a, x, n), calc(b, y, m));
	abv = abv == INF ? 0 : abv;
	int cdv = min(calc(c, x, n), calc(d, y, m));
	cdv = cdv == INF ? 0 : cdv;
	int adj = 0;
	bool same = same_direction(a, b, c, d);
	if (same) {
		int64_t ac_lcm = lcm(a, c);
		int64_t bd_lcm = lcm(b, d);
		adj = min(calc(ac_lcm, x, n), calc(bd_lcm, y, m));
		adj = adj == INF ? 0 : adj;
	}

	printf("%d\n", abv+cdv-adj+1);
	return 0;
}
