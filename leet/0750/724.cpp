class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int sm = 0, sz = nums.size();
		for (int i=0; i<sz; ++i) { sm += nums[i]; }
		int cur = 0;
		for (int i=0; i<sz; ++i) {
			if (sm - nums[i] - cur == cur) { return i; }
			cur += nums[i];
		}

		return -1;
	}
};
