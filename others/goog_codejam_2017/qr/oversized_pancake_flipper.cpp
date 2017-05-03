/*
 * Offical Editorial:
 * Let's start with two simple but key observations. First, the flips are
 * commutative. That is, the order in which you make the flips doesn't
 * matter: flipping at the same positions in any order always yields the
 * same result. Second, you never need to flip at the same position more than
 * once: since flips are commutative, you may rearrange the flips so that two
 * flips at the same position happen consecutively, and then it is clear that
 * they cancel each other out and you might as well not do either.
 *
 * Of course, the approach above will take way too long for the Large dataset,
 * which can have up to 1000 pancakes. There is a simple greedy strategy that
 * is not too hard to find. Notice that the left-most pancake p1 is only
 * affected by the left-most flip f1. That means that the initial status of p1
 * completely determines what do we need to do with f1 if we want to have any
 * chance of leaving all pancakes happy side up: use f1 if and only if p1 is
 * initially blank side up. After deciding on f1, we can notice that there is
 * only one remaining flip f2 that affects the second to the left pancake p2.
 * So, after we have used f1 (or not), the current state of p2 completely
 * determines whether to use f2.
 *
 * Continuing with this reasoning, we can use the leftmost N-K+1 pancakes to
 * determine all flips. After doing that, we only need to check whether the
 * last K-1 pancakes are happy side up or not. If they all are, then the
 * answer is the number of flips we used. Otherwise, the answer is IMPOSSIBLE.
 * Notice that this reasoning also implies that at most one of the subsets of
 * flips from our Small-only solution above would have worked.
 *
 * If we carry out the above strategy literally and actually flip all of the
 * pancakes in memory each time, the complexity is O(N2). We can reduce this
 * to O(N) by only flipping one pancake at a time, and keeping a running count
 * of the number of flips that we "owe" the current pancake. For instance,
 * suppose that N = 10 and K = 5, and the first pancake is blank side up. We
 * start with the first pancake, and because we must flip it, we know we must
 * flip the first five pancakes. We increase our flip count to 1, and also make
 * a memo to decrease the flip count by 1 once we reach the sixth pancake. We
 * continue from left to right, and whenever a pancake is blank side up and
 * the flip count is even, or a pancake is happy side up and the flip count is
 * odd, we increase the flip count and make another memo. These memos can be
 * easily stored in another array of length N that is checked before handling
 * each pancake. This optimization is not necessary to solve the Large dataset,
 * but it is a useful trick in programming contest problems (and at least one
 * of your Code Jam engineers has used it in day-to-day software engineering
 * work!)
 */

#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

char pcs[MAXN+1];
bool exit_mark[MAXN];

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int s; scanf("%s %d", pcs, &s);
		int len = strlen(pcs);
		memset(exit_mark, false, sizeof(exit_mark));
		int cnt = 0, ans = 0;

		for (int i=0; i<len; ++i) {
			int v = (((pcs[i] == '-') ? 0 : 1) + cnt) & 1;

			if (i <= len-s && v == 0) {
				++ans;
				++cnt;
				exit_mark[i+s-1] = true;
			} else if (v == 0) {
				ans = -1;
			}

			if (exit_mark[i]) { --cnt; }
		}

		printf("Case #%d: ", t);
		if (ans == -1) {
			printf("IMPOSSIBLE\n");
		} else {
			printf("%d\n", ans);
		}
	}

	return 0;
}
