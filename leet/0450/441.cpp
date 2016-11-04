#include <cmath>

class Solution {
	public:
		const double esp = 0.000005;
		int arrangeCoins(int n) {
			double d = n;
			return int((sqrt(8*d + 1) - 1) / 2 + esp);
		}
};
