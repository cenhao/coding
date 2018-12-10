class Solution {
public:
	bool areSentencesSimilarTwo(vector<string>& w1, vector<string>& w2, vector<pair<string, string>> ps) {
		int len1 = w1.size(), len2 = w2.size();
		if (len1 != len2) { return false; }

		unordered_map<string, int> hm;
		for (auto &w: w1) {
			if (hm.find(w) == hm.end()) { hm.emplace(w, int(hm.size())); }
		}
		for (auto &w: w2) {
			if (hm.find(w) == hm.end()) { hm.emplace(w, int(hm.size())); }
		}
		for (auto &p: ps) {
			if (hm.find(p.first) == hm.end()) { hm.emplace(p.first, int(hm.size())); }
			if (hm.find(p.second) == hm.end()) { hm.emplace(p.second, int(hm.size())); }
		}

		int sz = hm.size();
		vector<int> f(sz);
		for (int i=0; i<sz; ++i) { f[i] = i; }
		function<int(int)> find = [&](int x) { return f[x] = (f[x] != f[f[x]]) ? find(f[x]) : f[x]; };

		for (auto &p: ps) {
			int f1 = find(hm[p.first]), f2 = find(hm[p.second]);
			if (f1 != f2) { f[f1] = f2; }
		}

		for (int i=0; i<len1; ++i) {
			int f1 = find(hm[w1[i]]), f2 = find(hm[w2[i]]);
			if (f1 != f2) { return false; }
		}

		return true;
	}
};
