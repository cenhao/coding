#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	struct Frac { int num, dom; };
	int find(int tar, int s, int e, vector<int> &a) {
		int l = s, r = e;
		while (l <= r) {
			int m = (l+r) >> 1;
			if (a[m] <= tar) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		return r;
	}
	vector<int> kthSmallestPrimeFraction(vector<int>& a, int K) {
		int sz = a.size();
		const double eps = 1e-7;
		sort(a.begin(), a.end());
		double l = 0, r = 1;
		for (int i=0; i<50; ++i) {
			double m = (l+r) / 2;
			int cnt = 0;
			for (int j=1; j<sz; ++j) {
				int tar = a[j] * m;
				cnt += find(tar, 0, j-1, a) + 1;
			}

			if (cnt < K) {
				l = m;
			} else {
				r = m;
			}
		}

		int cnt = 0;
		vector<Frac> fv;
		for (int i=1; i<sz; ++i) {
			int tar = a[i] * l;
			int sr = find(tar, 0, i-1, a);
			cnt += sr + 1;
			if (sr + 1 < i) { fv.push_back({a[sr+1], a[i]}); }
		}
		sort(fv.begin(), fv.end(), [](const Frac &f1, const Frac &f2) {
			return f1.num * f2.dom < f1.dom * f2.num;
		});

		vector<int> ans = { fv[K-cnt-1].num, fv[K-cnt-1].dom };
		return ans;
	}
};

int main() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int i=0; i<n; ++i) { cin >> v[i]; }
	Solution sol;
	vector<int> ans = sol.kthSmallestPrimeFraction(v, k);
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}
