class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		set<int> hs;
		int sz = nums.size();
		for (int i=0; i<sz; ++i) {
			if (i > k) { hs.erase(nums[i-k-1]); }
			if (hs.find(nums[i]) != hs.end()) { return true; }
			hs.insert(nums[i]);
		}
		return false;
	}
};
