class Solution {
public:
	struct TrieNode {
		TrieNode() { memset(lnk, -1, sizeof(lnk)); }
		int lnk[26];
		vector<int> pidx;
	};
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		sort(products.begin(), products.end());
		vector<TrieNode> nodes;
		nodes.emplace_back();
		int sz = products.size();
		for (int i=0; i<sz; ++i) {
			string &p = products[i];
			int cur = 0;
			for (auto c: p) {
				int nxt = nodes[cur].lnk[c-'a'];
				if (nxt == -1) {
					nodes.emplace_back();
					nxt = nodes[cur].lnk[c-'a'] = nodes.size() - 1;
				}
				cur = nxt;
				nodes[cur].pidx.push_back(i);
			}
		}

		int scur = 0;
		vector<vector<string>> ans;
		for (auto c: searchWord) {
			scur = scur==-1 ? -1 : nodes[scur].lnk[c-'a'];
			vector<string> tmp;
			if (scur != -1) {
				for (int i=0, ed=min(int(nodes[scur].pidx.size()), 3); i<ed; ++i) {
					int idx = nodes[scur].pidx[i];
					tmp.emplace_back(products[idx]);
				}
			}
			ans.emplace_back(move(tmp));
		}

		return ans;
	}
};
