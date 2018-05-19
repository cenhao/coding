class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0) { return false; }
		int lb = n & (~(n-1));
		return lb == n;
	}
};
