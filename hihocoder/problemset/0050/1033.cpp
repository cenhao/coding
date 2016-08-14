/*
 * Hihocoder 1033 - Cross Sum
 * My first `digit dp`
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXK 100
#define MAXD 10
#define MAXL 18 
#define MOD 1000000007LL

int64_t sum[MAXL+1][MAXD][2*MAXK+1];
int64_t cnt[MAXL+1][MAXD][2*MAXK+1];
int64_t zsum[MAXL+1][2*MAXK+1];
int64_t zcnt[MAXL+1][2*MAXK+1];
int digits[MAXL+2];
int dcnt;

struct Result {
	int64_t sum, cnt;
};

void preprocess() {
	memset(sum, 0LL, sizeof(sum));
	memset(cnt, 0LL, sizeof(cnt));
	memset(zcnt, 0LL, sizeof(zcnt));
	memset(zsum, 0LL, sizeof(zsum));

	cnt[0][0][0+MAXK] = 1;
	int end = MAXK * 2 + 1;
	int64_t base = 1;
	for (int lv=1; lv<=MAXL; ++lv) {
		for (int lv2=0; lv2<MAXD; ++lv2) {
			for (int lv3=0; lv3<MAXD; ++lv3) {
				for (int lv4=0; lv4<end; ++lv4) {
					if (cnt[lv-1][lv3][lv4] <= 0) { continue; }
					int v = lv2 - (lv4 - MAXK) + MAXK;
					cnt[lv][lv2][v] += cnt[lv-1][lv3][lv4];
					cnt[lv][lv2][v] %= MOD;
					sum[lv][lv2][v] +=
						((((cnt[lv-1][lv3][lv4]*lv2)%MOD)*base % MOD) +
						sum[lv-1][lv3][lv4]) % MOD;
				}
			}
		}

		base = (base * 10) % MOD;
	}

	for (int lv=1; lv<=MAXL; ++lv) {
		for (int lv2=0; lv2<end; ++lv2) {
			zcnt[lv][lv2] = zcnt[lv-1][lv2];
			zsum[lv][lv2] = zsum[lv-1][lv2];
		}
		for (int lv2=1; lv2<MAXD; ++lv2) {
			for (int lv3=0; lv3<end; ++lv3) {
				if (cnt[lv-1][lv2][lv3] <= 0) { continue; }
				zcnt[lv][lv3] += cnt[lv-1][lv2][lv3];
				zcnt[lv][lv3] %= MOD;
				zsum[lv][lv3] += sum[lv-1][lv2][lv3];
				zsum[lv][lv3] %= MOD;
			}
		}
	}
}

Result findInternal(int idx, int need, bool first) {
	if (idx <= 0) {
		Result res;
		res.sum = 0LL;
		res.cnt = (need == 0) ? 1LL : 0LL;
		return res;
	}

	int64_t base = 1;
	for (int i=1; i<idx; ++i) {
		base = (base * 10) % MOD;
	}

	int64_t rs = 0LL;
	int64_t rc = 0LL;
	for (int i=0; i<digits[idx-1]; ++i) {
		if (i==0 && first) {
			rs = (rs + zsum[idx][need+MAXK]) % MOD;
			rc = (rc + zcnt[idx][need+MAXK]) % MOD;
		} else {
			rs = (rs + sum[idx][i][need+MAXK]) % MOD;
			rc = (rc + cnt[idx][i][need+MAXK]) % MOD;
		}
	}

	Result extra = findInternal(idx-1, digits[idx-1]-need, false);
	rs = (rs + extra.sum + (digits[idx-1] * extra.cnt * base) % MOD) % MOD;
	rc = (rc + extra.cnt) % MOD;
	Result res;
	res.sum = rs; res.cnt = rc;
	return res;
}

int64_t find(int64_t v, int k) {
	dcnt = 0;
	while (v > 0) {
		digits[dcnt++] = v % 10;
		v /= 10;
	}

	return findInternal(dcnt, k, true).sum;
}

int main() {
	int64_t l, r;
	int k;
	preprocess();
	while (EOF != scanf("%"SCNd64"%"SCNd64"%d", &l, &r, &k)) {
		int64_t a = find(l-1, k);
		int64_t b = find(r, k);
		a = (((b - a) % MOD) + MOD) % MOD;
		printf("%"PRId64"\n", a);
	}

	return 0;
}
