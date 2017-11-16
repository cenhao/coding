/*
class Solution {
public:
	string longestWord(vector<string>& words) {
		unordered_set<string> hs;
		for (auto w : words) { hs.insert(w); }
		sort(words.begin(), words.end());

		string ans = "";
		for (int i=words.size()-1; i>=0; --i) {
			bool ok = true;
			for (int j=0; j<words[i].length(); ++j) {
				if (hs.find(words[i].substr(0, j+1)) == hs.end()) {
					ok = false;
					break;
				}
			}

			if (ok && words[i].length()>ans.length()) {
				ans = words[i];
			}
		}

		return ans;
	}
};
*/

struct TrieNode {
	int r, lnk[26];
} tn[30010];

class Solution {
public:
	int dfs(int cur, const vector<string> &w) {
		if (cur<0 || tn[cur].r<0) { return -1; }
		int pick = tn[cur].r;
		for (int i=0; i<26; ++i) {
			int v = dfs(tn[cur].lnk[i], w);
			if (v>=0 && w[v].length()>w[pick].length()) {
				pick = v;
			}
		}

		return pick;
	}

	string longestWord(vector<string>& words) {
		int sz = words.size();
		memset(tn[0].lnk, -1, sizeof(tn[0].lnk));
		tn[0].r = -1;
		int tcnt = 1;
		for (int i=0; i<sz; ++i) {
			int cur = 0;
			for (int j=0, end=words[i].length(); j<end; ++j) {
				if (tn[cur].lnk[words[i][j]-'a'] == -1) {
					memset(tn[tcnt].lnk, -1, sizeof(tn[tcnt].lnk));
					tn[tcnt].r = -1;
					tn[cur].lnk[words[i][j]-'a'] = tcnt++;
				}
				cur = tn[cur].lnk[words[i][j]-'a'];
			}

			tn[cur].r = i;
		}

		int pick = -1;
		for (int i=0; i<26; ++i) {
			int v = dfs(tn[0].lnk[i], words);
			if (v>=0 && (pick==-1||words[v].length()>words[pick].length())) {
				pick = v;
			}
		}

		return words[pick];
	}
};
