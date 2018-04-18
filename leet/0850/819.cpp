class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		unordered_set<string> bm;
		for (auto &b: banned) { bm.insert(move(b)); }
		unordered_map<string, int> cnt;
		string buff;
		for (auto c: paragraph) {
			if ((c>='a' && c<='z') || (c>='A' && c<='Z')) {
				buff += tolower(c);
			} else {
				if (buff.length() > 0) {
					++cnt[buff];
				}
				buff = "";
			}
		}

		if (buff.length() > 0) { ++cnt[buff]; }

		string ans;
		int mx = 0;
		for (auto &kvp: cnt) {
			if (bm.find(kvp.first) != bm.end()) { continue; }
			if (kvp.second > mx) {
				mx = kvp.second;
				ans = kvp.first;
			}
		}

		return ans;
	}
};
