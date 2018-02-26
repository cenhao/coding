#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numTilings(int N) {
		const int MOD = 1000000007;
		vector<vector<int>> dp(N+1, vector<int>(4, 0));
		dp[0][3] = 1;
		for (int i=1; i<=N; ++i) {
			dp[i][3] = (dp[i][3] + dp[i-1][1]) % MOD;
			dp[i][3] = (dp[i][3] + dp[i-1][2]) % MOD;
			dp[i][3] = (dp[i][3] + dp[i-1][3]) % MOD;
			dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD;
			dp[i][1] = (dp[i][1] + dp[i-1][2]) % MOD;
			dp[i][2] = (dp[i][2] + dp[i-1][0]) % MOD;
			dp[i][2] = (dp[i][2] + dp[i-1][1]) % MOD;
			dp[i][0] = (dp[i][0] + dp[i-1][3]) % MOD;
			if (i > 1) {
				dp[i][3] = (dp[i][3] + dp[i-2][3]) % MOD;
			}
		}

		return dp[N][3];
	}
};

int main() {
	int n; cin >> n;
	Solution sol;
	cout << sol.numTilings(n) << endl;
	return 0;
}
