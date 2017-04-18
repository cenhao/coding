#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int plink[MAXN+1][2];
int pcnt[MAXN+1];
int ans[2];

int main() {
	int n; scanf("%d", &n);
	memset(pcnt, 0, sizeof(pcnt));
	for (int i=1; i<=n; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		plink[v][pcnt[v]++] = i;
	}

	bool found = false;
	for (int i=1; i<=n; ++i) {
		if (pcnt[i] > 1) {
			found = true;
			ans[0] = plink[i][0];
			ans[1] = plink[i][1];
		}
	}

	if (found) {
		if (ans[0] > ans[1]) { swap(ans[0], ans[1]); }
		printf("%d %d\n", ans[0], ans[1]);
	} else {
		printf("%d\n", plink[1][0]);
	}

	return 0;
}
