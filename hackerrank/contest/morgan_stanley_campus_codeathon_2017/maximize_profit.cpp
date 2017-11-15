#include <bits/stdc++.h>
using namespace std;

#define MAXN 101
int a[MAXN], b[MAXN];

int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	int mx = m * k;
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }
	for (int i=0; i<n; ++i) { scanf("%d", &b[i]); }
	for (int i=0; i<n; ++i) { mx = max(a[i]*b[i]*m, mx); }
	printf("%d\n", mx);
	return 0;
}
