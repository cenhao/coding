class Solution {
public:
	struct TrieNode {
		TrieNode() {
			memset(lnk, -1, sizeof(lnk));
			wid = -1;
			depth = ccnt = 0;
		};
		int wid, ccnt, depth;
		int lnk[26];
	};
	void insert(const string &s, int id, vector<TrieNode> &nodes) {
		int cur = 0;
		for (int i=s.length()-1; i>=0; --i) {
			int idx = s[i] - 'a';
			if (nodes[cur].lnk[idx] == -1) {
				++nodes[cur].ccnt;
				nodes[cur].lnk[idx] = nodes.size();
				nodes.emplace_back();
			}
			int d = nodes[cur].depth;
			cur = nodes[cur].lnk[idx];
			nodes[cur].depth = d + 1;
		}
		nodes[cur].wid = id;
	}
	int minimumLengthEncoding(vector<string>& words) {
		vector<TrieNode> nodes(1);
		for (int i=0; i<words.size(); ++i) {
			insert(words[i], i, nodes);
		}
		int ans = 0;
		for (auto &n: nodes) {
			if (n.wid>=0 && n.ccnt==0) { ans += n.depth+1; }
		}

		return ans;
	}
};
