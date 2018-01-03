#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
int a[MAXN], sm[MAXN], idx[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0, pre=0; i<n; ++i) {
		scanf("%d", &a[i]);
		pre += a[i];
		sm[i] = pre;
		idx[i] = i;
	}

	sort(idx, idx+n, [](const int &i1, const int &i2) {
		return ::a[i1] > ::a[i2];
	});

	int gain = 0;
	for (int i=0, pre=-1; i<n; ++i) {
		if (idx[i] < pre) { continue; }
		int proceed = (idx[i] - pre) * a[idx[i]];
		int cost = sm[idx[i]] - (pre<0 ? 0 : sm[pre]);
		pre = idx[i];
		gain += proceed - cost;
	}

	printf("%d\n", gain);
	return 0;
}
