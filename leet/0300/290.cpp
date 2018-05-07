class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> vs;
		string buf;
		for (int i=0; i<=str.length(); ++i) {
			if (i==str.length() || str[i]==' ') {
				if (buf.length() > 0) { vs.emplace_back(move(buf)); }
				buf = "";
			} else {
				buf += str[i];
			}
		}

		if (vs.size() != pattern.length()) { return false; }
		vector<bool> used(26, false);
		unordered_map<string, char> hm;
		for (int i=0; i<vs.size(); ++i) {
			auto it = hm.find(vs[i]);
			if (it != hm.end()) {
				if (it->second != pattern[i]) { return false; }
			} else {
				if (used[pattern[i]-'a']) { return false; }
				hm.insert(make_pair(vs[i], pattern[i]));
				used[pattern[i]-'a'] = true;
			}
		}
		return true;
	}
};
