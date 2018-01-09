/**
 * First think about instead of reversing the entire segment,
 * swapping the two ends of the segment, since reversing the
 * segment is equivalent to swapping every pairs in the segment.
 *
 * So if two elements are swapped, how is the # of reverse pairs
 * changing? Is it changing to odd or even.
 *
 * Let's consider the segment, {h, a_1, a_2, ..., a_n, r}
 * the # of reverse pairs can be calculated by:
 * 1. external pairs: at least one of the element of the pair is
 * out side of the segment, call it Ecnt.
 * 2. internal pairs: both elements are either {a_1, a_2, ..., a_n}.
 * call it Icnt.
 * 3. pairs with h as the left, call it Hcnt.
 * 4. pairs with r as the right, call it Rcnt.
 * 5. if h > r, add extra 1
 *
 * If h and r is swapped, Ecnt and Icnt will not change.
 *
 * Let's say in {a_1, ..., a_n}, number of a < h is X == Hcnt
 * number of a > r is Y == Rcnt
 *
 * After swapping, Hcnt == n - X, Rcnt == n - Y
 * If h > r, add -1, or add 1 for h < r
 *
 * Then before swapping, the # is Ecnt + Icnt + X + Y
 * After, the # is Ecnt + Icnt + 2*n - (X+Y) +/- 1
 *
 * Substracting after with before, we have:
 * 2*n - 2*(X+Y) +/- 1 == 2*(n-X-Y) +/- 1
 *
 * So the change in # is an odd number, as a result, after swapping,
 * the # will change from even to odd or odd to even accordingly.
 *
 * We can then calculate the change in # for reversing the segment
 * by simply counting the # of "real" pairs in the segment.
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1500
int a[MAXN], b[MAXN];

int merge_cnt(int n) {
	int cnt = 0;
	for (int i=0; (1<<i)<=n; ++i) {
		int len = 1 << i;
		for (int j=0; j+len<=n; j+=2*len) {
			int li = 0, ri = 0, rlen = min(n, j+2*len) - j-len;
			while (li < len && ri < rlen) {
				if (a[j+li] <= a[j+len+ri]) {
					b[j+li+ri] = a[j+li];
					++li;
				} else {
					b[j+li+ri] = a[j+len+ri];
					++ri;
					cnt += len - li;
				}
			}

			while (li < len) { b[j+li+ri] = a[j+li++]; }
			while (ri < rlen) { b[j+li+ri] = a[j+len+ri++]; }
			for (int k=0; k<len+rlen; ++k) { a[j+k] = b[j+k]; }
		}
	}

	return cnt;
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }
	int rcnt = merge_cnt(n);
	bool even = (rcnt & 1) == 0;
	int m; scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		int pcnt = (r-l+1) / 2;
		if (pcnt & 1) { even = !even; }
		printf(even ? "even\n" : "odd\n");
	}

	return 0;
}
