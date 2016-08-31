#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXM 100000
int dp[MAXM + 1];

int main() {
	memset(dp, 0, sizeof(dp));
	int n, m;
	scanf("%d %d", &n, &m);

	for (int lv=0; lv<n; ++lv) {
		int need, value;
		scanf("%d %d", &need, &value);

		for (int lv2=m; lv2>=need; --lv2) {
			dp[lv2] = max(dp[lv2], dp[lv2-need]+value);
		}
	}

	printf("%d\n", dp[m]);
	return 0;
}
