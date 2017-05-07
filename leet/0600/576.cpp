class Solution {
public:
	int findPaths(int n, int m, int N, int a, int b) {
		const int maxn = 50, MOD = 1000000007;
		int64_t dp[maxn+2][maxn+2][maxn+1];
		memset(dp, 0, sizeof(dp));
		dp[a][b][0] = 1;
		int64_t ans = 0;
		if (N > 0) {
			if (a == 0) { ans += 1; }
			if (a == n-1) { ++ans; }
			if (b == 0) { ++ans; }
			if (b == m-1) { ++ans; }
		}
		ans %= MOD;
		const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
		for (int k=1; k<N; ++k) {
			for (int i=0; i<n; ++i) {
				for (int j=0; j<m; ++j) {
					for (int d=0; d<4; ++d) {
						int x = i+dir[d][0], y = j+dir[d][1];
						if (x < 0 || x >= n || y < 0 || y >= m) { continue; }
						dp[i][j][k] = (dp[i][j][k] + dp[x][y][k-1]) % MOD;
					}

					if (i == 0) { ans += dp[i][j][k]; }
					if (i == n-1) { ans += dp[i][j][k]; }
					if (j == 0) { ans += dp[i][j][k]; }
					if (j == m-1) { ans += dp[i][j][k]; }
					ans %= MOD;
				}
			}
		}

		return ans;
	}
};
