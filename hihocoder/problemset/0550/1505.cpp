#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int coin[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &coin[i]); }
	unordered_map<int, int> hm;
	unordered_map<int, int> cnt;
	for (int i=0; i<n; ++i) {
		++cnt[coin[i]];
		for (int j=i+1; j<n; ++j) {
			++hm[coin[i]+coin[j]];
		}
	}

	int64_t ans = 0;
	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			int v = coin[i] + coin[j];
			int c = cnt[coin[i]] + cnt[coin[j]] - 1;
			if (coin[i] == coin[j]) { c -= 2; }
			ans += hm[v] - c;
		}
	}

	printf("%" PRId64 "\n", ans);
	return 0;
}
