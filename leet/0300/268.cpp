class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int len = nums.size();
		for (int i=0; i<len; ++i) {
			while (nums[i]!=i && nums[i]<len) {
				swap(nums[i], nums[nums[i]]);
			}
		}
		int ans = len;
		for (int i=0; i<len; ++i) {
			if (nums[i] != i) {
				ans = i;
				break;
			}
		}
		return ans;
	}
};
