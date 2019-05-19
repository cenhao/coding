#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> numMovesStonesII(vector<int>& sto) {
		int sz = sto.size();
		sort(sto.begin(), sto.end());
		if (sz == sto[sz-1]-sto[0]+1) { return vector<int> {0, 0}; }
		int mn = 0x7fffffff;
		for (int i=0; i<sz; ++i) {
			int st = sto[i], ed = sto[i] + sz - 1;
			auto sit = lower_bound(sto.begin(), sto.end(), st);
			auto eit = upper_bound(sit, sto.end(), ed);
			auto pit = prev(eit);
			int v = distance(sit, eit);
			if (v == sz-1 && *pit-*sit+1 == sz-1) {
				v = 2;
			} else {
				v = sz - v;
			}
			mn = min(mn, v);
			st = sto[i] - sz + 1, ed = sto[i];
			sit = lower_bound(sto.begin(), sto.end(), st);
			eit = upper_bound(sit, sto.end(), ed);
			pit = prev(eit);
			v = distance(sit, eit);
			if (v == sz-1 && *pit-*sit+1 == sz-1) {
				v = 2;
			} else {
				v = sz - v;
			}
			mn = min(mn, v);
		}

		int ldist = sto[1] - sto[0], rdist = sto[sz-1] - sto[sz-2];
		int l, r;
		if (ldist <= rdist) {
			l = sto[1], r = sto[sz-1];
		} else {
			l = sto[0], r = sto[sz-2];
		}
		int mx = r - l + 1 - sz + 1;
		return vector<int>{mn, mx};
	}
};

int main() {
	int n; cin >> n;
	vector<int> sto(n);
	for (int i=0; i<n; ++i) { cin >> sto[i]; }
	Solution sol;
	auto ans = sol.numMovesStonesII(sto);
	cout << ans[0] << ' ' << ans[1] << endl;
	return 0;
}
