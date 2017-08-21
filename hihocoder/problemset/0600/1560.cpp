#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAXP 40

int64_t base[10][10];
int64_t val[10][10];
int64_t tmp[10][10];

// set val to current base
void set_val(int k) {
	int kk = min(9, k);
	for (int i=0; i<=kk; ++i) {
		for (int j=0; j<=kk; ++j) { val[i][j] = base[i][j]; }
	}
}

// initialize base
void init_base(int k) {
	memset(base, 0, sizeof(base));
	int kk = min(9, k);
	for (int i=0; i<=kk; ++i) { base[i][i] = 1; }
}

void mul(int k, int64_t (*a)[10], int64_t (*b)[10]) {
	memset(tmp, 0, sizeof(tmp));
	int kk = min(k, 9);
	for (int i=0; i<=kk; ++i) {
		for (int j=0; j<=kk; ++j) {
			if (a[i][j] <= 0) { continue; }
			for (int i1=0; i1<=kk && j*i1<=k; ++i1) {
				for (int j1=0; j1<=kk; ++j1) {
					tmp[i][j1] = (tmp[i][j1] + (a[i][j]*b[i1][j1])%MOD) % MOD;
				}
			}
		}
	}

	for (int i=0; i<=kk; ++i) {
		for (int j=0; j<=kk; ++j) { a[i][j] = tmp[i][j]; }
	}
}

int main() {
	int64_t n; int k; scanf("%" SCNd64 "%d", &n, &k);

	bool init = false;
	init_base(k);
	while (n > 0) {
		if (n & 1) {
			if (!init) {
				set_val(k);
				init = true;
			} else {
				mul(k, val, base);
			}
		}

		mul(k, base, base);
		n >>= 1;
	}

	int64_t ans = 0;
	for (int i=min(9, k); i>0; --i) {
		for (int j=min(9, k); j>=0; --j) {
			ans = (ans + val[i][j]) % MOD;
		}
	}

	printf("%" PRId64 "\n", ans);
	return 0;
}
