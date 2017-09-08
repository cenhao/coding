class Solution {
public:
	void sortColors(vector<int>& nums) {
		int cnt[3] = { 0, 0, 0 };
		for (int i=0; i<nums.size(); ++i) { ++cnt[nums[i]]; }
		for (int i=0; i<cnt[0]; ++i) { nums[i] = 0; }
		for (int i=cnt[0], end=cnt[0]+cnt[1]; i<end; ++i) { nums[i] = 1; }
		for (int i=cnt[0]+cnt[1]; i<nums.size(); ++i) { nums[i] = 2; }
	}
};
