#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define MAXK ((int64_t)1000000000LL)
#define calc(i, curs) (dp[n][cidx[nxt[curs][i]-'a']])

int64_t dp[MAXN+1][3];
int cidx[26];
char nxt[4][5] = { "hio", "hi", "ho", "hiho" };
int nlen[4] = { 3, 2, 2, 4 };


void init() {
	cidx['h'-'a'] = 0;
	cidx['i'-'a'] = 1;
	cidx['o'-'a'] = 2;

	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	for (int i=2; i<=MAXN; ++i) {
		dp[i][0] = min(MAXK, dp[i-1][0] + dp[i-1][1] + dp[i-1][2]);
		dp[i][1] = min(MAXK, dp[i-1][0] + dp[i-1][1]);
		dp[i][2] = min(MAXK, dp[i-1][0] + dp[i-1][2]);
	}
}

int main() {
	init();
	int t; scanf("%d", &t);
	while (t--) {
		int n, k; scanf("%d%d", &n, &k);

		int curs = 3;
		while (n != 1) {
			int64_t take = 0, i;
			for (i=0; i<nlen[curs] && take+calc(i, curs)<k; ++i) {
				take += calc(i, curs);
			}

			k -= take;
			curs = cidx[nxt[curs][i]-'a'];
			--n;
		}

		printf("%c\n", nxt[curs][k-1]);
	}
	return 0;
}
