class Solution {
public:
	bool dfs(const string &s, int cur, int cnt, string &buf,
			 const string &p, vector<bool> &used, unordered_map<string, char>& hm) {
		if (cnt >= p.length()) { return cur >= s.length(); }
		if (cur >= s.length()) { return false; }
		buf.push_back(s[cur]);
		auto it = hm.find(buf);
		if (it != hm.end()) {
			if (it->second == p[cnt]) {
				string nbuf;
				if (dfs(s, cur+1, cnt+1, nbuf, p, used, hm)) { return true; }
			}
		} else {
			if (!used[p[cnt]-'a']) {
				used[p[cnt]-'a'] = true;
				hm.insert(make_pair(buf, p[cnt]));
				string nbuf;
				if (dfs(s, cur+1, cnt+1, nbuf, p, used, hm)) { return true; }
				hm.erase(buf);
				used[p[cnt]-'a'] = false;
			}
		}
		return dfs(s, cur+1, cnt, buf, p, used, hm);
	}
	bool wordPatternMatch(string pattern, string str) {
		string buf;
		vector<bool> used(26, false);
		unordered_map<string, char> hm;
		return dfs(str, 0, 0, buf, pattern, used, hm);
	}
};
