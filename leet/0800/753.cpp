class Solution {
public:
	bool dfs(int sta, unordered_set<string> &hm, int cnt, int tar, string &ans, int len, int k) {
		if (cnt == tar) { return true; }
		string tmp = string(len, '0');
		for (int i=1; i<len; ++i) { tmp[i-1] = ans[sta-len+i]; }
		for (int i=0; i<k; ++i) {
			ans[sta] = tmp[len-1] = '0' + i;
			if (hm.end() != hm.find(tmp)) { continue; }
			hm.insert(tmp);
			if (dfs(sta+1, hm, cnt+1, tar, ans, len, k)) { return true; }
			hm.erase(tmp);
		}
		return false;
	}
	string crackSafe(int n, int k) {
		int cnt = 1;
		for (int i=0; i<n; ++i) { cnt *= k; }
		string ans = string(cnt+n-1, '0');
		unordered_set<string> hm;
		string first = string(n, '0');
		hm.insert(move(first));
		dfs(n, hm, 1, cnt, ans, n, k);
		return ans;
	}
};
