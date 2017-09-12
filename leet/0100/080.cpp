class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int sz = nums.size();
		if (sz <= 0) { return sz; }
		int64_t last = nums[0] - 1;
		int cnt = 0, pos = 0;

		for (int i=0; i<sz; ++i) {
			if (nums[i] != last) {
				cnt = 0;
				last = nums[i];
			}

			if (++cnt <= 2) {
				nums[pos++] = nums[i];
			}
		}

		return pos;
	}
};
