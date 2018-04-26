class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int sz = nums.size();
		vector<pair<int, int>> q(sz);
		int h = 0, r = 0;
		vector<int> ans;
		for (int i=0; i<sz; ++i) {
			while (h != r && q[h].second<=i-k) { ++h; }
			while (h != r && q[r-1].first<=nums[i]) { --r; }
			q[r++] = make_pair(nums[i], i);
			if (i >= k) { ans.push_back(q[h].first); }
		}
		return ans;
	}
};
