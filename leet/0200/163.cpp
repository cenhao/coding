class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		int64_t l = lower, u = upper;
		int64_t last = l - 1;
		vector<string> ans;
		for (int i=0; i<nums.size(); ++i) {
			if (nums[i] == last) { continue; }
			if (nums[i] != last+1) {
				int64_t cnt  = int64_t(nums[i])-1 - (last+1) + 1;
				if (cnt == 1) {
					ans.push_back(to_string(last+1));
				} else {
					ans.push_back(to_string(last+1) + "->" + to_string(nums[i]-1));
				}
			}
			last = nums[i];
		}

		if (last != u) {
			if (last == u-1) {
				ans.push_back(to_string(u));
			} else {
				ans.push_back(to_string(last+1) + "->" + to_string(upper));
			}
		}
		return ans;
	}
};
