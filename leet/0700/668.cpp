#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findKthNumber(int m, int n, int k) {
		if (n < m) { swap(m, n); }
		int l = 1, r = n * m;
		while (l <= r) {
			int mid = (l + r) >> 1;
			int cnt = 0;
			for (int i=1; i<=m; ++i) {
				cnt += min(n, mid / i);
			}

			if (cnt < k) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		return l;
	}
};

int main() {
	int n, m, k; cin >> n >> m >> k;
	Solution sol;
	cout << sol.findKthNumber(n, m, k) << endl;
	return 0;
}
