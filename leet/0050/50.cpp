class Solution {
public:
	double myPow(double x, int n) {
		double ans = 1.0, base = x;
		bool rev = (n < 0);
		int64_t nn = abs(int64_t(n));
		while (nn != 0) {
			if (nn & 1) {
				ans *= base;
			}
			nn >>= 1;
			base *= base;
		}

		return rev ? 1/ans : ans;
	}
};
