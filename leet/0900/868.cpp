class Solution {
public:
	int binaryGap(int n) {
		int last = -1, mx = 0;
		for (int i=0; i<32; ++i) {
			if (n & (1<<i)) {
				if (last >= 0) { mx = max(mx, i-last); }
				last = i;
			}
		}

		return mx;
	}
};
