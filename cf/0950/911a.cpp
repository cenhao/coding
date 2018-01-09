#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int mn = 0x7fffffff, pos, ans = 0x7fffffff;
	for (int i=0; i<n; ++i) {
		int a; scanf("%d", &a);
		if (a < mn) {
			mn = a;
			pos = i;
			ans = 0x7fffffff;
		} else if (a == mn) {
			ans = min(ans, i-pos);
			pos = i;
		}
	}

	printf("%d\n", ans);
	return 0;
}
