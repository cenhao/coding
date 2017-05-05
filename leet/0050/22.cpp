class Solution {
public:
	void dfs(int n, vector<string> &ans, string &buff, int l, int r, int pos) {
		if (r == n) {
			ans.push_back(buff);
			return;
		}

		if (l < n) {
			buff[pos] = '(';
			dfs(n, ans, buff, l+1, r, pos+1);
		}
		if (r < l) {
			buff[pos] = ')';
			dfs(n, ans, buff, l, r+1, pos+1);
		}
	}
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		string buff(2*n, ' ');
		dfs(n, ans, buff, 0, 0, 0);
		return ans;
	}
};
