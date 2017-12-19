class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int sz = cost.size();
		vector<int> dp(sz+1, -1);
		dp[0] = dp[1] = 0;
		for (int i=0; i<sz; ++i) {
			for (int j=1; j<=2 && i+j<=sz; ++j) {
				if (dp[i+j] < 0 || dp[i+j] > dp[i]+cost[i]) {
					dp[i+j] = dp[i]+cost[i];
				}
			}
		}

		return dp[sz];
	}
};
