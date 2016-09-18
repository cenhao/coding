/*
 * hihocoder 1053 - binary search
 * Use binary search to find an upper limit, then test if this
 * limit is feasible.
 * The biggest problem is how to efficently test if an upper limit
 * is feasible.
 * After sorting the stations according to their location.
 * 1. if stations before it still have space, try move population
 * in current station to the previous stations, so the the current
 * one will have more space to accommodate latter stations.
 * 2. if stations before it have already exceeded the limit, move 
 * their population to current station, but the maximum population
 * move to this station cannot exceed the upper limit. There're two
 * reasons:
 * 	a. move population from previous ones to current one, because the
 * 	current has more chance to move to latter ones.
 * 	b. keep it below upper limit, that we don't move those from the
 * 	previous one anymore, as we will adjust population in the current
 * 	station. The population from previous stations will have less
 * 	chance to find a new station, and if we exceed the current limit,
 * 	it will have to move to latter stations as well, those two are the
 * 	same:
 * 	s1 = 10, s2 = 0, s3 = 0, limit = 3
 * 	plan 1, s1 -> s2 = 10, s2 -> s3 = 7;
 * 	plan 2, s1 -> s2 = 3, s1 -> s3 = 7;
 * If population from previous station and current station exceeded
 * limit, than we need to record the # of exceeded; if not, we increase
 * the population in the current station, and keep its remaining space
 * for future migration.
 */
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100000
#define INF 1000000000

int _;
int n, r;

struct Station {
	int cnt;
	int pos;
} s[MAXN], ts[MAXN];
int exceed[MAXN];

bool cmp(const Station& s1, const Station& s2) {
	return (s1.pos != s2.pos) ?
		s1.pos < s2.pos : s1.cnt < s2.cnt;
}

bool possible(int mx) {
	memcpy(ts, s, sizeof(Station)*n);
	memset(exceed, 0, sizeof(int)*n);

	int first = 0;
	for (int i=0; i<n; ++i) {
		while (first < i && abs(ts[first].pos - ts[i].pos) > r) {
			if (exceed[first] > 0) { return false; }
			++first;
		}
		int take = 0;
		while (first < i) {
			if (exceed[first] == 0) { // there's still space
				int move = min(ts[i].cnt, mx-ts[first].cnt);
				ts[first].cnt += move;
				ts[i].cnt -= move;
				if (ts[first].cnt >= mx) { ++first; }
				if (ts[i].cnt == 0) { break; }
			} else {
				int move = min(mx-take, exceed[first]);
				exceed[first] -= move;
				take += move;
				if (exceed[first] <= 0) { ++first; }
				if (take == mx) { break; }
			}
		}

		exceed[i] = max(0, take+ts[i].cnt-mx);
		ts[i].cnt += take; // This is important
		// If population from previous station and current one
		// together does not exceed the limit, the current "absorb"
		// the immigrated population as its own, so that later on
		// we can calculate the space correctly.
	}

	for (; first<n; ++first) {
		if (exceed[first] > 0) { return false; }
	}

	return true;
}

int process() {
	int l = 0, r = INF, m; 
	while (l <= r) {
		m = (l + r) >> 1;
		if (possible(m)) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	return l;
}

int main() {
	for (scanf("%d", &_); _>0; --_) {
		scanf("%d %d", &n, &r);
		for (int i=0; i<n; ++i) { scanf("%d %d", &s[i].pos, &s[i].cnt); }
		sort(s, s+n, cmp);
		printf("%d\n", process());
	}

	return 0;
}
