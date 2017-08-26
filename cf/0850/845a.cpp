#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
int a[MAXN*2];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n*2; ++i) { scanf("%d", &a[i]); }
	sort(a, a+n*2);
	printf("%s\n", (a[n] > a[n-1]) ? "YES" : "NO");
	return 0;
}
