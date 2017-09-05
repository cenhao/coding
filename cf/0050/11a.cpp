#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d; scanf("%d%d", &n, &d);
	int last = 0, ans = 0;
	for (int i=0; i<n; ++i) {
		int b; scanf("%d", &b);
		if (b <= last) {
			int m = (last-b) / d + 1;
			ans += m;
			b += m * d;
		}
		last = b;
	}

	printf("%d\n", ans);
	return 0;
}
