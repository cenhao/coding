/*
 * Offline algorithm for binary indexed tree.
 * The indexes are the time cost for every student.
 * Let's say at the beginning we have no student, and
 * we add in the first one. So then the total time is
 * itself.
 *
 * Then we add the second one, if the time for the second
 * student is longer than the first one, then the time
 * for the second student is t1 + t2.
 *
 * If the time is smaller than the first one, the time for
 * the student is t2, but first student becomes t1+t2.
 *
 * So the rule is simple, we slowly expand the interval,
 * for a newly added student, he has to wait for all students
 * that are faster, and all student slower has to wait for him.
 *
 * so himself is sum(smaller), and all slower student number * t.
 *
 * The inverse approach can be applied if we shrink.
 *
 * However, the expanding and shrinking can take a lot of time if
 * the interval expand too much or shrink too much very often, then
 * the way to avoid this is the partition the intervals, so that
 * within the interval, we only shrinks at the beginning,
 * and expand slowly as needed.
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 20000
#define LOWBIT(x) (x & (~(x-1)))

int t[MAXN+1], mxt;
int64_t cnt_bits[MAXN+1];
int64_t sum_bits[MAXN+1];
int64_t ans[MAXN+1];

struct Query { int l, r, id; } q[MAXN+1];

void add(int idx, int v, int64_t *arr, int end) {
	while (idx <= end) {
		arr[idx] += v;
		idx += LOWBIT(idx);
	}
}

int query(int idx, int64_t *arr) {
	int64_t sum = 0;
	while (idx > 0) {
		sum += arr[idx];
		idx -= LOWBIT(idx);
	}

	return sum;
}

void include(int idx, int64_t &sum) {
	add(t[idx], t[idx], sum_bits, mxt);
	add(t[idx], 1, cnt_bits, mxt);
	sum += query(t[idx], sum_bits) +
		(query(mxt, cnt_bits)-query(t[idx], cnt_bits))*t[idx];
}

void exclude(int idx, int64_t &sum) {
	sum -= query(t[idx], sum_bits) +
		(query(mxt, cnt_bits)-query(t[idx], cnt_bits))*t[idx];
	add(t[idx], -t[idx], sum_bits, mxt);
	add(t[idx], -1, cnt_bits, mxt);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d %d", &n, &m);
		memset(cnt_bits, 0, sizeof(cnt_bits));
		memset(sum_bits, 0, sizeof(sum_bits));

		mxt = -1;
		for (int i=1; i<=n; ++i) {
			scanf("%d", &t[i]);
			mxt = max(mxt, t[i]);
		}

		for (int i=0; i<m; ++i) {
			scanf("%d %d", &q[i].l, &q[i].r);
			q[i].id = i;
		}

		int pn = sqrt(m); // partitioner number

		sort(q, q+m, [pn](const Query &q1, const Query &q2) -> bool{
			return (q1.l / pn == q2.l / pn) ?
				((q1.r == q2.r) ? (q1.l < q2.l) : (q1.r < q2.r)) :
				(q1.l / pn < q2.l / pn);
		});

		int cl = 1, cr = 0;
		int64_t tmp = 0;
		for (int i=0; i<m; ++i) {
			while (cr < q[i].r) { include(++cr, tmp); }
			while (cr > q[i].r) { exclude(cr--, tmp); }
			while (cl < q[i].l) { exclude(cl++, tmp); }
			while (cl > q[i].l) { include(--cl, tmp); }

			ans[q[i].id] = tmp;
		}

		for (int i=0; i<m; ++i) { printf("%" PRId64 "\n", ans[i]); }
	}

	return 0;
}
