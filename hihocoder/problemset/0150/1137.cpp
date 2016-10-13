#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXB 1000
#define MAXN 100

int dp[2][MAXN+1][MAXB+1];
struct Pick {
	uint64_t lower;
	uint64_t upper;
	void set(int bit) {
		if (bit > 64) {
			upper |= 1ULL << (bit-1-64);
		} else {
			lower |= 1ULL << (bit-1);
		}
	}
	bool get(int bit) {
		if (bit > 64) {
			return upper & (1ULL << bit-1-64);
		}
		return lower & (1ULL<<(bit-1));
	}
	bool operator <(const Pick& p) const {
		if (lower != p.lower) {
			uint64_t diff = lower ^ p.lower;
			uint64_t lb = diff & (~(diff-1));

			return lower & lb;
		}

		uint64_t diff = upper ^ p.upper;
		uint64_t lb = diff & (~(diff-1));

		return upper & lb;
	}
	void merge(const Pick& p) {
		lower |= p.lower;
		upper |= p.upper;
	}
} pick[2][MAXN+1][MAXB+1];

int main() {
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = dp[1][0][0] = 0;
	memset(pick, 0, sizeof(pick));

	int n, x, y, b; scanf("%d %d %d %d", &n, &x, &y, &b);

	for (int i=1; i<=n; ++i) {
		char gender[5]; int v, s;
		scanf("%s %d %d", gender, &v, &s);

		int idx, end;
		if (gender[0] == 'M') {
			idx = 0; end = x;
		} else {
			idx = 1; end = y;
		}

		for (int i1=end; i1>0; --i1) {
			for (int i2=b; i2>=s; --i2) {
				if (dp[idx][i1-1][i2-s] < 0) { continue; }
				if (dp[idx][i1-1][i2-s]+v > dp[idx][i1][i2]) {
					dp[idx][i1][i2] = dp[idx][i1-1][i2-s]+v;
					pick[idx][i1][i2] = pick[idx][i1-1][i2-s];
					pick[idx][i1][i2].set(i);
				} else if (dp[idx][i1-1][i2-s]+v == dp[idx][i1][i2]) {
					Pick tmp = pick[idx][i1-1][i2-s];
					tmp.set(i);
					if (tmp < pick[idx][i1][i2]) { pick[idx][i1][i2] = tmp; }
				}
			}
		}
	}

	int mx = 0;
	int cost = 0;
	Pick ans;
	for (int i=0; i<=b; ++i) {
		if (dp[0][x][i] < 0) { continue; }
		for (int i1=b-i; i1>=0; --i1) {
			if (dp[1][y][i1] < 0) { continue; }

			if (dp[0][x][i] + dp[1][y][i1] > mx) {
				mx = dp[0][x][i] + dp[1][y][i1];
				cost = i + i1;
				ans = pick[0][x][i]; ans.merge(pick[1][y][i1]);
			} else if (dp[0][x][i] + dp[1][y][i1] == mx) {
				if (i + i1 < cost) {
					cost = i + i1;
					ans = pick[0][x][i]; ans.merge(pick[1][y][i1]);
				} else if (i + i1 == cost) {
					Pick tmp = pick[0][x][i]; tmp.merge(pick[1][y][i1]);
					if (tmp < ans) { ans = tmp; }
				}
			}
		}
	}

	printf("%d %d\n", mx, cost);
	if (x + y > 0) {
		int cnt = 0;
		for (int i=1; i<=n; ++i) {
			if (ans.get(i)) {
				++cnt;
				printf(cnt == (x+y) ? "%d\n" : "%d ", i);
			}
		}
	}

	return 0;
}
