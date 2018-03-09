#include <bits/stdc++.h>
using namespace std;

#define MAXN 30

int a[MAXN+1],  order[MAXN+1][MAXN+1][MAXN+1], ans[MAXN+1];
int64_t dp[MAXN+1][MAXN+1];

int dfs(int l, int r, int d, int64_t need) {
	if (r < l) { return 0; }
	int pd = d;
	for (int i=0, end=r-l+1; i<end; ++i) {
		int pos = order[l][r][i];
		int64_t lv = (pos-1<l) ? 1 : dp[l][pos-1];
		int64_t rv = (pos+1>r) ? 1 : dp[pos+1][r];
		int64_t tmp = lv * rv;
		if (tmp < need) {
			need -= tmp;
		} else {
			ans[d++] = a[pos];
			int64_t lneed = (need-1) / rv + 1;
			d += dfs(l, pos-1, d, lneed);
			int64_t rneed = ((need-1) % rv) + 1;
			d += dfs(pos+1, r, d, rneed);
			break;
		}
	}

	return d - pd;
}

int main() {
	int n, K; scanf("%d%d", &n, &K);
	for (int *ptr=a, *end=&a[n]; ptr!=end; ++ptr) { scanf("%d", ptr); }
	for (int j=0; j<n; ++j) {
		for (int i=j; i>=0; --i) {
			dp[i][j] = 0;
			for (int k=i; k<=j; ++k) {
				int64_t l = (k-1<i) ? 1 : dp[i][k-1];
				int64_t r = (k+1>j) ? 1 : dp[k+1][j];
				dp[i][j] += l * r;
			}
		}
	}

	for (int j=0; j<n; ++j) {
		for (int i=j; i>=0; --i) {
			if (i == j) {
				order[i][j][0] = i;
				continue;
			}

			int sv = a[order[j][j][0]], pos = 0;
			for (int end=j-i; a[order[i][j-1][pos]]<sv && pos<end; ++pos) {
				order[i][j][pos] = order[i][j-1][pos];
			}

			order[i][j][pos++] = order[j][j][0];
			for (int end=j-i+1; pos<end; ++pos) {
				order[i][j][pos] = order[i][j-1][pos-1];
			}
		}
	}

	dfs(0, n-1, 0, K);
	for (int i=0; i<n; ++i) { printf("%d\n", ans[i]); }

	return 0;
}
