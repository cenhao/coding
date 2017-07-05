class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int sz = nums.size();
		if (sz == 0) { return 1; }
		for (int i=0; i<sz; ++i) {
			while (nums[i] > 0 && nums[i] <= sz && nums[i] != nums[nums[i]-1]) {
				swap(nums[i], nums[nums[i]-1]);
			}
		}
		for (int i=0; i<sz; ++i) {
			if (nums[i] != i+1) { return i+1; }
		}

		return sz+1;
	}
};
