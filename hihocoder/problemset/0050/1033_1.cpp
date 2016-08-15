/*
 * hihocoder 1033
 * Another way of implementing it.
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXL 18
#define MAXD 10
#define MAXK 100
#define MOD 1000000007LL

int64_t base[MAXL+2];
int digit[MAXL+2];

struct Item {
	int64_t sum, cnt;
} dp[MAXL+2][MAXD+1][2*MAXK+1];

void init() {
	memset(dp, -1, sizeof(dp));
	base[0] = 0LL; base[1] = 1LL;
	for (int i=2; i<=MAXL+1; ++i) {
		base[i] = (base[i-1] * 10LL) % MOD;
	}
}

Item get(int firstDigit, int pos, int k, bool first) {
	if (k > 100 || k < -100) { // This is important.
		Item ret = {0LL, 0LL};
		return ret;
	}

	int adj = (firstDigit == 0 && first) ? MAXD : 0;
	if (dp[pos][firstDigit+adj][k+MAXK].cnt >= 0) {
		return dp[pos][firstDigit+adj][k+MAXK];
	}

	if (pos == 0) {
		dp[pos][firstDigit+adj][k+MAXK].sum = 0LL;
		dp[pos][firstDigit+adj][k+MAXK].cnt =
			(k == 0 && firstDigit == 0) ? 1LL : 0LL;
		return dp[pos][firstDigit+adj][k+MAXK];
	}

	Item &item = dp[pos][firstDigit+adj][k+MAXK];
	item.cnt = 0; item.sum = 0;

	if (adj != MAXD) {
		for (int lv=0; lv<MAXD; ++lv) {
			Item tmp = get(lv, pos-1, firstDigit-k, false);
			item.cnt = (item.cnt + tmp.cnt) % MOD;
			item.sum = (item.sum + tmp.sum + (firstDigit * ((tmp.cnt * base[pos]) % MOD) % MOD)) % MOD;
		}
	} else {
		Item tmp = get(0, pos-1, k, true);
		item.cnt = (item.cnt + tmp.cnt) % MOD;
		item.sum = (item.sum + tmp.sum) % MOD;
		for (int lv=1; lv<MAXD; ++lv) {
			tmp = get(lv, pos-1, k, false);
			item.cnt = (item.cnt + tmp.cnt) % MOD;
			item.sum = (item.sum + tmp.sum) % MOD;
		}
	}

	return item;
}

Item dfs(int dn, int k, bool first) {
	if (dn == 0) { return get(0, 0, k, first); }

	Item ret = {0, 0};
	for (int i=0; i<digit[dn-1]; ++i) {
		Item tmp = get(i, dn, k, first);
		ret.cnt = (ret.cnt + tmp.cnt) % MOD;
		ret.sum = (ret.sum + tmp.sum) % MOD;
	}

	Item tmp = dfs(dn-1, digit[dn-1]-k, false);
	ret.cnt = (ret.cnt + tmp.cnt) % MOD;
	ret.sum = (ret.sum + tmp.sum + (((base[dn]*tmp.cnt)%MOD)*digit[dn-1])%MOD) % MOD;

	return ret;
}

int64_t dfs(int64_t v, int k) {
	int dcnt = 0;
	while (v > 0) {
		digit[dcnt++] = v % 10;
		v /= 10;
	}

	return dfs(dcnt, k, true).sum;
}

int main() {
	init();

	int64_t l, r;
	int k;
	while (EOF != scanf("%"SCNd64"%"SCNd64"%d", &l, &r, &k)) {
		int64_t a = dfs(l-1, k);
		int64_t b = dfs(r, k);
		int64_t ans = (((b - a) % MOD) + MOD) % MOD;
		printf("%"PRId64"\n", ans);
	}

	return 0;
}
