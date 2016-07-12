/*
ID: cenhao11
PROG: sort3
LANG: C++11
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXN 1005

int val[MAXN];
int sorted[MAXN];

int main() {
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);

	int n;
	int res = 0;

	scanf("%d", &n);

	for (int i=0; i<n; ++i) {
		scanf("%d", &val[i]);
		sorted[i] = val[i];
	}

	sort(sorted, sorted+n);

	for (int i=0; i<n; ++i) {
		if (sorted[i] == val[i]) { continue; }
		int choose = -1;
		for (int j=i+1; j<n; ++j) {
			if (val[j] == sorted[i] && val[i] == sorted[j]) {
				choose = j;
				break;
			} else if (val[j] == sorted[i] && val[j] != sorted[j] && choose == -1) {
				choose = j;
			}
		}

		val[i] = sorted[i];
		val[choose] = sorted[choose];
		++res;
	}

	printf("%d\n", res);
	return 0;
}
