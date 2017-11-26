class Solution {
public:
	bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
		int len = words1.size();
		if (len != words2.size()) { return false; }

		unordered_map<string, unordered_set<string>> pm;
		int psz = pairs.size();
		for (auto p : pairs) {
			auto it = pm.find(p.first);
			if (it == pm.end()) {
				it = pm.insert(make_pair(p.first, unordered_set<string>())).first;
			}
			it->second.insert(p.second);

			it = pm.find(p.second);
			if (it == pm.end()) {
				it = pm.insert(make_pair(p.second, unordered_set<string>())).first;
			}
			it->second.insert(p.first);
		}

		for (int i=0; i<len; ++i) {
			if (words1[i] == words2[i]) { continue; }
			auto it = pm.find(words1[i]);
			if (it == pm.end()) { return false; }
			auto iit = it->second.find(words2[i]);
			if (iit == it->second.end()) { return false; }
		}

		return true;
	}
};
