#include <bits/stdc++.h>
using namespace std;

#define MAXN 50
int paid[MAXN+1];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	memset(paid, 0, sizeof(paid));
	int sum = 0;
	for (int i=0; i<n; ++i) {
		int id, v; scanf("%d%d", &id, &v);
		sum += v;
		paid[id] += v;
	}

	int avg = sum / m;
	paid[1] -= sum - avg * m;
	for (int i=1; i<=m; ++i) {
		printf("%d %d\n", i, paid[i]-avg);
	}

	return 0;
}
