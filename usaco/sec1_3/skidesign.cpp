/*
PROG: skidesign
ID: cenhao11
LANG: C++11
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXN 1005
#define MAXH 105
#define GAP 17
#define INF 0x7fffffff

int h[MAXN];

int main() {
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);

	int n;
	while (EOF != scanf("%d", &n)) {
		int mx = -1, mn = MAXH;
		for (int i=0; i<n; ++i) {
			scanf("%d", &h[i]);
			mx = (h[i] > mx) ? h[i] : mx;
			mn = (h[i] < mn) ? h[i] : mn;
		}

		int cost = INF;
		for (int i=max(mx-GAP, mn); i>=mn; --i) {
			int sum = 0;
			for (int j=0; j<n; ++j) {
				if (h[j] < i || h[j] > i+GAP) {
					sum += min((h[j]-i)*(h[j]-i), (i+GAP-h[j])*(i+GAP-h[j]));
				}
			}
			cost = min(cost, sum);
		}

		printf("%d\n", cost);
	}

	return 0;
}
