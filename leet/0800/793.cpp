#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int preimageSizeFZF(int k) {
		int64_t l = 0, r = 0x7ffffffffffffff;
		while (l <= r) {
			int64_t m = (l + r) >> 1;
			int64_t tmp = m, cnt = 0;
			while (tmp > 0) {
				tmp /= 5;
				cnt += tmp;
			}

			if (cnt >= k) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		int64_t sl = l;

		l = 0, r = 0x7ffffffffffffff;
		while (l <= r) {
			int64_t m = (l + r) >> 1;
			int64_t tmp = m, cnt = 0;
			while (tmp > 0) {
				tmp /= 5;
				cnt += tmp;
			}

			if (cnt < k+1) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		int64_t sr = r;
		return sr - sl + 1;
	}
};

int main() {
	int n; cin >> n;
	Solution sol;
	cout << sol.preimageSizeFZF(n) << endl;
	return 0;
}
