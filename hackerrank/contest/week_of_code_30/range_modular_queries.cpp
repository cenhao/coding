/*
 * ##First
 * Keep a vector corresponding to positions of each element.
 * Now we can answer how many instances of an element occur
 * in a range by binary search. So, we iterate through all
 * k * x + y <= MAXN
 * and find their frequency in [l, r].
 * Obviously, this is fast enough for large x and very slow
 * for small x. For instance for 3 we have to do about 40000/3
 * binary searches.
 * ##Second
 * Compute whole array modulo x for each x. Then using the
 * method described above, we can find frequency of in range [l, r].
 * Obviously, we cannot do this for all  as it would consume too much time and memory.
 * ##Final
 * Note that our first approach was slow for small x and our
 * second approach only if we have small amount of different x
 * in our queries. So, if our x is larger than a threshold,
 * use second method, and for bigger x is use first method.
 * Let the threshold be K. Then, we need n*K precomputation
 * for second method and it answers queries in O(logn).
 * For first method, we need O(n/k*log(n) per query. It's
 * easy to see that if we put K=sqrt(MAXN), we will need about
 * n*200 steps for precomputation and we answer query in
 * O(200*logn) at max. which suffices.
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 40000
#define SQRT_MAXN 200

int main() {
	int n, q; scanf("%d %d", &n, &q);
	vector<vector<int>> pos(MAXN+1, vector<int>());
	vector<int> cnt[SQRT_MAXN+1][SQRT_MAXN];
	int mx = -1;

	for (int i=0; i<n; ++i) {
		int v; scanf("%d", &v);
		pos[v].push_back(i);
		for (int j=1; j<=SQRT_MAXN; ++j) { cnt[j][v%j].push_back(i); }
		mx = max(mx, v);
	}

	for (int i=0; i<q; ++i) {
		int l, r, x, y; scanf("%d %d %d %d", &l, &r, &x, &y);
		int ans = 0;
		if (x > SQRT_MAXN) {
			for (int j=y; j<=mx; j+=x) {
				auto lb = lower_bound(pos[j].begin(), pos[j].end(), l);
				auto ub = upper_bound(pos[j].begin(), pos[j].end(), r);
				ans += distance(lb, ub);
			}
		} else {
			auto lb = lower_bound(cnt[x][y].begin(), cnt[x][y].end(), l);
			auto ub = upper_bound(cnt[x][y].begin(), cnt[x][y].end(), r);
			ans = distance(lb, ub);
		}

		printf("%d\n", ans);
	}

	return 0;
}
