#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, n; scanf("%d%d%d%d", &a, &b, &c, &n);
	if (c>a || c>b) {
		printf("-1\n");
		return 0;
	}
	int pass = a + b - c;
	int fail = n - pass;
	if (pass>n || fail>n || fail<1) {
		printf("-1\n");
	} else {
		printf("%d\n", fail);
	}
	return 0;
}
