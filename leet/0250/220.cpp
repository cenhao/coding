class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int sz = nums.size();
		map<int64_t, int> hm;
		for (int i=0, l=0, r=0; i<sz; ++i) {
			while (r-i<=k && r<sz) { ++hm[nums[r++]]; }
			while (i-l>k) {
				int v = nums[l++];
				auto it = hm.find(v);
				if (--it->second == 0) {
					hm.erase(it);
				}
			}
			auto it = hm.find(nums[i]);
			if (it->second > 1) { return 0 <= t; }
			auto nit = next(it);
			if (nit != hm.end()) {
				if (abs(nit->first-nums[i]) <= t) { return true; }
			}
			if (it != hm.begin()) {
				auto pit = prev(it);
				if (abs(pit->first-nums[i]) <= t) { return true; }
			}
		}

		return false;
	}
};
