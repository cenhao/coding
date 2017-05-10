/*
 * Given a string of parentheses, find the minimum number
 * of parenthesis to insert to make the string complete,
 * and find how many different solutions are there.
 *
 * First, consider the simplified version where only the left
 * parenthesis is need like `())`.
 *
 * For each `)`, a number can be defined as "the minimum `(`
 * is needed to be inserted to make the string complete".
 * For example: `())` we have [x, 0, 1], where for the first `)`,
 * it's already complete with the `(` right before it.
 * And another `(` is needed for the second `)`.
 *
 * For `)))` the numbers will be [1, 2, 3]
 *
 * For each `)`, an array, called it `dp`, can be defined as:
 * dp[i] is # of different ways of inserting `(`s right before
 * the current `)` (not necessarily right before the current one).
 * Then dp[i] = sum(pdp[0..i]), here pdp is the dp array for the
 * previous `)`.
 *
 * Then the # of solution will be the dp[minimum `)` to insert for last `)']
 *
 * For strings that requires inserting `)`, we can mirror the string
 * then perform the same algorithm mentioned above.
 *
 * Finally, for general cases, we can always find a right posistion
 * to split the string into 2, where the left one requires only inserting `(`,
 * and the right one only requires inserting `)`
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
#define MOD 1000000007

char str[MAXN+1];
int64_t dp[2][MAXN+1];

void mirror(int start, int end) {
	int len = end - start + 1;
	for (int i=len/2-1; i>=0; --i) {
		swap(str[start+i], str[end-i]);
	}

	for (int i=start; i<=end; ++i) {
		str[i] = (str[i] == '(') ? ')' : '(';
	}
}

int64_t process(int start, int end, int *add /* out */) {
	int len = end - start + 1;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	int lcnt = 0, rcnt = 0;
	for (int i=1; i<=len; ++i) {
		int cur = i & 1, pre = (i&1) ^ 1;
		if (str[i+start-1] == '(') {
			++lcnt;
			memcpy(dp[cur], dp[pre], sizeof(int64_t)*(len+1));
		} else {
			if (lcnt > 0) {
				--lcnt;
			} else {
				++rcnt;
			}
			int64_t sum = 0;
			for (int j=0; j<rcnt; ++j) {
				dp[cur][j] = 0;
				sum = (sum + dp[pre][j]) % MOD;
			}

			for (int j=rcnt; j<=len; ++j) {
				dp[cur][j] = sum = (sum + dp[pre][j]) % MOD;
			}
		}
	}

	*add = rcnt;
	return dp[len&1][rcnt];
}

int main() {
	scanf("%s", str);
	int len = strlen(str);

	int pos = -1, cnt = 0;
	for (int i=0; i<len; ++i) {
		if (str[i] == ')') {
			--cnt;
			if (cnt < 0) {
				pos = i; cnt = 0;
			}
		} else {
			++cnt;
		}
	}

	int ladd, radd;
	int64_t l = process(0, pos, &ladd);
	mirror(pos+1, len-1);
	int64_t r = process(pos+1, len-1, &radd);
	int64_t ans = (l * r) % MOD;

	printf("%d %" PRId64 "\n", ladd+radd, ans);
	return 0;
}
