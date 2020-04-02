class Solution {
public:
	int minFlips(int a, int b, int c) {
		int cnt = 0;
		for (int i=0; i<32; ++i) {
			int target = c & (1<<i);
			int cur = (a|b) & (1<<i);
			if (target != cur) {
				if (target == 0) {
					cnt += ((a&b) & (1<<i)) == 0 ? 1 : 2;
				} else {
					++cnt;
				}
			}
		}
		return cnt;
	}
};
