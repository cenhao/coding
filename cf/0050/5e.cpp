/*
 * First think about how to the number of hills of one hill can see.
 * Go from one direction, say to the right, scan every hill.
 * If the hill is higher than the current one, stop.
 *
 * during scanning, record the max hight of the hills scanned, when
 * a new hill is scanned, if it's lower than the maximum, then it can't
 * be seen.
 *
 * Scan both direction, and use inclusion-exclusion principle to calculate
 * the answer.
 *
 * Do this for every hill, sum them together and devide the answer by 2
 * (all the pairs are calculate twice).
 *
 * However this will be O(N^2)
 *
 * Here a stack can be used to optimize the calculation.
 * Start from the first highest hill, put it into the stack, and scan the rest
 * from one direction.
 *
 * If a hill is lower than the top of the stack, meaning it can see the top of 
 * the stack, push it into the stack.
 *
 * If a hill is higher than the top of the stack, meaning it can not only see
 * the top of the stack, it can see the the hill(s) under the top. But the top
 * can no longer see any hill after the current hill.
 *
 * So start poping out hills lower than the current one. for each hill that
 * get pop, add a pair. Finally, push the current hill into the stack.
 *
 * The scan will circle back to the head of the array, all the way to first
 * highest hill. For the first highest hill, there will be some overlap,
 * use the algorithm before the optimization to calculate the overlapped,
 * subtract it from the answer.
 *
 * Also we need some extra handling for hills with same hight.
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000

int h[MAXN];
int cnt[MAXN];

struct Item {
	int val, cnt;
};

int main() {
	int mx = -1, pos;
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &h[i]);
		if (h[i] > mx) {
			mx = h[i];
			pos = i;
		}
	}

	Item item = { h[pos], 1 };
	stack<Item> st;
	st.push(item);

	int64_t ans = 0;
	for (int i=1; i<=n; ++i) {
		int ii = (pos+i) % n;
		int ecnt = 1;
		while (!st.empty() && h[ii] >= st.top().val) {
			ans += st.top().cnt;
			if (h[ii] == st.top().val) { ecnt += st.top().cnt; } // same hight
			st.pop();
		}

		if (!st.empty()) { ++ans; } // If the hill is as high as the hightest one, the stack will be popped empty
		item.val = h[ii]; item.cnt = ecnt;
		st.push(item);
	}

	// calculate the overlapp
	memset(cnt, 0, sizeof(cnt));
	mx = 0;
	for (int i=1; i<=n; ++i) {
		int ii = (pos+i) % n;
		if (h[ii] >= mx) {
			mx = h[ii];
			++cnt[ii];
		}
	}

	mx = 0;
	int sub = 0;
	for (int i=1; i<=n; ++i) {
		int ii = (pos+n-i) % n;
		if (h[ii] >= mx) {
			mx = h[ii];
			++cnt[ii];

			if (cnt[ii] > 1) { ++sub; }
		}
	}

	ans -= sub;

	printf("%" PRId64 "\n", ans);
	return 0;
}
