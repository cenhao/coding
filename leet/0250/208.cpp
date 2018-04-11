class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
		nodes.emplace_back();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
		int cur = 0;
		for (auto c: word) {
			int idx = c - 'a';
			if (nodes[cur].lnk[idx] == -1) {
				nodes.emplace_back();
				nodes[cur].lnk[idx] = nodes.size()-1;
			}
			cur = nodes[cur].lnk[idx];
		}
		nodes[cur].word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
		int cur = 0;
		for (auto c: word) {
			int idx = c - 'a';
			if (nodes[cur].lnk[idx] == -1) { return false; }
			cur = nodes[cur].lnk[idx];
		}
		return nodes[cur].word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		int cur = 0;
		for (auto c: prefix) {
			int idx = c - 'a';
			if (nodes[cur].lnk[idx] == -1) { return false; }
			cur = nodes[cur].lnk[idx];
		}

		if (nodes[cur].word) { return true; }
		for (int i=0; i<26; ++i) { if (nodes[cur].lnk[i] != -1) { return true; } }
		return false;
    }
private:
	struct TrieNode {
		TrieNode() {
			memset(lnk, -1, sizeof(lnk));
			word = false;
		}
		int lnk[26];
		bool word;
	};
	vector<TrieNode> nodes;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
