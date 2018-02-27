#include <bits/stdc++.h>
using namespace std;

/*
// simple solution
class Solution {
public:
	int minCut(string s) {
		int len = s.length();
		vector<vector<bool>> is_pal(len, vector<bool>(len, false));
		vector<int> dp(len);

		for (int i=0; i<len; ++i) {
			dp[i] = i;
			for (int j=i; j>=0; --j) {
				if (s[i]==s[j] && (i<=j+1||is_pal[j+1][i-1])) {
					is_pal[j][i] = true;
					dp[i] = min(dp[i], (j-1>=0 ? dp[j-1] : -1)+1);
				}
			}
		}

		return dp[len-1];
	}
};
*/

/*
// parlindrome tree solution
class Solution {
public:
	struct PTN { int fail, len, lnk[128]; }; // parlindrome tree node
	int minCut(string s) {
		int len = s.length();
		vector<int> dp(len), mk(len);
		vector<PTN> nodes(2);
		nodes[0].fail = nodes[1].fail = 0;
		nodes[0].len = -1; nodes[1].len = 0;
		memset(nodes[0].lnk, -1, sizeof(nodes[0].lnk));
		memset(nodes[1].lnk, -1, sizeof(nodes[1].lnk));
		int cur = 0;

		for (int i=0; i<len; ++i) {
			while (cur!=0 && (i-nodes[cur].len-1<0 || s[i-nodes[cur].len-1]!=s[i])) {
				cur = nodes[cur].fail;
			}

			if (nodes[cur].lnk[s[i]] == -1) {
				nodes.push_back(PTN());
				int nxt = nodes.size()-1;
				nodes[cur].lnk[s[i]] = nxt;
				memset(nodes[nxt].lnk, -1, sizeof(nodes[nxt].lnk));
				nodes[nxt].len = nodes[cur].len+2;
				int fail = nodes[cur].fail;
				while (fail!=0 && (i-nodes[fail].len-1<0 || s[i]!=s[i-nodes[fail].len-1])) {
					fail = nodes[fail].fail;
				}
				nodes[nxt].fail = (nodes[fail].lnk[s[i]]==nxt) ? 1 : nodes[fail].lnk[s[i]];
			}
			cur = nodes[cur].lnk[s[i]];
			mk[i] = cur;
		}

		for (int i=0; i<len; ++i) {
			dp[i] = i;
			for (int j=mk[i]; j>1; j=nodes[j].fail) {
				dp[i] = min(dp[i], (i-nodes[j].len>=0) ? dp[i-nodes[j].len]+1:0);
			}
		}

		return dp[len-1];
	}
};
*/

class Solution {
public:
	int minCut(string s) {
		int len = s.length();
		vector<int> dp(len, len);
		for (int i=0; i<len; ++i) {
			for (int j=0; i+j<len && i-j>=0 && s[i+j]==s[i-j]; ++j) {
				dp[i+j] = min(dp[i+j], i-j-1>=0 ? dp[i-j-1]+1:0);
			}
			for (int j=1; i+j-1<len && i-j>=0 && s[i+j-1]==s[i-j]; ++j) {
				dp[i+j-1] = min(dp[i+j-1], i-j-1>=0 ? dp[i-j-1]+1:0);
			}
		}

		return dp[len-1];
	}
};

int main() {
	string s; cin >> s;
	Solution sol;
	cout << sol.minCut(s) << endl;
	return 0;
}
