#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	unordered_map<int, int> hm;
	int mxs = 0;
	for (int i=0; i<n; ++i) {
		int sum = 0, m; scanf("%d", &m);
		for (int j=0; j<m; ++j) {
			int v; scanf("%d", &v);
			sum += v;
			++hm[sum];
		}

		mxs = max(mxs, sum);
	}

	int mx = 0;
	for (auto &ent : hm) {
		if (ent.first != mxs) { mx = max(mx, ent.second); }
	}

	printf("%d\n", n-mx);

	return 0;
}
