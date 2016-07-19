/*
ID: cenhao11
PROG: lamps
LANG: C++11
*/

/*
 * So the solution relies on the fact that press the same button even times will
 * have not effect, regradless of the order of pressing, i.e, press buttons 1, 2, 1
 * will be equal to only pressing 2. This is XOR operation.
 * With this in mind, if n % 2 == 0, we can always find a way make it the same as 
 * not pressing any button. So, if (n-k) % 2 == 0, only the last k actions will be
 * effective, and only all k actions are different from each other, they might have
 * a different outcome. So 0 <= k <= 4. (and pressing 1, 2, 3 is the same as not
 * pressing anything, but we can ignore that in this problem).
 * Once we know the possible k, we can enumerate all the combinations to get the
 * final state, and check with the constrain to see if a combination is possible.
 */

#include <stdio.h>
#include <string.h>

#include <set>
using namespace std;

#define MAXN 101

const int btn[4] = {
	077, // 1 1 1 1 1 1
	052, // 1 0 1 0 1 0
	025, // 0 1 0 1 0 1
	044  // 1 0 0 1 0 0
};

int on[MAXN];
int oncnt;
int off[MAXN];
int offcnt;

bool check(int mask) {
	for (int i=0; i<oncnt; ++i) {
		int pos = 5 - ((on[i]-1) % 6);
		if (!(mask & (1<<pos))) { return false; }
	}

	for (int i=0; i<offcnt; ++i) {
		int pos = 5 - ((off[i]-1) % 6);
		if (mask & (1<<pos)) { return false; }
	}

	return true;
}

void build(int depth, int start, int mask, set<int> &configs) {
	if (depth == 0) {
		if (check(mask)) { configs.insert(mask); }
	} else {
		for (int i=start; i<4; ++i) {
			build(depth-1, i+1, mask ^ btn[i], configs);
		}
	}
}

void process(int n, int c) {
	set<int> configs;
	for (int i=0; i<=4 && c>=i; ++i) {
		if ((c-i) % 2 == 0) {
			build(i, 0, 077, configs);
		}
	}

	for (auto it=configs.begin(); it!=configs.end(); ++it) {
		for (int i=0; i<n; ++i) {
			int pos = i%6;
			printf("%d", (*it&(1<<(5-pos))) ? 1 : 0);
		}

		printf("\n");
	}

	if (configs.size() <= 0) {
		printf("IMPOSSIBLE\n");
	}
}

int main() {
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);

	int n, c;
	memset(on, 0, sizeof(on));
	memset(off, 0, sizeof(off));

	scanf("%d %d", &n, &c);
	int pos;
	oncnt = offcnt = 0;
	do {
		scanf("%d", &pos);
		if (pos > 0) { on[oncnt++] = pos; }
	} while (pos > 0);
	do {
		scanf("%d", &pos);
		if (pos > 0) { off[offcnt++] = pos; }
	} while (pos > 0);

	process(n, c);
	return 0;
}
