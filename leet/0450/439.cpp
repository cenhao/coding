class Solution {
public:
	string dfs(const string &e, int &sta) {
		char cond = e[sta++];
		if (sta<e.length() && e[sta]=='?') {
			++sta;
			string lres = dfs(e, sta);
			++sta;
			string rres = dfs(e, sta);
			return cond == 'T' ? lres : rres;
		}
		string ret = { cond };
		return ret;
	}
	string parseTernary(string expression) {
		int sta = 0;
		return dfs(expression, sta);
	}
};
