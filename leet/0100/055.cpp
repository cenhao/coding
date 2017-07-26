class Solution {
public:
	bool canJump(vector<int>& nums) {
		int mx = 0, sz = nums.size(), pos;
		for (pos=mx; pos<=min(mx, sz-1); ++pos) {
			mx = max(mx, pos+nums[pos]);
		}

		return pos >= sz;
	}
};
