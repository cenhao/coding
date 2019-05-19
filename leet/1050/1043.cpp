class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& a, int k) {
		int sz = a.size();
		vector<int> dp(sz+1, 0);
		for (int i=0; i<sz; ++i) {
			int mx = a[i];
			dp[i+1] = a[i] + dp[i];
			for (int j=1; j<k && i-j>=0; ++j) {
				mx = max(a[i-j], mx);
				dp[i+1] = max(dp[i+1], dp[i-j]+(j+1)*mx);
			}
		}
		return dp[sz];
	}
};
