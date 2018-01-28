#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int calc(int64_t k, int64_t n) {
	int64_t ret = 0;
	int64_t sum = 0;
	int64_t last = 0;
	for (int64_t i=1; i*k/k==i && i<=n; ++i) {
		int64_t tmp = ((i-last)*sum) % MOD;
		ret = (ret + tmp) % MOD;
		last = i;
		sum = (sum + i) % MOD;
		i *= k;
	}

	int64_t tmp = ((n-last+1)*sum) % MOD;
	ret = (ret + tmp) % MOD;
	return ret;
}

int simplestSum(int64_t k, int64_t a, int64_t b) {
	int asum = calc(k, a-1);
	int bsum = calc(k, b);
	bsum = (bsum - asum < 0) ? bsum-asum+MOD : bsum-asum;
	return bsum;
}

int main() {
	int q; scanf("%d", &q);
	for(int i=0; i<q; ++i){
		int64_t k, a, b; scanf("%" SCNd64 "%" SCNd64 "%" SCNd64"", &k, &a, &b);
		int result = simplestSum(k, a, b);
		printf("%d\n", result);
	}
	return 0;
}


