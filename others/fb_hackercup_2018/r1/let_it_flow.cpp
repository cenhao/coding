#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
#define MOD 1000000007

char mat[3][MAXN+1];

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int n; scanf("%d", &n);
		for (int i=0; i<3; ++i) { scanf("%s", mat[i]); }

		// 0 -> down, 1 -> up, 2 -> forward
		int dp[2][3][3];
		memset(dp, 0, sizeof(dp));
		dp[1][0][2] = 1;

		for (int i=0; i<n; ++i) {
			int pre = (i+1) & 1, cur = i & 1;
			for (int j=0; j<3; ++j) {
				dp[cur][j][0] = dp[cur][j][1] = mat[j][i]=='#' ? 0 : dp[pre][j][2];
			}
			for (int j=0; j<3; ++j) {
				dp[cur][j][2] = 0;
				if (mat[j][i] != '#') {
					if (j != 0) {
						dp[cur][j][2] = dp[cur][j-1][0];
					}
					if (j != 2) {
						dp[cur][j][2] = (dp[cur][j][2]+dp[cur][j+1][1]) % MOD;
					}
				}
			}
		}

		int cur = (n-1) & 1;
		printf("Case #%d: %d\n", t, dp[cur][2][2]);
	}
	return 0;
}
