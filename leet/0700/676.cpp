struct TrieNode {
	bool word;
	int lnk[26];
} nodes[1024*1024];

class MagicDictionary {
public:
	int nfirst;
    /** Initialize your data structure here. */
    MagicDictionary() {
		init_node(0);
		nfirst = 1;
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
		for (auto &w : dict) {
			int cur = 0;
			for (int i=0, len=w.length(); i<len; ++i) {
				int idx = w[i] - 'a';
				if (nodes[cur].lnk[idx] == -1) { init_node(nodes[cur].lnk[idx] = nfirst++); }
				cur = nodes[cur].lnk[idx];
			}
			nodes[cur].word = true;
		}
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
		return dfs(word, 0, 0, 0, word.length());
    }

	bool dfs(const string &w, int p, int cur, int cnt, int len) {
		if (p == len) { return (nodes[cur].word && cnt == 1); }
		int idx = w[p] - 'a';
		for (int i=0; i<26; ++i) {
			if (nodes[cur].lnk[i] != -1) {
				if (idx == i) {
					if (dfs(w, p+1, nodes[cur].lnk[i], cnt, len)) { return true; }
				} else if (cnt == 0) {
					if (dfs(w, p+1, nodes[cur].lnk[i], 1, len)) { return true; }
				}
			}
		}

		return false;
	}

	void init_node(int idx) {
		nodes[idx].word = false;
		memset(nodes[idx].lnk, -1, sizeof(nodes[idx].lnk));
	}
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
