class Solution {
public:
	int threeSumSmaller(vector<int>& nums, int tar) {
		int sz = nums.size();
		if (sz == 0) { return 0; }
		vector<int> idx(sz);
		for (int i=0; i<sz; ++i) { idx[i] = i; }
		sort(idx.begin(), idx.end(), [&nums](int i1, int i2) {
			return nums[i1] < nums[i2];
		});

		int ans = 0;
		for (int i=0; i<sz-2; ++i) {
			int l=i+1, r=sz-1;
			while (l < r) {
				int v = nums[idx[i]] + nums[idx[l]] + nums[idx[r]];
				if (v >= tar) {
					--r;
				} else {
					ans += r - l;
					++l;
				}
			}
		}

		return ans;
	}
};
