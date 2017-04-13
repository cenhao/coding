/*
 * Scan the patter from left to the right.
 * If found a '?', then read in its costs. And this point,
 * pick the close parenthesis. Also, put the gain of changing the 
 * right parenthesis to left parenthesis to a priority queue.
 *
 * For each character scanned, check if there're more left parenthesis
 * than right parenthesis. It can be proved that, if scanned from the
 * left to right, for each position, it should have # of left
 * parenthesis than right, otherwise the pattern won't be valid.
 *
 * If #left < #right, than pick the one with maximum gain of changing
 * in the priority queue, and replace that position with left.
 * With this approach, it can be guarenteed that it's the minimum cost.
 *
 * At the end, #left should be equal to #right
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXL 50000

struct Cost {
	int diff;
	int pos;
	bool operator < (const Cost& c) const {
		return diff < c.diff;
	}
};

char pattern[MAXL+1];

int main() {
	scanf("%s", pattern);
	int len = strlen(pattern);
	int lcnt = 0, rcnt = 0;
	int64_t sum = 0;
	bool stop = false;
	priority_queue<Cost> pq;
	for (int i=0; i<len && !stop; ++i) {
		if (pattern[i] == '(') {
			++lcnt;
		} else if (pattern[i] == ')') {
			++rcnt;
		} else {
			pattern[i] = ')';
			int lc, rc; scanf("%d %d", &lc, &rc);
			++rcnt;
			sum += rc;
			Cost tmp = { rc - lc, i };
			pq.push(tmp);
		}

		while (lcnt < rcnt) {
			if (pq.empty()) {
				stop = true;
				break;
			}

			Cost tmp = pq.top(); pq.pop();
			sum -= tmp.diff;
			pattern[tmp.pos] = '(';
			++lcnt; --rcnt;
		}
	}

	if (stop || lcnt > rcnt) {
		printf("-1\n");
	} else {
		printf("%" PRId64 "\n%s\n", sum, pattern);
	}

	return 0;
}
