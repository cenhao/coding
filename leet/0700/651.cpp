class Solution {
public:
	int maxA(int N) {
		vector<int> dp(N+1, 0);
		for (int i=1; i<=N; ++i) { dp[i] = i; }
		for (int i=4; i<=N; ++i) {
			for (int j=i; j<=N; ++j) {
				dp[j] = max(dp[j], dp[i-3]*(j-i+2));
			}
		}

		return dp[N];
	}
};
