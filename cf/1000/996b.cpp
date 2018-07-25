#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int mx = -1, pick;
	for (int i=0; i<n; ++i) {
		int v; scanf("%d", &v);
		int r = (v-i+n-1) / n;
		if (mx==-1 || r<mx) {
			mx = r;
			pick = i;
		}
	}

	printf("%d\n", pick+1);
	return 0;
}
