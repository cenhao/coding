class Solution {
public:
	int rob(const vector<int> &n, int s, int e) {
		int ans = 0, inc = 0, exc = 0;
		for (int i=s; i<e; ++i) {
			int inc1 = exc + n[i];
			exc = max(inc, exc);
			inc = inc1;
			ans = max(ans, inc);
		}
		return ans;
	}
	int rob(vector<int>& nums) {
		int sz = nums.size();
		if (sz <= 1) { return sz == 0 ? 0 : nums[1]; }
		return max(rob(nums, 0, sz-1), rob(nums, 1, sz));
	}
};
