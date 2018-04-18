#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define MAXN 100100
#define INF 0x7fffffff
pii itvs[MAXN], nitvs[MAXN+2];
int acc[MAXN+1];

int main() {
	int n, q; scanf("%d%d", &n, &q);
	for (int i=0; i<n; ++i) {
		scanf("%d%d",  &itvs[i].first, &itvs[i].second);
	}

	sort(itvs, itvs+n, [](const pii &p1, const pii &p2) {
		return p1.first==p2.first ? (p1.second<p2.second) : (p1.first<p2.first);
	});

	int cnt = 0, last=0;
	for (int i=0; i<n; ++i) {
		if (itvs[i].first > last) {
			pii tmp = make_pair(last+1, itvs[i].first-1);
			if (tmp.first <= tmp.second) {
				nitvs[cnt++] = tmp;
			}
		}
		last = max(last, itvs[i].second);
	}
	nitvs[cnt++] = make_pair(last+1, INF);
	for (int i=0, sm=0; i<cnt-1; ++i) {
		sm = acc[i] = sm+nitvs[i].second-nitvs[i].first+1;
	}

	for (int i=0; i<q; ++i) {
		int k; scanf("%d", &k);
		int l = 0, r = cnt-1-1;
		while (l <= r) {
			int m = (l+r) >> 1;
			if (acc[m] >= k) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		k -= (l == 0) ? 0 : acc[l-1];
		printf("%d\n", nitvs[l].first+k-1);
	}

	return 0;
}
