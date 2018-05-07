class Solution {
public:
	int findMin(vector<int>& nums) {
		int sz = nums.size();
		int l = 0, r = sz-1;
		while (nums[l] == nums[r]) { --r; }
		int ed = r;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (nums[m] <= nums[ed]) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		return nums[l];
	}
};
