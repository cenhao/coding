class Solution {
public:
	int findLHS(vector<int>& nums) {
		int mx = 0;

		unordered_map<int, int> hm;
		for (int i=0; i<nums.size(); ++i) { ++hm[nums[i]]; }
		for (auto &kvp : hm) {
			int l = (hm.find(kvp.first-1) != hm.end()) ? hm[kvp.first-1] : 0;
			int r = (hm.find(kvp.first+1) != hm.end()) ? hm[kvp.first+1] : 0;
			if (l > 0 || r > 0) { mx = max(mx, kvp.second + max(l, r)); }
		}

		return mx;
	}
};
