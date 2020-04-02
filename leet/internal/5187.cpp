class Solution {
public:
	int64_t calc(int64_t sz) {
		int64_t base = sz * (sz + 1LL);
		int64_t step = sz * 2 + 1;
		int64_t other = (base+step + base+sz*step) * sz;
		return base + other;
	}

	int minimumPerimeter(int n) {
		int64_t l=1, r=50000;
		while (l <= r) {
			int64_t m = (l + r) / 2;
			int64_t v = calc(m);
			if (v >= n) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		return l * 8;
	}
};
