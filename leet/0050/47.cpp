class Solution {
public:
	void dfs(const vector<int> &nums, vector<int> &buff, vector<bool> &vis, vector<vector<int>> &ans, int cur, int sz) {
		if (cur == sz) {
			ans.push_back(buff);
			return ;
		}
		bool first = true;
		int last;
		for (int i=0; i<sz; ++i) {
			if (vis[i]) { continue; }
			if (first || nums[i] != last) {
				first = false;
				last = nums[i];
				vis[i] = true;
				buff[cur] = nums[i];
				dfs(nums, buff, vis, ans, cur+1, sz);
				vis[i] = false;
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		int sz = nums.size();
		vector<vector<int>> ans;
		if (sz <= 0) { return ans; }
		sort(nums.begin(), nums.end());
		vector<int> buff(sz);
		vector<bool> vis(sz, false);
		dfs(nums, buff, vis, ans, 0, sz);
		return ans;
	}
};

