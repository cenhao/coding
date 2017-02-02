#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 12

int dp[MAXN][1 << MAXN];
bool e[MAXN][MAXN];

int main() {
	memset(dp, 0, sizeof(dp));
	memset(e, 0, sizeof(e));

	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		e[a-1][b-1] = true;
	}

	int full = (1 << n) - 1;
	dp[0][1] = 1;

	for (int i=1; i<=full; ++i) {
		for (int j=0; j<n; ++j) {
			if (!((1<<j) & i)) { continue; }
			for (int k=0; k<n; ++k) {
				if (j == k || !e[k][j] || !((1<<k) & i)) { continue; }
				dp[j][i] += dp[k][(~(1<<j))&i];
			}
		}
	}

	int ans = 0;
	for (int i=1; i<n; ++i) {
		if (e[i][0]) { ans += dp[i][full]; }
	}

	printf("%d\n", ans);
	return 0;
}
