class Solution {
public:
	void dfs(int sta, int end, int len, const vector<int> &nums, vector<int> &buff, vector<vector<int>> &ans) {
		vector<int> tmp(buff.begin(), buff.begin()+len);
		ans.push_back(move(tmp));
		if (sta >= end) { return; }

		int last = nums[sta] - 1;
		for (int i=sta; i<end; ++i) {
			if (nums[i] == last) { continue; }
			buff[len] = last = nums[i];
			dfs(i+1, end, len+1, nums, buff, ans);
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		vector<int> buff(nums.size());
		dfs(0, nums.size(), 0, nums, buff, ans);
		return ans;
	}
};
