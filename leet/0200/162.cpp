class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int l = 0, r = nums.size()-1, sz = nums.size();
		while (l <= r) {
			int m = (l + r) >> 1;

			bool ll = (m!=0 && nums[m-1]>nums[m]);
			bool lr = (m!=sz-1 && nums[m]<nums[m+1]);

			if (ll) {
				r = m - 1;
			} else if (lr) {
				l = m + 1;
			} else {
				return m;
			}
		}

		return -1;
	}
};
