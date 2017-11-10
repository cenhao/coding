#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
struct Stock { int p, d; } s[MAXN];
int ans[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &s[i].p);
		s[i].d = i;
	}

	sort(s, s+n, [](const Stock &s1, const Stock &s2) {
		return s1.p == s2.p ? s1.d > s2.d : s1.p < s2.p;
	});

	set<int> ds;
	int last = -1;
	for (int i=n-1; i>=0; --i) {
		auto it = ds.upper_bound(s[i].d);
		ans[s[i].d] = (it == ds.end()) ? -1 : *it-s[i].d;
		ds.insert(s[i].d);
	}

	for (int i=0; i<n; ++i) { printf("%d\n", ans[i]); }
	return 0;
}
