class Solution {
public:
	void dfs(const vector<int>& arr, int sz, int sum, int start, int tar, int pos, vector<int> &buff, vector<vector<int>> &ans) {
		if (sum > tar) { return; }
		if (sum == tar && pos > 0) {
			vector<int> tmp(pos);
			for (int i=0; i<pos; ++i) { tmp[i] = buff[i]; }
			ans.push_back(move(tmp));
		}
		bool first = true;
		int last;
		for (int i=start; i<sz; ++i) {
			if (!first && arr[i] == last) { continue; }
			first = false;
			last = arr[i];
			buff[pos] = arr[i];
			dfs(arr, sz, sum+arr[i], i+1, tar, pos+1, buff, ans);
		}
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		int sz = candidates.size();
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> ans;
		vector<int> buff(sz);
		dfs(candidates, sz, 0, 0, target, 0, buff, ans);
		return ans;
    }
};
