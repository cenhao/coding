class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1) { return 0; }
		int mn = 0x7fffffff, mx = 0x80000000;
		for (auto n: nums) {
			mn = min(mn, n);
			mx = max(mx, n);
		}

		if (mn == mx) { return 0; }
		int step = (mx-mn) / (len-1) + ((mx-mn)%(len-1) == 0 ? 0 : 1);
		vector<int> mxa(len-1, 0x80000000), mna(len-1, 0x7fffffff);

		for (auto n: nums) {
			int idx = (n-mn) / step;
			if (idx >= len-1) { continue; }
			mxa[idx] = max(mxa[idx], n);
			mna[idx] = min(mna[idx], n);
		}

		int ans = 0x80000000, prev = mn;
		for (int i=0; i<len-1; ++i) {
			if (mxa[i] == 0x80000000) { continue; }
			ans = max(ans, mna[i]-prev);
			prev = mxa[i];
		}

		ans = max(ans, mx - prev);

		return ans;
	}
};
