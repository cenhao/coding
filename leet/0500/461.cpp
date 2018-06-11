class Solution {
public:
	int hammingDistance(int x, int y) {
		int v = x ^ y, cnt = 0;
		while (v != 0) {
			++cnt;
			v -= v & (~(v-1));
		}
		return cnt;
	}
};
