class Solution {
public:
	int mySqrt(int x) {
		int64_t l = 0, r = x;
		while (l <= r) {
			int64_t m = (l + r) >> 1;
			int64_t mul = m * m;
			if (mul <= x) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		return r;
	}
};
