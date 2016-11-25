/*
 * Find the count of numbers matching the following criteria:
 * 1. Contains '2', '3', or '5' (at least one)
 * 2. Does not contain '18'
 * 3. Can be devided by 7
 * within a range [a, b], where 0 <= a <= b <= 10^18
 */

#include <algorithm>
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstring>
using namespace std;

#define MOD 7
#define MAXL 19

// length of number, highest digit, remainder, must contains 2/3/5
int64_t dp[MAXL][10][MOD][2];

void init() {
	memset(dp, 0, sizeof(dp));
	for (int i=0; i<10; ++i) {
		dp[0][i][i%MOD][0] = 1LL;
		if (i == 2 || i == 3 || i == 5) {
			dp[0][i][i%MOD][1] = 1LL;
		}
	}

	int64_t base = 1;
	for (int i=1; i<MAXL; ++i) {
		base *= 10;
		for (int i1=0; i1<10; ++i1) {
			int r = (i1 * base) % MOD;
			for (int i2=0; i2<10; ++i2) {
				//if (i1 == 0 && i2 == 0) { continue; } // consecutive 0s
				if (i1 == 1 && i2 == 8) { continue; } // 18

				// if i1 is 2/3/5, any value after that is accepted
				int idx = (i1 == 2 || i1 == 3 || i1 == 5) ? 0 : 1;
				for (int i3=0; i3<MOD; ++i3) {
					dp[i][i1][(i3+r)%MOD][0] += dp[i-1][i2][i3][0];
					dp[i][i1][(i3+r)%MOD][1] += dp[i-1][i2][i3][idx];
				}
			}
		}
	}
}

int64_t query(int64_t v) {
	if (v < 0) { return 0; }
	int64_t base = 1;
	int length = 0;
	while (v / base >= 10) {
		base *= 10;
		++length;
	}
	int64_t ans = 0LL;
	int r = 0, last = -1;
	bool with235 = false;

	while (length >= 0) {
		int first = v / base;
		if (base == 1) { ++first; } // also take the number itself as cannot go deeper.
		int idx = with235 ? 0 : 1;
		for (int i=0; i<first; ++i) {
			if (last == 1 && i == 8) { continue; }
			ans += dp[length][i][r][idx];
		}

		if (first == 8 && last == 1) { break; }

		if (first == 2 || first == 3 || first == 5) { with235 = true; }
		int64_t cur = first * base;
		r = (r + MOD - (cur % MOD)) % MOD;
		last = first;
		v -= first * base;
		base /= 10;
		--length;
	}

	return ans;
}

int main() {
	init();
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		int64_t a, b; scanf("%" SCNd64 " %" SCNd64 "", &a, &b);
		int64_t va = query(a-1);
		int64_t vb = query(b);
		printf("%" PRId64 "\n", vb - va);
	}

	return 0;
}
