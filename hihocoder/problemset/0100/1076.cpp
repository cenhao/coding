/*
 * Hiho coder 1076
 * This is a great question, in short this problem can be solved as:
 * For each bit, it can be used at most k times, how many solutions will
 * there be.
 *
 * This can be solved as a muliple back pack problem, however, unlike
 * calculating the maximum gain, calculating the # of solution can only be
 * solved in the hard way: enumerate every one of every type of item one
 * by one, while the maximum can be optimized as binary number.
 */
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 10000
#define MOD 1000000009
#define LOG2MAXN 13

int pack[LOG2MAXN+2][MAXN+1];

int main() {
	int t;
	for (scanf("%d", &t); t; --t) {
		int k, n; scanf("%d %d", &k, &n);
		memset(pack, 0, sizeof(pack));
		pack[0][0] = 1;

		int mx = 0, ei = 0; // ei = 0 is important
		for (int i=1, base=1; base<=n; ++i, base<<=1) {
			ei = i;
			for (int i1=0; i1<=mx; ++i1) { pack[i][i1] = pack[i-1][i1]; }
			int mmx = 0;
			for (int cnt=1; cnt*base<=n && cnt<=k; ++cnt) {
				int w = cnt * base;
				mmx = min(n, mx+w);
				for (int i1=min(n, mx+w); i1>=w; --i1) {
					pack[i][i1] = (pack[i][i1] + pack[i-1][i1-w]) % MOD;
				}
			}
			mx = mmx;
		}

		printf("%d\n", pack[ei][n]);
	}

	return 0;
}

