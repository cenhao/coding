class Solution {
public:
	void dfs(string &s, int v, int cur, int ed, int last, char a, char d, int step, vector<string> &ans) {
		if (cur == ed) {
			if (v == 0) {
				string tmp;
				for (int i=0; i<s.length(); ++i) {
					if (s[i] != 0) { tmp += s[i]; }
				}
				ans.emplace_back(tmp);
			} else {
				dfs(s, 0, ed-step, -1, ed, d, a, -step, ans);
			}
			return;
		}
		v += (s[cur]==a) ? 1 : ((s[cur]==d) ? -1:0);
		if (v < 0) {
			for (int i=last+step; ; i+=step) {
				if (s[i]==d && (i==last+step || s[i-step]!=d)) {
					s[i] = 0;
					dfs(s, 0, cur+step, ed, i, a, d, step, ans);
					s[i] = d;
				}
				if (i == cur) { break; }
			}
		} else {
			dfs(s, v, cur+step, ed, last, a, d, step, ans);
		}
	}
    vector<string> removeInvalidParentheses(string &s) {
		vector<string> ans;
		dfs(s, 0, 0, s.length(), -1, '(', ')', 1, ans);
		return ans;
    }
};
