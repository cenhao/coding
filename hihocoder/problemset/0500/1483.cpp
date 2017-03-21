/*
 * Let's explain things one by one:
 * 1. given a interval of the array, a[l, r], if there're N value v,
 *    those v's can contribute 0 + 1 + ... + (n-1) pairs. or (N-1)*N/2 pairs.
 * 2. given a[l, r], the value of this interval is the sum of # of pairs for
 *    each value. And for all sub intervals with r as the end, i.e. a[l', r],
 *    where l' >= l, their value will be no more than a[l, r]'s.
 * 3. at position i, if the # of a[i] in sub interval a[0, i] is k_i, then for
 *    a[l, r], the # of a[r] is k_r - k_(l-1)
 * 4. the solution is to binary search the possible value, in the search, add
 *    all count of sub interval with value no more than the search value. And
 *    use the double pointers approach the extend or shrink to calculate the
 *    number
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int a[MAXN], cnt[MAXN], nxt;
unordered_map<int, int> ahash(MAXN);

bool no_less(int64_t v, int n, int k) {
	memset(cnt, 0, sizeof(cnt));
	int64_t sum = 0, head = 0, num = 0;
	for (int i=0; i<n; ++i) { // extend
		sum += cnt[ahash[a[i]]]++;
		while (sum > v) { // shrink
			sum -= --cnt[ahash[a[head++]]];
		}

		num += i - head + 1;
		if (num >= k) { return true; }
	}

	return num >= k;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, k; scanf("%d %d", &n, &k);
		nxt = 0;
		ahash.clear();
		for (int i=0; i<n; ++i) {
			scanf("%d", &a[i]);
			auto it = ahash.find(a[i]);
			if (it == ahash.end()) { ahash.insert(pair<int, int>(a[i], nxt++)); }
		}

		int64_t l = 0, r = int64_t(n)*(n-1)/2, m;
		while (l <= r) {
			m = (l + r) >> 1;
			if (no_less(m, n, k)) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		printf("%" PRId64 "\n", l);
	}

	return 0;
}
