#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXL 20

int a[MAXN];
int mxl[MAXN];
int rmqv[MAXL][MAXN], rmqp[MAXL][MAXN];

void calc_mxl(int n) {
	for (int i=1, lv=0, lp=0; i<=n; ++i) {
		if (i==n || a[i]-a[i-1]!=lv) {
			for (int j=lp; j<i; ++j) { mxl[j] = max(mxl[j], i-j); }
			lv = a[i]-a[i-1];
			lp = i-1;
		}
	}
}

void calc_rmq(int n) {
	for (int i=0; i<n; ++i) {
		rmqv[0][i] = mxl[i];
		rmqp[0][i] = i;
	}

	for (int i=1; (1<<i)<n; ++i) {
		int full = 1<<i, half = 1<<(i-1);
		for (int j=0, end=n+1-full; j<end; ++j) {
			int nxt = j+half;
			bool pick_first = rmqv[i-1][j] > rmqv[i-1][nxt];
			rmqv[i][j] = pick_first ? rmqv[i-1][j] : rmqv[i-1][nxt];
			rmqp[i][j] = pick_first ? rmqp[i-1][j] : rmqp[i-1][nxt];
		}
	}
}

void query_rmq(int l, int r, int &mxv, int &mxp) {
	if (l == r) {
		mxv = rmqv[0][l];
		mxp = rmqp[0][l];
		return;
	}
	int itv = r - l + 1;
	int pw = int(ceil(log2(double(itv))))-1;
	int len = 1 << pw;
	int nxt = r-len+1;
	bool pick_first = rmqv[pw][l] > rmqv[pw][nxt];
	mxv = pick_first ? rmqv[pw][l] : rmqv[pw][nxt];
	mxp = pick_first ? rmqp[pw][l] : rmqp[pw][nxt];
}

int main() {
	int n, q; scanf("%d%d", &n, &q);
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }
	memset(mxl, 0, sizeof(mxl));

	calc_mxl(n);
	calc_rmq(n);

	for (int i=0; i<q; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		--l; --r;
		int mxv, mxp, rr = r, trunc;
		int ans = 0;
		do {
			query_rmq(l, r, mxv, mxp);
			r = mxp - 1;
			trunc = rr - mxp + 1;
			ans = max(ans, min(trunc, mxv));
		} while (l<=r && mxv>trunc);
		printf("%d\n", ans);
	}

	return 0;
}
