/*
ID: cenhao11
PROG: nuggets
LANG: C++11
*/

#include <stdio.h>
#include <string.h>

#define MAXN 10
#define MAXB 256
#define SIZE (MAXB*MAXB+1)

int nuggets[MAXN], n;
int dp[SIZE];

int gcd(int a, int b) {
	int tmp;
	while (b != 0) {
		tmp = a;
		a = b;
		b = tmp % b;
	}

	return a;
}

int main() {
	freopen("nuggets.in", "r", stdin);
	freopen("nuggets.out", "w", stdout);

	scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &nuggets[i]); }

	if (n == 1) {
		printf("0\n");
		return 0;
	}

	int d = nuggets[0];
	for (int i=1; i<n; ++i) { d = gcd(d, nuggets[i]); }

	if (d != 1) {
		printf("0\n");
		return 0;
	}

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int lv=0; lv<n; ++lv) {
		for (int lv2=nuggets[lv]; lv2<SIZE; ++lv2) {
			if (dp[lv2-nuggets[lv]] == 1) {
				dp[lv2] = 1;
			}
		}
	}

	int mx = 0;
	for (int lv=SIZE-1; lv>=0; --lv) {
		if (dp[lv] == 0) {
			mx = lv;
			break;
		}
	}

	printf("%d\n", mx);
}
