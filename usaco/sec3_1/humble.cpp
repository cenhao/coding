/*
ID: cenhao11
LANG: C++11
PROG: humble
*/

/*
 * My original idea is to use an STL set.
 * At the beginning in the set there's only `1`, and every iteration I pop the
 * smallest value from the set and try to put all the possible combination of
 * it with all the given prime, i.e., for (i:0-k) set.push(top * p[i]).
 * So that the n+1-th value popped from the set is the answer, however I exceeded
 * the memory limit from this approach.
 * Then a optimization was added: limiting the size of the set. As the answer is the
 * n+1-th value of the set, so as we pop more and more value from the set, the size
 * should keep being decreased: when we take the first value (1), the size becomes
 * n, then we take the second value, the size become n-1, and so on.
 * When putting the combinations into the set, once the size exceeds the limit,
 * the combination is larger then the last value of the set, the iteration is stopped.
 * After each iteration, I also clear out the unnecessary values from the set to
 * maintain the size.
 * With this optimization, I passed.
 * The time complexity: for each pick it's O(logn), for each iteration we have
 * roughly k insert or delete, each cost O(logn), in total it's O(klogn).
 * So the overall complexity is O(nlogn + nklogn) => O(nklogn)
 *
 * But the official answer is simpler and faster with complexity O(nk), the idea
 * is given the first few humble numbers, we can generate the next humble number
 * from them: humble_x = min(h[0..x-1] * p[0..k-1]), and to make things faster,
 * it records the index of the last humber number used by p[i], as p[i]*h[x] > p[i]*h[x-1],
 * if p[i]*h[x] is in the humber array, then p[i]*h[x-1] must be in the array
 */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXK 100
#define MAXN 100000
#define INF 0x7fffffffffffff00LL

int prime[MAXK];
int64_t humble[MAXN+1];
int pidx[MAXK];

int main() {
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);

	int n, k;
	scanf("%d %d", &k, &n);
	for (int i=0; i<k; ++i) { scanf("%d", &prime[i]); }

	humble[0] = 1LL;
	int end = 0, start = 0;
	memset(pidx, 0, sizeof(pidx));

	while (end != n) {
		int64_t mn = INF;
		int64_t tmp;
		int pick;

		for (int i=0; i<k; ++i) {
			while ((tmp = prime[i] * humble[pidx[i]]) <= humble[end]) { ++pidx[i]; }
			if (tmp < mn) {
				mn = tmp;
				pick = i;
			}
		}

		humble[++end] = mn;
		++pidx[pick];
	}

	printf("%" PRId64 "\n", humble[n]);
	return 0;
}

/*
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <set>
using namespace std;

#define MAXK 100

int prime[MAXK];

int main() {
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);

	int n, k;
	scanf("%d %d", &k, &n);

	for (int i=0; i<k; ++i) {
		scanf("%d", &prime[i]);
	}

	set<int64_t> humble;
	humble.insert(1);
	int cnt = 0;
	int64_t val;

	while (cnt <= n) {
		val = *humble.begin();
		humble.erase(humble.begin());
		int limit = n - cnt;
		int last = -1;

		for (int i=0; i<k; ++i) {
			int64_t tmp = val * prime[i];
			if (last > 0 && tmp > last) { break; }
			if (tmp > 0) { humble.insert(tmp); }
			if (humble.size() > limit) {
				last = *humble.rbegin();
			}
		}

		auto it = humble.end();
		for (int i=humble.size()-limit; i>0; --i) { --it; }
		humble.erase(it, humble.end());

		++cnt;
	}

	printf("%" PRId64 "\n", val);
	return 0;
}
*/
