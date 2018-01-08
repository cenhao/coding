class Solution {
public:
	bool dfs(vector<string> &b, int cur, unordered_map<string, vector<char>> &hm,
			 int len, int st) {
		if (len == 1) { return true; }
		string key = move(b[cur].substr(st, 2));
		auto it = hm.find(key);
		if (it == hm.end()) { return false; }
		for (auto c : it->second) {
			b[cur+1][st] = c;
			if (st == len-2 && dfs(b, cur+1, hm, len-1, 0)) {
				return true;
			} else if (dfs(b, cur, hm, len, st+1)) {
				return true;
			}
		}
		return false;
	}
	bool pyramidTransition(string bottom, vector<string>& allowed) {
		int len = bottom.length(), sz = allowed.size();
		int need = len * (len-1) / 2;
		if (need > sz) { return false; }
		vector<string> b(len, bottom);
		unordered_map<string, vector<char>> hm;
		for (auto &a : allowed) {
			string key = move(a.substr(0, 2));
			auto it = hm.find(key);
			if (it == hm.end()) {
				it = hm.insert(make_pair(key, vector<char>())).first;
			}

			it->second.push_back(a[2]);
		}
		return dfs(b, 0, hm, len, 0);
	}
};
