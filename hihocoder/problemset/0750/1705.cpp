#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
int pos[MAXN+5];

struct Seat { int p, l, r; };

int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	pos[0] = 0;
	for (int i=1; i<=m; ++i) { scanf("%d", &pos[i]); }
	sort(pos, pos+m);
	auto cmp = [](const Seat &s1, const Seat &s2) {
		int mn1 = min(s1.l, s1.r), mx1 = max(s1.l, s1.r);
		int mn2 = min(s2.l, s2.r), mx2 = max(s2.l, s2.r);
		return mn1 == mn2 ? (mx1 == mx2 ? s1.p > s2.p : mx1 < mx2) : mn1 < mn2;
	};
	priority_queue<Seat, vector<Seat>, decltype(cmp)> pq(cmp);
	for (int i=1; i<=m+1; ++i) {
		int cp = (i == m+1) ? n+1 : pos[i];
		if (cp > pos[i-1]+1) {
			int p = (cp+pos[i-1]) >> 1;
			pq.push({p, p-pos[i-1]-1, cp-p-1});
		}
	}

	for (int i=0; i<k; ++i) {
		Seat s = pq.top(); pq.pop();
		printf("%d\n", s.p);
		if (s.l > 0) {
			int l = s.p - s.l - 1;
			int p = (l + s.p) >> 1;
			pq.push({p, p-l-1, s.p-p-1});
		}
		if (s.r > 0) {
			int r = s.p + s.r + 1;
			int p = (s.p + r) >> 1;
			pq.push({p, p-s.p-1, r-p-1});
		}
	}

	return 0;
}
