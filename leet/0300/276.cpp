class Solution {
public:
	int numWays(int n, int k) {
		if (n==0 || k==0) { return 0; }
		int same = 0, diff = k;
		for (int i=1; i<n; ++i) {
			int ns = diff, nd = (same+diff) * (k-1);
			same = ns;
			diff = nd;
		}
		return same + diff;
	}
};
