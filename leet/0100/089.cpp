class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans(1 << n);
		ans[0] = 0;
		for (int i=1; i<=n; ++i) {
			int sta = 1 << (i-1);
			for (int i=0; i<sta; ++i) {
				ans[sta+i] = sta | ans[sta-i-1];
			}
		}

		return ans;
	}
};
