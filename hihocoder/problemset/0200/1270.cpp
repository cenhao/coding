#include <algorithm>
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXM 100
#define MAXK 10000

int64_t A[MAXM], B[MAXM];
int64_t dp[MAXK+1];

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int n, m, K, t; scanf("%d %d %d %d", &n, &m, &K, &t);
		for (int i=0; i<m; ++i) { scanf("%" SCNd64 "", &A[i]); }
		for (int i=0; i<m; ++i) { scanf("%" SCNd64 "", &B[i]); }

		int64_t sum = 0;
		for (int i=0; i<n; ++i) {
			memset(dp, -1, sizeof(dp));
			dp[0] = 0;
			for (int j=0; j<m; ++j) {
				if (B[j] == 0) { continue; }
				for (int k=0; k<=K; ++k) {
					if (dp[k] == -1) { continue; }
					int pos = min((int64_t)K, k+B[j]);
					if (dp[pos] != -1) {
						dp[pos] = min(dp[pos], dp[k]+A[j]);
					} else {
						dp[pos] = dp[k]+A[j];
					}
				}
				B[j] /= t;
			}

			if (dp[K] == -1) {
				sum = -1;
				break;
			}
			sum += dp[K];
		}

		if (sum == -1) {
			printf("No Answer\n");
		} else {
			printf("%" PRId64 "\n", sum);
		}
	}

	return 0;
}
