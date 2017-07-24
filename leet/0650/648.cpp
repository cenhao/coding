#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	int lnk[26];
	bool is_word;
	int rid;
} nodes[100010];

class Solution {
public:
	string replaceWords(vector<string>& dict, string sentence) {
		int ncnt = 1;
		memset(nodes, 0, sizeof(nodes));
		int dsz = dict.size();
		for (int i=0; i<dsz; ++i) {
			int cur = 0;
			int len = dict[i].length();
			for (int j=0; j<len; ++j) {
				int idx = dict[i][j] - 'a';
				if (nodes[cur].lnk[idx] == 0) {
					nodes[cur].lnk[idx] = ncnt++;
				}
				cur = nodes[cur].lnk[idx];
			}

			nodes[cur].is_word = true;
			nodes[cur].rid = i;
		}

		sentence += ' ';
		int slen = sentence.length();
		string ans = "", buff = "";
		for (int i=0; i<slen; ++i) {
			if (sentence[i] > 'z' || sentence[i] < 'a') {
				int blen = buff.length();
				if (blen > 0) {
					int cur = 0;
					for (int j=0; j<blen; ++j) {
						int idx = buff[j] - 'a';
						cur = nodes[cur].lnk[idx];
						if (cur == 0 || nodes[cur].is_word) { break; }
					}

					if (cur == 0 || !nodes[cur].is_word) {
						ans += buff;
					} else {
						ans += dict[nodes[cur].rid];
					}
				}

				buff = "";
				if (i != slen-1) { ans += sentence[i]; }
			} else {
				buff += sentence[i];
			}
		}

		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<string> dict(n);
	for (int i=0; i<n; ++i) { cin >> dict[i]; }
	string s = "the cattle was rattled by the battery";
	Solution sol;
	cout << sol.replaceWords(dict, s) << endl;
	return 0;
}
