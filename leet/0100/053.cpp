class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = 0, sz = nums.size(), mx = -0x7fffffff;
		for (int i=0; i<sz; ++i) {
			sum += nums[i];
			mx = max(mx, sum);
			sum = max(0, sum);
		}

		return mx;
	}
};
