/*
 * Timus 1057 Amounts of degrees
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXE 32
#define MAXB 10

int dp[MAXE][MAXE];
int cnt[MAXB+1];
int64_t base[MAXB+1][MAXE];

void preprocess() {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;

	for (int lv=1; lv<MAXE; ++lv) {
		dp[lv][0] = 1;
		for (int lv2=1; lv2<=lv; ++lv2) {
			dp[lv][lv2] = dp[lv-1][lv2] + dp[lv-1][lv2-1];
		}
	}

	memset(cnt, 0, sizeof(cnt));
	for (int i=2; i<=10; ++i) {
		cnt[i] = 1;
		base[i][0] = 1;

		while (base[i][cnt[i]-1]*i <= 0x7fffffff) {
			base[i][cnt[i]] = base[i][cnt[i]-1] * i;
			++cnt[i];
		}
	}
}

int find(int64_t v, int k, int b) {
	int idx = cnt[b] - 1;
	int ret = 0;

	while (idx >= 0 && k >= 0) {
		if (v >= base[b][idx]) {
			ret += dp[idx][k];
			--k;
			if (v >= 2*base[b][idx]) {
				v = base[b][idx] - 1;
			}
			v %= base[b][idx];
		}

		--idx;
	}

	// if k == 0, meaning v contains exactly k 1s,
	// and in the above loop, we need k+1 1s in v
	// to correctly calculate the result
	if (k == 0) { ++ret; }

	return ret;
}

int main() {
	int x, y, k, b;
	preprocess();

	while (EOF != scanf("%d%d%d%d", &x, &y, &k, &b)) {
		int v1 = find(x-1, k, b);
		int v2 = find(y, k, b);
		printf("%d\n", v2-v1);
	}

	return 0;
}
