struct TrieNode {
	bool is_word;
	int lnk[127];
} nodes[100*1001];

class Solution {
public:
	string addBoldTag(string s, vector<string>& dict) {
		int tcnt = 1;
		nodes[0].is_word = false;
		memset(nodes[0].lnk, -1, sizeof(nodes[0].lnk));

		for (int i=0; i<dict.size(); ++i) {
			int cur = 0;
			for (int j=0; j<dict[i].length(); ++j) {
				if (nodes[cur].lnk[dict[i][j]] == -1) {
					nodes[tcnt].is_word = false;
					memset(nodes[tcnt].lnk, -1, sizeof(nodes[tcnt].lnk));
					nodes[cur].lnk[dict[i][j]] = tcnt++;
				}
				cur = nodes[cur].lnk[dict[i][j]];
			}

			nodes[cur].is_word = true;
		}

		vector<bool> mark(s.length(), false);

		for (int i=0; i<s.length(); ++i) {
			int cur = 0, pos = i, mx = -1;
			while (cur != -1 && pos < s.length()) {
				cur = nodes[cur].lnk[s[pos++]];
				if (cur != -1 && nodes[cur].is_word) {
					mx = pos;
				}
			}

			for (int j=i; j<mx; ++j) { mark[j] = true; }
		}

		string ans;
		bool marking = false;
		for (int i=0; i<s.length(); ++i) {
			if (mark[i] == true) {
				if (!marking) {
					marking = true;
					ans += "<b>";
				}

				ans += s[i];
			} else {
				if (marking) {
					marking = false;
					ans += "</b>";
				}
				ans += s[i];
			}
		}

		if (marking) { ans += "</b>"; }

		return ans;
	}
};
