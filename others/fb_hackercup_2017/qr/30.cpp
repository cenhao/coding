#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std;

#define MAXN 100

int w[MAXN];

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int n; scanf("%d", &n);
		for (int i=0; i<n; ++i) { scanf("%d", &w[i]); }
		sort(w, w+n, greater<int>());
		int used = 0, mx = 0;
		for (int i=0; i<n-used; ++i) {
			int need = 50/w[i] + ((50 % w[i] == 0) ? 0 : 1) - 1;
			if (need > n-used-i-1) { break; }
			used += need;
			++mx;
		}

		printf("Case #%d: %d\n", t, mx);
	}

	return 0;
}
