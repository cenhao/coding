class Solution {
public:
	vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
		unordered_map<int, vector<int>> hm;
		for (int i=0; i<pid.size(); ++i) {
			auto it = hm.find(ppid[i]);
			if (it == hm.end()) {
				it = hm.insert(pair<int, vector<int>>(ppid[i], vector<int>())).first;
			}

			it->second.push_back(pid[i]);
		}
		vector<int> ans;
		dfs(kill, hm, ans);
		return ans;
	}

	void dfs(int kill, unordered_map<int, vector<int>> &hm, vector<int> &ans) {
		ans.push_back(kill);
		auto it = hm.find(kill);
		if (it == hm.end()) { return; }
		for (auto ent : it->second) { dfs(ent, hm, ans); }
	}
};
