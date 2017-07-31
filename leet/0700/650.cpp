class Solution {
public:
	int minSteps(int n) {
		vector<int> dp(n+1, 0x7fffffff);
		dp[1] = 0;
		for (int i=2; i<=n; ++i) {
			for (int j=1, end=n/2; j<=end; ++j) {
				if (i % j != 0) { continue; }
				int cnt = i / j - 1;
				dp[i] = min(dp[i], cnt+dp[j]+1);
			}
		}

		return dp[n];
	}
};
