#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void dfs(const vector<int> &nums, int sta, int pre_v, int len, vector<int> &buff, vector<vector<int>> &ans) {
		if (len >= 2) {
			vector<int> v(len);
			for (int i=0; i<len; ++i) { v[i] = buff[i]; }
			ans.push_back(move(v));
		}

		unordered_set<int> hashset;

		for (int i=sta; i<nums.size(); ++i) {
			if (nums[i] < pre_v || hashset.end() != hashset.find(nums[i])) { continue; }
			hashset.insert(nums[i]);
			buff[len] = nums[i];
			dfs(nums, i+1, nums[i], len+1, buff, ans);
		}
	}

	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<int> buff(nums.size());
		vector<vector<int>> ans;
		dfs(nums, 0, -10000000, 0, buff, ans);
		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; ++i) { cin >> v[i]; }
	Solution sol;
	vector<vector<int>> ans = sol.findSubsequences(v);
	return 0;
}
