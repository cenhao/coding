class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		int sz = nums.size();
		vector<int> dp(target+1, 0);
		sort(nums.begin(), nums.end());
		dp[0] = 1;
		for (int i=0; i<target; ++i) {
			for (int j=0; j<sz && i+nums[j]<=target; ++j) {
				dp[i+nums[j]] += dp[i];
			}
		}

		return dp[target];
	}
};
