class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		int sz = nums.size();
		vector<string> ans;
		if (sz == 0) { return ans; }
		int64_t last = nums[0], start = 0;
		for (int i=0; i<=sz; ++i) {
			if (i==sz || nums[i]>last+1) {
				int cnt = last - nums[start] + 1;
				if (cnt == 1) {
					ans.emplace_back(move(to_string(last)));
				} else {
					ans.emplace_back(move(to_string(nums[start])+"->"+to_string(last)));
				}

				if (i != sz) {
					start = i;
					last = nums[i];
				}
			} else {
				last = nums[i];
			}
		}

		return ans;
	}
};
