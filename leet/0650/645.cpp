class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		int sz = nums.size();
		vector<int> cnt(sz, 0);
		for (int i=0; i<sz; ++i) { ++cnt[nums[i]-1]; }
		vector<int> ans(2);
		for (int i=0; i<sz; ++i) {
			if (cnt[i] == 2) {
				ans[0] = i + 1;
			} else if (cnt[i] == 0) {
				ans[1] = i + 1;
			}
		}

		return ans;
	}
};
