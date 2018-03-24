#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	struct TrieNode {
		TrieNode() {
			memset(lnk, -1, sizeof(lnk));
			id = -1;
		}
		int lnk[26], id;
	};
	void dfs(int cur, vector<int> &buf, vector<string> &ans,
			 const vector<vector<int>> &pl, const vector<string> &wd) {
		if (cur < 0) {
			string tmp;
			for (int i=buf.size()-1; i>=0; --i) {
				tmp += wd[buf[i]];
				if (i != 0) { tmp += ' '; }
			}
			ans.push_back(move(tmp));
			return;
		}

		for (auto p: pl[cur]) {
			buf.push_back(p);
			dfs(cur-wd[p].length(), buf, ans, pl, wd);
			buf.pop_back();
		}
	}
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		vector<TrieNode> nodes;
		nodes.emplace_back();
		int wsz = wordDict.size();
		for (int i=0; i<wsz; ++i) {
			string &w = wordDict[i];
			int cur = 0, wlen = w.length();
			for (int j=wlen-1; j>=0; --j) {
				char c = w[j] - 'a';
				if (nodes[cur].lnk[c] == -1) {
					nodes.emplace_back();
					nodes[cur].lnk[c] = nodes.size() - 1;
				}
				cur = nodes[cur].lnk[c];
			}

			nodes[cur].id = i;
		}

		int len = s.length();
		vector<vector<int>> pl(len);
		for (int i=0; i<len; ++i) {
			int cur = 0;
			for (int j=i; j>=0 && cur>=0; --j) {
				int c = s[j] - 'a';
				cur = nodes[cur].lnk[c];
				if (cur>=0 && nodes[cur].id>=0) {
					if (j-1<0 || pl[j-1].size()>0) {
						pl[i].push_back(nodes[cur].id);
					}
				}
			}
		}

		vector<string> ans;
		vector<int> buf;
		dfs(len-1, buf, ans, pl, wordDict);
		return ans;
	}
};

int main() {
	string s; cin >> s;
	int n; cin >> n;
	vector<string> wd(n);
	for (int i=0; i<n; ++i) { cin >> wd[i]; }
	Solution sol;
	sol.wordBreak(s, wd);
	return 0;
}
