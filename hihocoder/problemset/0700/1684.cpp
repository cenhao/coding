#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
int mxv[MAXN];

int main() {
	int n; scanf("%d", &n);
	int len = 0;
	memset(mxv, 0, sizeof(mxv));
	for (int i=0; i<n; ++i) {
		int v; scanf("%d", &v);
		int l = 0, r = len-1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (mxv[m] >= v) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		mxv[r+1] = max(mxv[r+1], v);
		if (r+1 == len) { ++len; }
	}

	printf("%d\n", n - len);
	return 0;
}
