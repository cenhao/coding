#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int gcd(int a, int b) {
		while (b != 0) {
			int r = a % b;
			a = b; b = r;
		}
		return a;
	}

	int nthMagicalNumber(int n, int a, int b) {
		if (a > b) { swap(a, b); }
		int d = gcd(a, b);
		int64_t l = 0, r = int64_t(a)*b*n;
		a /= d, b /= d;
		while (l <= r) {
			int64_t m = (l + r) >> 1;
			int64_t ac = m / a, bc = m / b, abc = m / (int64_t(a)*b);
			int64_t sm = ac + bc - abc;
			if (sm >= n) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		int mod = 1000000007;
		int ans = ((l%mod) * d) % mod;
		return ans;
	}
};

int main() {
	int n, a, b; cin >> n >> a >> b;
	Solution sol;
	cout << sol.nthMagicalNumber(n, a, b) << endl;
	return 0;
}
