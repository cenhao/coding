class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int sz = nums.size();
		vector<int> ans(2, -1);
		if (sz <= 0) { return ans; }

		int l = 0, r = sz - 1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (nums[m] >= target) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		if (l >= sz || nums[l] != target) { return ans; }
		ans[0] = l;

		l = 0; r = sz - 1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (nums[m] < target + 1) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		ans[1] = r;
		return ans;
	}
};
