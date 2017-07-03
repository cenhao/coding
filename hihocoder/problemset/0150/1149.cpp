#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
#define MOD 100007

int dp[MAXN][MAXN+1];
char str[MAXN+1];

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		scanf("%s", str);
		int len = strlen(str);
		for (int i=0; i<len; ++i) {
			dp[i][0] = 0; dp[i][1] = 1;
		}

		for (int i=2; i<=len; ++i) {
			for (int h=0; h+i<=len; ++h) {
				dp[h][i] = dp[h][i-1] + dp[h+1][i-1];
				dp[h][i] += ((str[h] == str[h+i-1]) ? 1 : -dp[h+1][i-2]);
				while (dp[h][i] < 0) { dp[h][i] += MOD; }
				dp[h][i] %= MOD;
			}
		}

		printf("Case #%d: %d\n", t, dp[0][len]);
	}

	return 0;
}
