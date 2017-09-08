class Solution {
public:
	void dfs(int s, int e, int cnt, vector<int> &buff, vector<vector<int>> &ans) {
		if (cnt >= buff.size()) {
			ans.push_back(buff);
			return;
		}

		for (int i=s; i<=e-(buff.size()-cnt)+1; ++i) {
			buff[cnt] = i;
			dfs(i+1, e, cnt+1, buff, ans);
		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		vector<int> buff(k);
		dfs(1, n, 0, buff, ans);
		return ans;
	}
};
