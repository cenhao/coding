/*
 * A very simple way is to enumerate a the possible range, and
 * count the number of days that has no submission. Which will cost
 * O(n^2).
 *
 * The approach I used is that I first try to expand the days as much
 * as possible, and shrink once I can't expand any more, this cost
 * O(n)
 */
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 100

bool empty[MAXN+1];
int n, m;

int process() {
	int rear = 1, head = 1;
	int remain = m;
	int mx = 0;

	while (head <= MAXN) {
		// expand
		for (; head<=MAXN; ++head) {
			if (empty[head]) {
				if (remain > 0) {
					--remain;
				} else {
					break;
				}
			}
		}

		mx = max(mx, head-rear);

		// shrink
		for (; rear<=MAXN; ++rear) {
			if (empty[rear]) {
				++rear;
				break;
			}
		}

		remain = min(remain+1, m);
		head = max(head, rear);
	}

	return mx;
}

int main() {
	int t;
	for (scanf("%d", &t); t>0; --t) {
		scanf("%d%d", &n, &m);
		memset(empty, 0, sizeof(empty));
		int tmp;
		for (int i=0; i<n; ++i) {
			scanf("%d", &tmp);
			empty[tmp] = true;
		}
		printf("%d\n", process());
	}

	return 0;
}
