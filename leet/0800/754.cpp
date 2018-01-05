class Solution {
public:
	int reachNumber(int target) {
		target = abs(target);
		int64_t l = 0, r = target>>1;
		while (l <= r) {
			int64_t m = (l + r) >> 1;
			if ((1+m)*m/2 >= target) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		int64_t sm = (1+l) * l / 2;
		if (sm == target) { return l; }
		while ((sm & 1) != (target & 1)) {
			sm += ++l;
		}

		return l;
	}
};
