/*
ID: cenhao11
PROG: ratios
LANG: C++11
*/

/* there's another way to solve this problem
 * with linear algebra
 */

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXN 100
#define INF 0x7fff0000

int target[3];
int mixtures[3][3];
int sum[3], ratio[3];
int ans[3];

int main() {
	freopen("ratios.in", "r", stdin);
	freopen("ratios.out", "w", stdout);

	for (int i=0; i<3; ++i) { scanf("%d", &target[i]); }
	for (int i=0; i<3; ++i) {
		for (int j=0; j<3; ++j) {
			scanf("%d", &mixtures[i][j]);
		}
	}

	int mn = INF;
	for (int i=0; i<MAXN; ++i) {
		for (int j=0; j<MAXN; ++j) {
			for (int k=0; k<MAXN; ++k) {
				for (int l=0; l<3; ++l) {
					sum[l] = mixtures[0][l]*i + mixtures[1][l]*j + mixtures[2][l]*k;
					if (target[l] == 0) {
						if (sum[l] == 0) {
							ratio[l] = 0;
						} else {
							ratio[l] = -1;
						}
					} else {
						if (sum[l] != 0 && sum[l] % target[l] == 0) {
							ratio[l] = sum[l] / target[l];
						} else {
							ratio[l] = -1;
						}
					}
				}
				
				if ((ratio[0] == ratio[1] || ratio[0] == 0 || ratio[1] == 0) &&
						(ratio[0] == ratio[2] || ratio[0] == 0 || ratio[2] == 0) &&
						(ratio[1] == ratio[2] || ratio[1] == 0 || ratio[2] == 0)) {
					int tmp = min(ratio[0], min(ratio[1], ratio[2]));
					if (tmp >= 0) {
						tmp = max(ratio[0], max(ratio[1], ratio[2]));
						if (mn > tmp) {
							mn = tmp;
							ans[0] = i; ans[1] = j; ans[2] = k;
						}
					}
				}
			}
		}
	}

	if (mn != INF) {
		printf("%d %d %d %d\n", ans[0], ans[1], ans[2], mn);
	} else {
		printf("NONE\n");
	}

	return 0;
}
