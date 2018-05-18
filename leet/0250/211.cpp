class WordDictionary {
private:
	struct TrieNode {
		TrieNode() { word = false; memset(lnk, -1, sizeof(lnk)); }
		int lnk[26];
		bool word;
	};
	vector<TrieNode> nodes;
	bool search(const string &w, int sta, int nid) {
		for (int i=sta; i<w.length(); ++i) {
			if (w[i] == '.') {
				for (int j=0; j<26; ++j) {
					if (nodes[nid].lnk[j] == -1) { continue; }
					if (search(w, i+1, nodes[nid].lnk[j])) { return true; }
				}
				return false;
			} else {
				int idx = w[i] - 'a';
				if (nodes[nid].lnk[idx] == -1) { return false; }
				nid = nodes[nid].lnk[idx];
			}
		}

		return nodes[nid].word;
	}
public:
    /** Initialize your data structure here. */
    WordDictionary() {
		nodes.emplace_back();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
		int cur = 0;
		for (auto c: word) {
			int idx = c - 'a';
			if (nodes[cur].lnk[idx] == -1) {
				nodes[cur].lnk[idx] = nodes.size();
				nodes.emplace_back();
			}
			cur = nodes[cur].lnk[idx];
		}
		nodes[cur].word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
		return search(word, 0, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
