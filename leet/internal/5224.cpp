class Solution {
public:
	int dieSimulator(int n, vector<int>& rollMax) {
		vector<vector<vector<int>>> dp(2, vector<vector<int>>(6, vector<int>(16, 0)));
		const int MOD = 1000000007;
		for (int i=0; i<6; ++i) { dp[0][i][1] = 1; }
		for (int i=1; i<n; ++i) {
			int cur = i & 1, pre = (i+1) & 1;
			for (int j=0; j<6; ++j) {
				for (int k=1; k<=rollMax[j]; ++k) { dp[cur][j][k] = 0; }
			}
			for (int j=0; j<6; ++j) {
				for (int k=1; k<=rollMax[j]; ++k) {
					for (int nxt=0; nxt<6; ++nxt) {
						if (j != nxt) {
							dp[cur][nxt][1] = (dp[cur][nxt][1]+dp[pre][j][k]) % MOD;
						} else if (k+1 <= rollMax[j]) {
							dp[cur][j][k+1] = (dp[cur][j][k+1]+dp[pre][j][k]) % MOD;
						}
					}
				}
			}
		}

		int ans = 0, idx = (n-1) & 1;
		for (int i=0; i<6; ++i) {
			for (int j=1; j<=rollMax[i]; ++j) {
				ans = (ans + dp[idx][i][j]) % MOD;
			}
		}

		return ans;
	}
};
