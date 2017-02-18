#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1200
#define MOD 1000000007

int M[MAXN];
int64_t dp[MAXN+1][MAXN+1];
int64_t fact[MAXN+1];
int64_t combination[MAXN+1][MAXN+1];

void calc_factorial() {
	int64_t v = 1LL;
	fact[0] = 1;
	for (int i=1; i<=MAXN; ++i) { fact[i] = v = (v * i) % MOD; }
}

int64_t calc_combination(int n, int m) {
	if (combination[n][m] >= 0) { return combination[n][m]; }
	if (n < m) { return 0; }
	if (m == 0) {
		combination[n][m] = 1LL;
	} else {
		combination[n][m] =
			(calc_combination(n-1, m-1) + calc_combination(n-1, m)) % MOD;
	}

	return combination[n][m];
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &M[i]); }
	memset(dp, 0, sizeof(dp));
	memset(combination, -1, sizeof(combination));
	calc_factorial();
	dp[n][0] = 1;

	for (int i=n-1; i>=0; --i) {
		int mx = 0, last = -1;
		for (int j=i; j<n; ++j) {
			if (M[j] <= last) { break; }
			last = M[j];
			++mx;
		}

		for (int j=1; j<=mx; ++j) {
			for (int k=0; k<=j; ++k) {
				int64_t c = calc_combination(j, k);
				int64_t tmp = (((fact[k]*c) % MOD)*dp[i+j][k]) % MOD;
				dp[i][j] = (dp[i][j] + tmp) % MOD;
			}
		}
	}

	int64_t ans = 0LL;
	for (int i=1; i<=n; ++i) { ans = (ans + dp[0][i]) % MOD; }
	printf("%" PRId64 "\n", ans);
	return 0;
}
