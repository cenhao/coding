#include <algorithm>
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 2000
#define MOD 1000000007

int umbrellas[MAXN];
int eranges[MAXN*2 + 1];

int64_t calc_inverse(int64_t x) {
	int pw = MOD - 2;
	int64_t ret = 1LL;
	int64_t base = x;

	while (pw > 0) {
		if (pw & 1) {
			ret = (ret * base) % MOD;
		}

		base = (base * base) % MOD;
		pw >>= 1;
	}

	return ret;
}

int64_t calc_combination(int k, int n) {
	int tmp = n - k;
	int upper = max(tmp, k);
	int lower = min(tmp, k);

	int64_t dom = 1LL;
	for (int i=upper+1; i<=n; ++i) { dom = (dom * i) % MOD; }

	int64_t div = 1LL;
	for (int i=2; i<=lower; ++i) { div = (div * i) % MOD; }
	int64_t mul = calc_inverse(div);

	return (dom * mul) % MOD;
}

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int n, m; scanf("%d %d", &n, &m);
		int sum = 0, mx = -1;
		for (int i=0; i<n; ++i) {
			scanf("%d", &umbrellas[i]);
			sum += umbrellas[i] << 1;
			mx = max(umbrellas[i], mx);
		}

		int64_t ans = 0;
		if (n > 1) {
			memset(eranges, 0, sizeof(eranges));
			for (int i=0; i<n; ++i) {
				for (int j=0; j<n; ++j) {
					if (i == j) { continue; }
					++eranges[umbrellas[i] + umbrellas[j]];
				}
			}

			int64_t n_2_factorial = 1;
			for (int i=n-2; i>1; --i) { n_2_factorial = (n_2_factorial * i) % MOD; }

			for (int i=mx*2; i>0; --i) {
				if (eranges[i] <= 0) { continue; }
				if (i+m-1 < sum) { break; }

				int64_t tmp = (n_2_factorial * eranges[i]) % MOD;
				tmp = (tmp * calc_combination(n, i+m-sum+n-1)) % MOD;

				ans = (ans + tmp) % MOD;
			}
		} else {
			ans = m;
		}

		printf("Case #%d: %" PRId64 "\n", t, ans);
	}

	return 0;
}
