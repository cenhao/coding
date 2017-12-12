class WordFilter {
public:
	unordered_map<string, int> hm;
	WordFilter(vector<string> words) {
		int sz = words.size();
		for (int i=0; i<sz; ++i) {
			int len = words[i].length();
			string pre;
			for (int j=0; j<=len; ++j) {
				if (j > 0) { pre += words[i][j-1]; }
				string suf;
				for (int k=len; k>=0; --k) {
					if (k < len) { suf = move(words[i][k]+move(suf)); }
					string tmp = pre + '#' + suf;
					hm[tmp] = i;
				}
			}
		}
	}

	int f(string prefix, string suffix) {
		auto it = hm.find(prefix + '#' + suffix);
		return (it == hm.end()) ? -1 : it->second;
	}
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
