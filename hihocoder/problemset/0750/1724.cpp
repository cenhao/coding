#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
int a[MAXN];

int main() {
	int n, p, q, k;
	scanf("%d%d%d%d", &n, &p, &q, &k);
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }
	sort(a, a+n);
	if (k > 0) { q = (q > 0) ? 1 : 0; }
	int ans = 0;
	for (int i=0; i<q; ++i) { ans -= a[i]; }
	for (int i=q; i<n; ++i) { ans += a[i]; }
	printf("%d\n", ans);
	return 0;
}
