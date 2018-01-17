#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
	string convert(const string &s) {
		string ret;
		for (auto c : s) { if (c != 0) { ret += c; } }
		return ret;
	}
	void rdfs(const string &os, int len, int end, int pre, int cnt, int cur, string tmp, vector<string> &ans) {
		if (cur <= end) {
			ans.push_back(move(convert(tmp)));
			return;
		}
		if (os[cur] == '(') {
			++cnt;
			if (cnt > 0) {
				for (int i=pre-1; i>=cur; --i) {
					if (tmp[i] != '(' || (i<pre-1 && tmp[i+1]=='(')) { continue; }
					tmp[i] = 0;
					rdfs(os, len, end, i, 0, cur-1, tmp, ans);
					tmp[i] = '(';
				}
			} else {
				rdfs(os, len, end, pre, cnt, cur-1, tmp, ans);
			}
		} else {
			if (os[cur] == ')') { --cnt; }
			rdfs(os, len, end, pre, cnt, cur-1, tmp, ans);
		}
	}
	void dfs(const string &os, int len, int pre, int cnt, int cur, int last, string tmp, vector<string> &ans) {
		if (cur == len) {
			if (cnt == 0) {
				ans.push_back(move(convert(tmp)));
			} else {
				rdfs(os, len, last, len, 0, len-1, tmp, ans);
			}
			return;
		}

		tmp += os[cur];
		if (os[cur] == ')') {
			--cnt;
			if (cnt < 0) {
				for (int i=pre+1; i<=cur; ++i) {
					if (tmp[i] != ')' || (i>pre+1 && tmp[i-1]==')')) { continue; }
					tmp[i] = 0;
					dfs(os, len, i, 0, cur+1, cur, tmp, ans);
					tmp[i] = ')';
				}
				return;
			}
		}

		if (os[cur] == '(') { ++cnt; }
		if (cnt == 0) { last = cur; }
		dfs(os, len, pre, cnt, cur+1, last, tmp, ans);
	}

	vector<string> removeInvalidParentheses(string s) {
		int len = s.length();
		vector<string> ans;
		string tmp;
		dfs(s, len, -1, 0, 0, -1, tmp, ans);
		return ans;
	}
};
*/

class Solution {
public:
	vector<char> ps = { ')', '(' };
	void dfs(string &s, int stop, int cur, int last_del, int valid_pos, int cnt, int pi, vector<string> &ans) {
		if (cur >= stop) {
			if (cnt == 0) {
				string ss;
				for (int i=0; i<s.length(); ++i) { if (s[i] != 0) { ss += s[i]; } }
				if (pi == 1) { reverse(ss.begin(), ss.end()); }
				ans.push_back(move(ss));
			} else {
				reverse(s.begin(), s.end());
				stop = s.length() - valid_pos - 1;
				dfs(s, stop, 0, -1, -1, 0, pi^1, ans);
				reverse(s.begin(), s.end());
			}
			return;
		}

		if (s[cur] == ps[pi]) {
			--cnt;
			if (cnt < 0) {
				for (int i=last_del+1; i<=cur; ++i) {
					if (s[i] != ps[pi] || (i>last_del+1 && s[i] == s[i-1])) { continue; }
					s[i] = 0;
					dfs(s, stop, cur+1, i, cur, 0, pi, ans);
					s[i] = ps[pi];
				}
				return;
			}
		}

		if (s[cur] == ps[pi^1]) { ++cnt; }
		dfs(s, stop, cur+1, last_del, valid_pos, cnt, pi, ans);
	}

	vector<string> removeInvalidParentheses(string s) {
		vector<string> ans;
		dfs(s, s.length(), 0, -1, -1, 0, 0, ans);
		return ans;
	}
};

int main() {
	string in; cin >> in;
	Solution sol;
	vector<string> ans = sol.removeInvalidParentheses(in);
	for (auto &s : ans) { cout << s << endl; }
	return 0;
}
