#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int kInversePairs(int n, int k) {
		int MOD = 1000000007;
		vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
		for (int i=1; i<=n; ++i) { dp[0][i] = 1; }
		int end = 0;
		for (int i=2; i<=n; ++i) {
			end = min(k, end+(i-1));
			int sum = dp[0][i-1];
			for (int j=1; j<=end; ++j) {
				if (j-i >= 0) {
					sum = sum - dp[j-i][i-1];
					if (sum < 0) { sum += MOD; }
				}
				sum = (sum + dp[j][i-1]) % MOD;
				dp[j][i] = sum;
			}
		}

		return dp[k][n];
	}
};

int main() {
	int n, k; cin >> n >> k;
	Solution sol;
	cout << sol.kInversePairs(n, k) << endl;
	return 0;
}
