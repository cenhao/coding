#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int bars[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &bars[i]); }
	int l = 0, r = n-1, lsum = 0, rsum = 0;

	while (l <= r) {
		if (lsum <= rsum) {
			lsum += bars[l++];
		} else {
			rsum += bars[r--];
		}
	}

	printf("%d %d\n", l, n-l);
	return 0;
}
