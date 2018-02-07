class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int mxg = 0, mn = 0x7fffffff;
		for (auto p : prices) {
			if (p > mn) {
				mxg = max(mxg, p-mn);
			} else {
				mn = p;
			}
		}

		return mxg;
	}
};
