#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 1000000
#define LOG2N 20

int rmq[MAXN+1][LOG2N];

int log2floor(int x, int &len) {
	int cnt = 0;
	len = 1;
	while (x > 1) {
		++cnt;
		len += len;
		x >>= 1;
	}

	return cnt;
}

int log2floor(int x) {
	int len;
	return log2floor(x, len);
}

int main() {
	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) { scanf("%d", &rmq[i][0]); }

	int log2n = log2floor(n);
	for (int i=1, len=1; i<=log2n; ++i, len+=len) {
		for (int i2=1, end=n-len-len+1; i2<=end; ++i2) {
			rmq[i2][i] = min(rmq[i2][i-1], rmq[i2+len][i-1]);
		}
	}

	int q; scanf("%d", &q);
	while (q--) {
		int l, r, len; scanf("%d %d", &l, &r);
		int p = log2floor(r - l + 1, len);
		printf("%d\n", min(rmq[l][p], rmq[r-len+1][p]));
	}

	return 0;
}
