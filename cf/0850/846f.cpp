#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
int a[MAXN+1];

int main() {
	memset(a, -1, sizeof(a));
	int n; scanf("%d", &n);
	int64_t cnt = 0, sum = 0, pre = -1;
	for (int i=0; i<n; ++i) {
		int v; scanf("%d", &v);
		cnt += 1 + i * 2;
		int64_t cur = 1 + ((pre-1)/2+1)*2;
		cur += (i-a[v]-1) * 2;
		a[v] = i;
		pre = cur;
		sum += cur;
	}

	printf("%.6lf\n", (double)sum / cnt);
	return 0;
}
