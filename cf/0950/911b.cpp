#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b; scanf("%d%d%d", &n, &a, &b);
	int l = 1, r = min((a+b)/n, min(a, b));
	while (l <= r) {
		int m = (l + r) / 2;
		int bn = n - a/m;
		if (bn <= 0 || b / bn >= m) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}

	printf("%d\n", r);
	return 0;
}
