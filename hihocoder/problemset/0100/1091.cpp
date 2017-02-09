#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXM 20000
#define GROW_BOUNDARY 15

int dp[2][MAXM+1];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	memset(dp, 0, sizeof(dp));
	int cur = 0, pre = 0;
	for (int i=0; i<n; ++i) {
		int a, b; scanf("%d %d", &a, &b);

		if (b < GROW_BOUNDARY) {
			cur = pre;
			for (int j=b; j<=m; ++j) {
				dp[cur][j] = max(dp[cur][j], dp[pre][j-b]+a);
			}
		} else {
			cur = (pre + 1) & 1;
			memcpy(dp[cur], dp[pre], (m+1)*sizeof(int));
			for (int j=b, bb=b, aa=a; j<=m; aa+=a, j+=bb) {
				for (int k=j; k<=m; ++k) {
					dp[cur][k] = max(dp[cur][k], dp[pre][k-j]+aa);
				}

				bb *= 1.07;
			}
		}

		pre = cur;
	}

	printf("%d\n", dp[pre][m]);
	return 0;
}
