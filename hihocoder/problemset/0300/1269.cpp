#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <queue>
using namespace std;

#define MAXN 100000
int p[MAXN];

bool possible(int n, int sz, int64_t q) {
	priority_queue<int> pq;
	int64_t sum = 0;
	for (int i=0; i<sz; ++i) { pq.push(p[i]); }
	for (int i=0; i<n; ++i) {
		sum += pq.top() * (i+1);
		pq.pop();
		if (i+sz < n) { pq.push(p[i+sz]); }
	}

	return sum <= q;
}

int binary_search(int n, int64_t q) {
	int l = 1, r = n, m;

	while (l <= r) {
		m = (l + r) / 2;
		if (possible(n, m, q)) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	return l;
}

int main() {
	int n; int64_t q; scanf("%d %" SCNd64 "", &n, &q);
	for (int i=0; i<n; ++i) { scanf("%d", &p[i]); }
	int ans = binary_search(n, q);
	printf("%d\n", (ans > n) ? -1 : ans);
	return 0;
}
