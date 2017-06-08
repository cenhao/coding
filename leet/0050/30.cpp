#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
	TrieNode() {
		memset(lnk, 0, sizeof(lnk));
		id = -1;
	}
	TrieNode *lnk[127];
	int id;
};

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		TrieNode root;
		vector<int> ans, cnt(words.size(), 0);
		if (words.size() <= 0) { return ans; }

		// build trie
		for (int i=0; i<words.size(); ++i) {
			TrieNode *cur = &root;
			for (int j=0; j<words[i].length(); ++j) {
				int c = words[i][j];
				if (cur->lnk[c] == nullptr) { cur->lnk[c] = new TrieNode(); }
				cur = cur->lnk[c];
			}

			if (cur->id == -1) { cur->id = i; }
			++cnt[cur->id];
		}

		// match single word
		int wlen = words[0].length(), slen = s.length();
		vector<int> match(slen, -1);
		for (int i=0, end=slen-wlen+1; i<end; ++i)  {
			TrieNode *cur = &root;
			for (int j=0; j<wlen; ++j) {
				int c = s[i+j];
				if (cur->lnk[c] == nullptr) { break; }
				cur = cur->lnk[c];
			}

			match[i] = cur->id;
		}

		for (int i=0; i<wlen; ++i) {
			int h = i, r = i-wlen, tot = 0;
			vector<int> mcnt(words.size(), 0);
			while (r < slen-wlen) {
				r += wlen;
				if (match[r] < 0) {
					while (h <= r) {
						if (match[h] >= 0) {
							--mcnt[match[h]];
							--tot;
						}
						h += wlen;
					}
				} else {
					++tot; ++mcnt[match[r]];
					while (mcnt[match[r]] > cnt[match[r]]) {
						--mcnt[match[h]];
						h += wlen;
						--tot;
					}

					if (tot == words.size()) { ans.push_back(h); }
				}
			}
		}

		release(&root);
		return ans;
	}

	void release(TrieNode *cur) {
		for (int i=0; i<127; ++i) {
			if (cur->lnk[i] != nullptr) {
				release(cur->lnk[i]);
				delete cur->lnk[i];
				cur->lnk[i] = nullptr;
			}
		}
	}
};

int main() {
	string s;
	Solution sol;
	while (cin >> s) {
		int n; cin >> n;
		vector<string> v(n);
		for (int i=0; i<n; ++i) { cin >> v[i]; }
		vector<int> ans = sol.findSubstring(s, v);
		for (int i=0; i<ans.size(); ++i) {
			cout << ans[i] << endl;
		}
	}

	return 0;
}
