#include <bits/stdc++.h>
using namespace std;

#define MAXN 45
int t[MAXN];

int main() {
	int n, k, m; scanf("%d%d%d", &n, &k, &m);
	int sum = 0;
	for (int i=0; i<k; ++i) {
		scanf("%d", &t[i]);
		sum += t[i];
	}
	sort(t, t+k);

	int mx = 0;
	for (int i=0; i<=n && i*sum<=m; ++i) {
		int full_score = (k+1) * i;
		int rm = m - i*sum, rn = n - i;

		for (int j=0; j<k && t[j] <= rm; ++j) {
			int take = min(rn, rm / t[j]);
			rm -= take * t[j];
			full_score += take;
		}

		mx = max(mx, full_score);
	}

	printf("%d\n", mx);
	return 0;
}
