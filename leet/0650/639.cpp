class Solution {
public:
	int numDecodings(string s) {
		const int MOD = 1000000007;
		int len = s.length();
		vector<int64_t> dp(len+1);
		dp[0] = 1;
		for (int i=0; i<len; ++i) {
			int ii = i+1;
			dp[ii] = 0;
			if (s[i] != '*') {
				if (s[i] != '0') { dp[ii] = dp[i]; }
				if (i == 0) { continue; }
				if (s[i-1] != '*') {
					int v = (s[i-1] - '0') * 10 + s[i] - '0';
					if (v <= 26 && v > 9) { dp[ii] = (dp[ii] + dp[i-1]) % MOD; }
				} else {
					int v = s[i] - '0' + 10;
					if (v <= 26) { dp[ii] = (dp[ii] + dp[i-1]) % MOD; }
					v += 10;
					if (v <= 26) { dp[ii] = (dp[ii] + dp[i-1]) % MOD; }
				}
			} else {
				dp[ii] = (dp[i] * 9) % MOD;
				if (i == 0) { continue; }
				if (s[i-1] != '*') {
					if (s[i-1] == '1') {
						dp[ii] = (dp[ii] + dp[i-1]*9) % MOD;
					} else if (s[i-1] == '2') {
						dp[ii] = (dp[ii] + dp[i-1]*6) % MOD;
					}
				} else {
					dp[ii] = (dp[ii] + dp[i-1]*15) % MOD;
				}
			}
		}

		return dp[len];
	}
};
