class Solution {
public:
	int gcd(int a, int b) {
		while (b != 0) {
			int tmp = b;
			b = a % b;
			a = tmp;;
		}

		return a;
	}
	int64_t lcm(int a, int b) {
		int64_t d = gcd(a, b);
		return a / d * b;
	}
	int count(int v, int a, int b, int c, int64_t ab, int64_t ac, int64_t bc, int64_t abc) {
		return v/a + v/b + v/c - v/ab - v/ac - v/bc + v/abc; 
	}
	int nthUglyNumber(int n, int a, int b, int c) {
		int64_t dab = lcm(a, b);
		int64_t dac = lcm(a, c);
		int64_t dbc = lcm(b, c);
		int64_t dabc = lcm(dab, c);
		int64_t l = 1, r = 2000000000;
		while (l <= r) {
			int m = (l + r) / 2;
			int cnt = count(m, a, b, c, dab, dac, dbc, dabc);
			if (cnt < n) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		return l;
	}
};
