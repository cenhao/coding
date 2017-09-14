class Solution {
public:
	int numDecodings(string s) {
		int len = s.length();
		vector<int> dp(len+1, 0);
		dp[0] = (len == 0) ? 0 : 1;
		for (int i=0, pre=0; i<len; ++i) {
			int ii = i + 1;
			int cur = s[i] - '0';
			if (cur > 0) { dp[ii] = dp[i]; }
			int com = cur + pre * 10;
			if (com <= 26 && com != cur) { dp[ii] += dp[i-1]; }
			pre = cur;
		}

		return dp[len];
	}
};
