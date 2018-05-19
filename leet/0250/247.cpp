class Solution {
public:
	void dfs(int cur, int n, string &buf, vector<string> &ans, const vector<int> &num, const vector<int> &rnum) {
		if (cur > (n-1)/2) {
			ans.push_back(buf);
			return;
		}

		int rpos = n-cur-1;
		for (int i=0; i<num.size(); ++i) {
			if (rpos!=cur || (num[i]!=6 && num[i]!=9)) {
				if (cur == 0 && n != 1 && num[i] == 0) { continue; }
				buf[cur] = num[i] + '0';
				buf[rpos] = rnum[i] + '0';
				dfs(cur+1, n, buf, ans, num, rnum);
			}
		}
	}

	vector<string> findStrobogrammatic(int n) {
		vector<int> num = { 0, 1, 6, 8, 9 };
		vector<int> rnum = { 0, 1, 9, 8, 6 };
		string buf(n, 0);
		vector<string> ans;
		if (n == 0) { return ans; }
		dfs(0, n, buf, ans, num, rnum);
		return ans;
	}
};
