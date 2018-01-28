#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool possible(vector<int> &s, int len, int k, double m) {
		int cnt = 0;
		for (int i=1; i<len && cnt<=k; ++i) {
			int d = s[i] - s[i-1];
			double need = d / m;
			if (need > 1+(1e-7)) {
				cnt += ceil(need) - 1;
			}
		}

		return cnt <= k;
	}
	double minmaxGasDist(vector<int>& s, int K) {
		sort(s.begin(), s.end());
		const double eps = 1e-7;
		int len = s.size(), mx = 0;
		for (int i=1; i<len; ++i) { mx = max(mx, s[i]-s[i-1]); }
		double l = 0.0, r = mx;
		while (l+eps <= r) {
			double m = (l+r) / 2;

			if (possible(s, len, K, m)) {
				r = m;
			} else {
				l = m;
			}
		}

		return l;
	}
};

int main() {
	int n, k; cin >> n >> k;
	vector<int> v(n); for (int i=0; i<n; ++i) { cin >> v[i]; }
	Solution sol;
	cout << sol.minmaxGasDist(v, k) << endl;
	return 0;
}
