#include <algorithm>
#include <cstdint>
#include <cstdio>
using namespace std;

#define MAXN 100000

int64_t asum[MAXN];

int main() {
	int G; scanf("%d", &G);
	for (int g=0; g<G; ++g) {
		int n, m, x; scanf("%d %d %d", &n, &m, &x);
		int64_t sum = 0;
		int mx = 0;
		for (int i=0; i<n; ++i) {
			int v; scanf("%d", &v);
			sum += v;
			asum[i] = sum;
			if (sum <= x) { mx = i + 1; }
		}

		sum = 0;
		for (int i=0; i<m; ++i) {
			int v; scanf("%d", &v);
			sum += v;
			if (sum > x) { continue; }

			int l = 0, r = n-1, mid;
			int target = x - sum;
			while (l <= r) {
				mid = (l + r) >> 1;
				if (asum[mid] <= target) {
					l = mid+1;
				} else {
					r = mid-1;
				}
			}

			mx = max(mx, r+1 + i+1);
		}

		printf("%d\n", mx);
	}
	return 0;
}
