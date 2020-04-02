class Solution {
public:
	int countVowelPermutation(int n) {
		const int mod = 1000000007;
		vector<vector<int>> dp(n, vector<int>(5));
		for (int i=0; i<5; ++i) { dp[0][i] = 1; }
		for (int i=1; i<n; ++i) {
			// after a
			dp[i][1] = (dp[i][1] + dp[i-1][0]) % mod;
			// after e
			dp[i][0] = (dp[i][0] + dp[i-1][1]) % mod;
			dp[i][2] = (dp[i][2] + dp[i-1][1]) % mod;
			// after i
			dp[i][0] = (dp[i][0] + dp[i-1][2]) % mod;
			dp[i][1] = (dp[i][1] + dp[i-1][2]) % mod;
			dp[i][3] = (dp[i][3] + dp[i-1][2]) % mod;
			dp[i][4] = (dp[i][4] + dp[i-1][2]) % mod;
			// after o
			dp[i][2] = (dp[i][2] + dp[i-1][3]) % mod;
			dp[i][4] = (dp[i][4] + dp[i-1][3]) % mod;
			// after u
			dp[i][0] = (dp[i][0] + dp[i-1][4]) % mod;
		}

		int ans = 0;
		for (int i=0; i<5; ++i) { ans = (ans + dp[n-1][i]) % mod; }
		return ans;
	}
};
