class Solution {
public:
	bool hasZero(int v) {
		while (v != 0) {
			int r = v % 10;
			if (r == 0) { return true; }
			v /= 10;
		}
		return false;
	}
	vector<int> getNoZeroIntegers(int n) {
		for (int i=1; i<n; ++i) {
			if (!hasZero(i) && !hasZero(n-i)) {
				return {i, n-i};
			}
		}
		return {0, 0};
	}
};
