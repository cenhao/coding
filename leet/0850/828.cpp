class Solution {
public:
	int uniqueLetterString(string s) {
		const static int MOD = 1000000007;
		vector<vector<int>> lp(128, vector<int>(2, -1));
		int len = s.length();
		vector<int> dp(len);
		for (int i=0; i<s.length(); ++i) {
			int last = (i == 0) ? 0 : dp[i-1];
			dp[i] = (last + i-lp[s[i]][0] - (lp[s[i]][0]-lp[s[i]][1])) % MOD;
			lp[s[i]][1] = lp[s[i]][0];
			lp[s[i]][0]= i;
		}
		int ans = 0;
		for (int i=0; i<len; ++i) {
			ans = (ans + dp[i]) % MOD;
		}
		return ans;
	}
};
