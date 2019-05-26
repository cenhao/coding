#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
int a[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }
	sort(a, a+n);
	int m = 0;
	for (int i=1; i<n; ++i) {
		if (a[i] != a[m]) { a[++m] = a[i]; }
	}
	int mx = 0;
	for (int i=0, pos=0; i<=m; ++i) {
		while (pos<=m && a[pos]<=a[i]+n-1) { ++pos; }
		mx = max(mx, pos-i);
	}
	printf("%d\n", n - mx);
	return 0;
}
