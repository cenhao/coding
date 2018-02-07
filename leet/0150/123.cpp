class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int sz = prices.size();
		if (sz <= 1) { return 0; }

		int ans = 0, mxf = 0, mxfa = 0x80000000, mn = 0x7fffffff;
		for (int p : prices) {
			if (p > mn) {
				mxf = max(mxf, p-mn);
			} else {
				mn = p;
			}

			mxfa =max(mxfa, mxf-p);
			ans = max(ans, mxfa+p);
		}

		return ans;
	}
};
