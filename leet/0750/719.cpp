class Solution {
public:
	int check(const vector<int> &nums, int sz, int m) {
		int sm = 0;
		for (int i=1, pos=0; i<sz; ++i) {
			while (pos<i && nums[i]-nums[pos] > m) { ++pos; }
			sm += i - pos;
		}
		return sm;
	}

	int smallestDistancePair(vector<int>& nums, int k) {
		int sz = nums.size();
		sort(nums.begin(), nums.end());
		int l = nums[1] - nums[0], r = nums[sz-1] - nums[0];
		for (int i=1; i<sz; ++i) { l = min(l, nums[i]-nums[i-1]); }
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(nums, sz, m) < k) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}

		return l;
	}
};
