#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 100

int score[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for (int lv=0; lv<n; ++lv) {
		for (int lv2=0; lv2<=lv; ++lv2) {
			scanf("%d", &score[lv][lv2]);
		}
	}

	int last = n - 1;
	for (int lv=0; lv<n; ++lv) {
		dp[last][lv] = score[last][lv];
	}

	for (int lv=n-2; lv>=0; --lv) {
		int next = lv + 1;
		for (int lv2=0; lv2<=lv; ++lv2) {
			dp[lv][lv2] = score[lv][lv2] + max(dp[next][lv2], dp[next][lv2+1]);
		}
	}

	printf("%d\n", dp[0][0]);
	return 0;
}
