#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 1000
#define MAXM 10

int dp[MAXN+1][1<<MAXM];
int w[MAXN+1];
int cnt[1<<MAXM];

void preprocess(int m) {
	for (int i=0, end=1<<m; i<end; ++i) {
		int c = 0;
		for (int i2=0; i2<m; ++i2) {
			if (i & (1<<i2)) { ++c; }
		}
		cnt[i] = c;
	}
}

int process(int n, int m, int q) {
	memset(dp, 0, sizeof(dp));
	preprocess(m);
	int cur = 1 << (m-1);
	int end = 1 << m;

	for (int i=1; i<=n; ++i) {
		for (int i2=0; i2<end; ++i2) {
			if (cnt[i2] > q) { continue; }
			int pre = (i2 & (~cur)) << 1;
			dp[i][i2] = max(dp[i-1][pre], dp[i-1][pre+1]) + ((i2&cur) ? w[i] : 0);
		}
	}

	int mx = 0;
	for (int i=0; i<end; ++i) {
		mx = max(dp[n][i], mx);
	}

	return mx;
}

int main() {
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	for (int i=1; i<=n; ++i) { scanf("%d", &w[i]); }
	printf("%d\n", process(n, m, q));
	return 0;
}
