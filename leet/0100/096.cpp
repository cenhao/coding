class Solution {
public:
	int numTrees(int n) {
		if (n == 0) { return 0; }
		vector<vector<int>> dp(2, vector<int>(n, 0));
		dp[1][0] = 1;
		for (int i=2; i<=n; ++i) {
			int cur = i & 1, pre = (i-1) & 1, sum = 0;
			for (int j=i-1; j>0; --j) {
				sum += dp[pre][j-1];
				dp[cur][j] = sum;
			}
			dp[cur][0] = sum;
		}
		int ans = 0;
		for (int i=0, cur=n&1; i<n; ++i) { ans += dp[cur][i]; }
		return ans;
	}
};
