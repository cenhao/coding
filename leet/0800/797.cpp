class Solution {
public:
	void dfs(int cur, int tar, vector<vector<int>> &g, vector<int> &buf, vector<vector<int>> &ans) {
		if (cur == tar) {
			ans.emplace_back(buf);
			return;
		}

		for (auto v: g[cur]) {
			buf.push_back(v);
			dfs(v, tar, g, buf, ans);
			buf.pop_back();
		}
	}
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int sz = graph.size();
		vector<vector<int>> ans;
		if (sz == 0) { return ans; }
		vector<int> buf = {0};
		dfs(0, sz-1, graph, buf, ans);
		return ans;
	}
};
