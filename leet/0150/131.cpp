/*
class Solution {
public:
	bool is_parlindrome(const string &s, vector<vector<int8_t>> &isp, int l, int r) {
		if (l > r) { return true; }
		if (isp[l][r] == 0) {
			isp[l][r] = (s[l]==s[r] && is_parlindrome(s, isp, l+1, r-1)) ? 1 : 2;
		}
		return isp[l][r] == 1;
	}

	void dfs(const string &s, int sta, vector<string> &buff, vector<vector<string>> &ans, vector<vector<int8_t>> &isp) {
		if (sta >= s.length()) {
			ans.push_back(buff);
			return;
		}
		for (int i=sta; i<s.length(); ++i) {
			if (is_parlindrome(s, isp, sta, i)) {
				buff.push_back(s.substr(sta, i-sta+1));
				dfs(s, i+1, buff, ans, isp);
				buff.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {
		int len = s.length();
		vector<vector<int8_t>> isp(len, vector<int8_t>(len, 0));
		vector<vector<string>> ans;
		vector<string> buff;
		dfs(s, 0, buff, ans, isp);
		return ans;
	}
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	struct Node {
		int fail, len, lnk[128];
	};
	void dfs(const vector<Node> &nodes, const vector<int> &mk, const string &s,
			 vector<vector<string>> &ans, vector<string> &buff, int cur) {
		if (cur >= s.length()) {
			ans.push_back(buff);
			return;
		}
		for (int fail=mk[cur]; fail>1; fail=nodes[fail].fail) {
			string ts = s.substr(cur, nodes[fail].len);
			buff.push_back(ts);
			dfs(nodes, mk, s, ans, buff, cur+nodes[fail].len);
			buff.pop_back();
		}
	}
	vector<vector<string>> partition(string s) {
		int len = s.length();
		vector<int> mk(len);
		vector<Node> nodes(2);
		nodes[0].fail = nodes[1].fail = 0;
		nodes[0].len = -1; nodes[1].len = 0;
		memset(nodes[0].lnk, -1, sizeof(nodes[0].lnk));
		memset(nodes[1].lnk, -1, sizeof(nodes[1].lnk));

		int cur = 0, nxt = 2;
		for (int i=len-1; i>=0; --i) {
			while (cur!=0 && (i+nodes[cur].len+1>=len || s[i+nodes[cur].len+1]!=s[i])) {
				cur = nodes[cur].fail;
			}
			if (nodes[cur].lnk[s[i]] == -1) {
				Node tmp;
				nodes.push_back(tmp);
				nodes[nxt].len = nodes[cur].len+2;
				nodes[cur].lnk[s[i]] = nxt;
				memset(nodes[nxt].lnk, -1, sizeof(nodes[nxt].lnk));
				int fail = nodes[cur].fail;
				while (fail!=0 && (i+nodes[fail].len+1>=len || s[i+nodes[fail].len+1]!=s[i])) {
					fail = nodes[fail].fail;
				}

				nodes[nxt].fail = nodes[fail].lnk[s[i]] == nxt ? 1 : nodes[fail].lnk[s[i]];
				++nxt;
			}

			cur = nodes[cur].lnk[s[i]];
			mk[i] = cur;
		}

		vector<vector<string>> ans;
		vector<string> buff;
		dfs(nodes, mk, s, ans, buff, 0);
		return ans;
	}
};

int main() {
	string s; cin >> s;
	Solution sol;
	vector<vector<string>> ans = move(sol.partition(s));
	for (int i=0, end=ans.size(); i<end; ++i) {
		for (auto &s : ans[i]) {
			cout << s << endl;
		}

		cout << endl;
	}
	return 0;
}
