#include <bits/stdc++.h>
using namespace std;

#define INF 0x7fffffff

int main() {
	int n; scanf("%d", &n);
	int mn[2] = {INF, INF}, smn[2] = {INF, INF}, mnp[2], smnp[2];
	for (int i=0; i<2; ++i) {
		for (int j=0; j<n; ++j) {
			int v; scanf("%d", &v);
			if (v < mn[i]) {
				smn[i] = mn[i]; smnp[i] = mnp[i];
				mn[i] = v; mnp[i] = j;
			} else if (v < smn[i]) {
				smn[i] = v; smnp[i] = j;
			}
		}
	}

	int ans;
	if (mnp[0] != mnp[1]) {
		ans = mn[0] + mn[1];
	} else {
		ans = min(mn[0]+smn[1], smn[0]+mn[1]);
	}

	printf("%d\n", ans);
	return 0;
}
