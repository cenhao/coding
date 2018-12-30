class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		for (int64_t i=1; i<=n; i<<=1) {
			if ((i & n) == 0) {
				m &= ~i;
			} else {
				int tmp = 0x7fffffff & (~i);
				tmp = tmp & n | (i-1);
				if (tmp >= m) { m &= ~i; }
			}
		}

		return m;
	}
};
