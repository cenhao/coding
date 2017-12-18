#include <bits/stdc++.h>
using namespace std;

#define MAXN 50
int h[MAXN];

int main() {
	int T; scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		int n; scanf("%d", &n);
		for (int i=0; i<n; ++i) { scanf("%d", &h[i]); }
		sort(h, h+n);
		int ans = 0;
		for (int i=1; i<n; ++i) { ans += h[i] - h[i-1]; }
		printf("%d\n", ans);
	}

	return 0;
}
