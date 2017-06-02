class Solution {
public:
	int go(int idx, vector<int> &nums, vector<bool> &vis) {
		if (vis[idx]) { return 0; }
		vis[idx] = true;
		return go(nums[idx], nums, vis);
	}

	int arrayNesting(vector<int>& nums) {
		vector<bool> vis(nums.size(), false);
		int mx = 0;
		for (int i=0; i<nums.size(); ++i) {
			if (!vis[i]) { mx = max(mx, go(i, nums, vis)); }
		}

		return mx;
	}
};
