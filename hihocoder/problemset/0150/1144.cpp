#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	if (m > n+1) {
		printf("NO\n");
		return 0;
	}

	if (m == n+1) {
		printf("1");
		--m;
	}

	while (m > 0) {
		--m; --n;
		printf("01");
	}

	for (int i=0; i<n; ++i) { printf("0"); }
	printf("\n");

	return 0;
}
