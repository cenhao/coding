class Solution {
public:
	int findMin(vector<int>& nums) {
		int sz = nums.size();
		int l = 0, r = sz - 1;
		while (l <= r) {
			int m = (l+r) >> 1;
			if (nums[m] <= nums[sz-1]) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return nums[l];
	}
};
