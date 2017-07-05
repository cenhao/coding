class Solution {
public:
	int search(vector<int>& nums, int target) {
		int sz = nums.size();
		if (sz <= 0) { return -1; }
		int l = 0, r = sz-1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (nums[m] <= nums[sz-1]) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		int end = (r >= sz) ? 0 : r + 1;
		l = 0, r = sz-1;
		while (l <= r) {
			int m = (l+r) >> 1;
			int mm = (m + end) % sz;
			if (nums[mm] < target) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		int idx = (l + end) % sz;
		return (nums[idx] == target) ? idx : -1;
	}
};
