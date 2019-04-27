#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxSumTwoNoOverlap(vector<int>& a, int L, int M) {
		int sz = a.size();
		vector<int> sm(sz, -1);
		for (int i=0, tmp=0; i<sz; ++i) {
			tmp += a[i];
			if (i >= L) { tmp -= a[i-L]; }
			if (i >= L-1) { sm[i] = tmp; }
		}
		vector<int> lmx(sz, -1), rmx(sz, -1);
		for (int i=0, mx=-1; i<sz; ++i) {
			mx = max(mx, sm[i]);
			lmx[i] = mx;
		}
		for (int i=sz-1, mx=-1; i>=0; --i) {
			mx = max(mx, sm[(i+L-1)%sz]);
			rmx[i] = mx;
		}

		int ans = -1;
		for (int i=0, tmp=0; i<sz; ++i) {
			tmp += a[i];
			if (i >= M) { tmp -= a[i-M]; }
			if (i < M-1) { continue; }
			int lidx = i - M;
			int lv = lidx < 0 ? -1 : lmx[lidx];
			int ridx = i + 1;
			int rv = ridx >= sz ? -1 : rmx[ridx];
			ans = max(ans, tmp + max(lv, rv));
		}

		return ans;
	}
};

int main() {
	int n, l, m; cin >> n >> l >> m;
	vector<int> a(n);
	for (int i=0; i<n; ++i) { cin >> a[i]; }
	Solution sol;
	cout << sol.maxSumTwoNoOverlap(a, l, m) << endl;
	return 0;
}
