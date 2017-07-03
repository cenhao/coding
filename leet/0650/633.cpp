class Solution {
public:
	bool judgeSquareSum(int c) {
		for (int64_t i=0; i*i*2<c; ++i) {
			int r = c - i*i;
			int b = sqrt(r);
			if (b*b + i*i == c) { return true; }
		}

		return false;
	}
};
