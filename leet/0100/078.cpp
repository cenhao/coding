class Solution {
public:
	void dfs(const vector<int> &nums, int start, int len, vector<int> &buff, vector<vector<int>> &ans) {
		if (len > nums.size()) { return; }
		for (int i=start; i<nums.size(); ++i) {
			buff[len] = nums[i];
			vector<int> cur(buff.begin(), buff.begin()+(len+1));
			ans.push_back(move(cur));
			dfs(nums, i+1, len+1, buff, ans);
		}
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ans(1, vector<int>());
		vector<int> buff(nums.size());
		dfs(nums, 0, 0, buff, ans);
		return ans;
	}
};
