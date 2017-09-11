class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int sz = nums.size();
		if (sz == 0) { return 0; }
		int pre = 1, mx = 1;
		for (int i=1; i<sz; ++i) {
			if (nums[i] <= nums[i-1]) {
				pre = 0;
			}
			++pre;
			mx = max(mx, pre);
		}

		return mx;
	}
};

