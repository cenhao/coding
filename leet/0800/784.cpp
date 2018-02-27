class Solution {
public:
	void dfs(string &s, int cur, vector<string> &ans) {
		if (cur >= s.length()) {
			ans.push_back(s);
			return;
		}

		if (s[cur] >= '0' && s[cur] <= '9') {
			dfs(s, cur+1, ans);
		} else {
			dfs(s, cur+1, ans);
			if (s[cur] >= 'a' && s[cur] <= 'z') {
				s[cur] = toupper(s[cur]);
			} else {
				s[cur] = tolower(s[cur]);
			}
			dfs(s, cur+1, ans);
		}
	}
	vector<string> letterCasePermutation(string S) {
		vector<string> ans;
		dfs(S, 0, ans);
		return ans;
	}
};
