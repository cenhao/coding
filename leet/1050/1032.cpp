class StreamChecker {
public:
	struct TrieNode {
		void init() {
			memset(lnk, -1, sizeof(lnk));
			isw = false;
		}
		int lnk[26];
		bool isw;
	} nodes[2000*2000];
    StreamChecker(vector<string>& words) {
		int nxt = 1;
		nodes[0].init();
		for (auto &w: words) {
			int cur = 0;
			for (auto c: w) {
				int idx = c - 'a';
				if (nodes[cur].lnk[idx] == -1) {
					nodes[cur].lnk[idx] = nxt;
					nodes[nxt++].init();
				}
				cur = nodes[cur].lnk[idx];
			}

			nodes[cur].isw = true;
		}
    }

	queue<int> q;
    
    bool query(char letter) {
		q.push(0);
		bool res = false;
		int idx = letter - 'a';
		queue<int> nq;

		while (!q.empty()) {
			int p = q.front(); q.pop();
			int np = nodes[p].lnk[idx];
			if (np!=-1) {
				res |= nodes[np].isw;
				nq.push(np);
			}
		}

		q = move(nq);
		return res;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
