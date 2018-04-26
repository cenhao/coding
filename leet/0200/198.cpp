class Solution {
public:
	int rob(vector<int>& nums) {
		int ans = 0, sz = nums.size();
		int inc = 0, exc = 0;
		for (int i=0; i<sz; ++i) {
			int inc1 = exc + nums[i];
			exc = max(inc, exc);
			inc = inc1;
			ans = max(ans, inc);
		}

		return ans;
	}
};
