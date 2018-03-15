#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
int64_t a[MAXN], sm[MAXN], mn[MAXN];

int main() {
	int n; scanf("%d", &n);
	int64_t pre = 0, mnv = 0;
	for (int i=0; i<n; ++i) {
		scanf("%" SCNd64 "", &a[i]);
		sm[i] = pre += a[i];
		mnv = mn[i] = min(mnv, sm[i]);
	}

	int ans = -1;
	for (int i=n-1; i>0; --i) {
		int ssm = pre - sm[i];
		if (ssm>0 && (mn[i]>=0 || ssm>-mn[i])) {
			ans = (i+2) % n;
			break;
		}
	}

	printf("%d\n", ans);
	return 0;
}
