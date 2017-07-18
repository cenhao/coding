#include <bits/stdc++.h>
using namespace std;

class AutocompleteSystem {
public:
	struct TrieNode {
		int lnk[27];
		int hot[3];
		int id;
	} nodes[10010];
	int ncnt;
	int anchor;
	string search;
	vector<string> scache;
	vector<int> tcache;
	AutocompleteSystem(vector<string> sentences, vector<int> times) {
		ncnt = 1;
		anchor = 0;
		search = "";
		int root = 0, sz = sentences.size();
		memset(nodes, -1, sizeof(nodes));
		for (int i=0; i<sz; ++i) { insert(sentences[i], times[i]); }
	}

	void update(int cur, int id) {
		int pos = -1;
		for (int k=0; k<3 && nodes[cur].hot[k]!=-1; ++k) {
			if (nodes[cur].hot[k] == id) {
				int i;
				for (i=k; i<2; ++i) { nodes[cur].hot[i] = nodes[cur].hot[i+1]; }
				nodes[cur].hot[i] = -1;
				break;
			}
		}
		for (int k=0; k<3; ++k) {
			if (nodes[cur].hot[k] == -1 ||
				tcache[nodes[cur].hot[k]] < tcache[id] ||
				(tcache[nodes[cur].hot[k]] == tcache[id] && scache[id] < scache[nodes[cur].hot[k]])) {
				pos = k;
				break;
			}
		}

		if (pos == -1) { return; }
		for (int k=2; k>pos; --k) { nodes[cur].hot[k] = nodes[cur].hot[k-1]; }
		nodes[cur].hot[pos] = id;
	}

	int insert(const string &s, int time) {
		int cur = 0, cid = scache.size();
		scache.push_back(s);
		tcache.push_back(time);
		for (int i=0, len=s.length(); i<len; ++i) {
			int idx = s[i] == ' ' ? 26 : s[i] - 'a';
			if (nodes[cur].lnk[idx] == -1) { nodes[cur].lnk[idx] = ncnt++; }
			cur = nodes[cur].lnk[idx];
			update(cur, cid);
		}

		return nodes[cur].id = cid;
	}

	vector<string> input(char c) {
		vector<string> ans;
		if (c == '#') {
			int cid;
			if (anchor == -1 || nodes[anchor].id == -1) {
				cid = insert(search, 1);
			} else {
				cid = nodes[anchor].id;
				++tcache[cid];
				for (int i=0, cur=0, len=search.length(); i<len; ++i) {
					int idx = search[i] == ' ' ? 26 : search[i] - 'a';
					if (nodes[cur].lnk[idx] == -1) { nodes[cur].lnk[idx] = ncnt++; }
					cur = nodes[cur].lnk[idx];
					update(cur, cid);
				}
			}
			anchor = 0;
			search = "";
			return ans;
		}

		search += c;
		if (anchor == -1) { return ans; }
		int idx = c == ' ' ? 26 : c - 'a';
		anchor = nodes[anchor].lnk[idx];
		if (anchor == -1) { return ans; }
		for (int i=0; i<3 && nodes[anchor].hot[i] >= 0; ++i) {
			ans.push_back(scache[nodes[anchor].hot[i]]);
		}

		return ans;
	}
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */

int main() {
	int n; cin >> n;
	vector<string> sentences(n);
	vector<int> times(n);
	for (int i=0; i<n; ++i) {
		cin >> sentences[i] >> times[i];
	}

	AutocompleteSystem obj(sentences, times);
	char c;
	while (cin >> c) {
		vector<string> ans = obj.input(c);
		for (int i=0; i<ans.size(); ++i) { cout << ans[i] << endl; }
		cout << "end\n";
	}

	return 0;
}
