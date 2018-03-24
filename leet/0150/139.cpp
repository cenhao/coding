class Solution {
public:
	class TrieNode {
	public:
		TrieNode() {
			memset(lnk, -1, sizeof(lnk));
			is_word = false;
		}
		int lnk[128];
		bool is_word;
	};
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<TrieNode> nodes(1);
		for (auto w: wordDict) {
			int wlen = w.length();
			int cur = 0;
			for (int i=wlen-1; i>=0; --i) {
				if (nodes[cur].lnk[w[i]] == -1) {
					nodes[cur].lnk[w[i]] = nodes.size();
					nodes.emplace_back();
				}
				cur = nodes[cur].lnk[w[i]];
			}

			nodes[cur].is_word = true;
		}

		int len = s.length();
		vector<int> dp(len+1, -1);
		dp[0] = 0;
		for (int i=1; i<=len; ++i) {
			int cur = 0;
			for (int j=i-1; j>=0 && cur>=0; --j) {
				cur = nodes[cur].lnk[s[j]];
				if (cur >= 0 && nodes[cur].is_word) {
					if (dp[j] >= 0) {
						dp[i] = j;
						break;
					}
				}
			}
		}

		return dp[len] >= 0;
	}
};
