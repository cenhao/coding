#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define MAXN 200000
#define GA(x, y) (a[(x)*m+(y)])
int a[MAXN], pos[MAXN];;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) {
		int base = i * m;
		for (int j=0; j<m; ++j) { scanf("%d", &a[base+j]); }
	}
	for (int i=0; i<n; ++i) {
		int base = i * m, *ptr = &a[base];
		sort(ptr, ptr+m);
	}

	auto cmp_lt = [](const pii &p1, const pii &p2) {
		return p1.first < p2.first;
	};
	auto cmp_gt = [](const pii &p1, const pii &p2) {
		return p1.first > p2.first;
	};

	priority_queue<pii, vector<pii>, decltype(cmp_gt)> pqmn(cmp_gt);
	priority_queue<pii, vector<pii>, decltype(cmp_lt)> pqmx(cmp_lt);
	for (int i=0; i<n; ++i) {
		pos[i] = m-1;
		pqmn.push(make_pair(GA(i, m-1), i));
		pqmx.push(make_pair(GA(i, m-1), i));
	}

	int ans = 0x7fffffff;
	while (true) {
		auto cmn = pqmn.top();
		while (cmn.first != GA(cmn.second, pos[cmn.second])) {
			pqmn.pop();
			cmn = pqmn.top();
		}
		auto cmx = pqmx.top(); pqmx.pop();
		ans = min(ans, cmx.first-cmn.first);
		if (pos[cmx.second] == 0) { break; }
		--pos[cmx.second];
		pqmx.push(make_pair(GA(cmx.second, pos[cmx.second]), cmx.second));
		pqmn.push(make_pair(GA(cmx.second, pos[cmx.second]), cmx.second));
	}

	printf("%d\n", ans);
	return 0;
}
