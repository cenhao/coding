#include <bits/stdc++.h>
using namespace std;

int ccnt[10];

struct State {
	int fcard[4];
	int acard[3];
} last[10];

int animals[3];
int fruits[4];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	char buff[16];

	memset(animals, 0, sizeof(animals));
	memset(fruits, 0, sizeof(fruits));
	memset(last, 0, sizeof(last));
	for (int i=0; i<n; ++i) { ccnt[i] = 10000000; }
	for (int i=0, cur=0, cnt=0; i<k; ++i) {
		scanf("%s", buff);
		if (buff[0] == 'R') {
			int who; scanf("%d", &who);
			bool win = false;
			int fcnt = 0;
			for (int j=0; j<4; ++j) {
				fcnt += fruits[j];
				if (fruits[j] == 5) { win = true; }
			}

			if (!win && fcnt > 0) {
				if ((animals[0] > 0 && fruits[3] == 0) ||
					(animals[1] > 0 && fruits[1] == 0) ||
					(animals[2] > 0)) {
					win = true;
				}
			}

			if (win) {
				ccnt[who] += cnt;
				memset(last, 0, sizeof(last));
				memset(animals, 0, sizeof(animals));
				memset(fruits, 0, sizeof(fruits));
				cnt = 0;
			} else {
				for (int j=0; j<n; ++j) { if (j != who) { ++ccnt[j]; } }
				ccnt[who] -= n-1;
			}

			cur = who;
			continue;
		}

		for (int j=0; j<4; ++j) {
			fruits[j] -= last[cur].fcard[j];
			last[cur].fcard[j] = 0;
		}
		for (int j=0; j<3; ++j) {
			animals[j] -= last[cur].acard[j];
			last[cur].acard[j] = 0;
		}
		if (buff[0] == 'F') {
			int fn; scanf("%d", &fn);
			for (int j=0; j<fn; ++j) {
				int f; scanf("%d", &f);
				++last[cur].fcard[f];
				++fruits[f];
			}
		} else {
			int at; scanf("%d", &at);
			++last[cur].acard[at];
			++animals[at];
		}

		--ccnt[cur];
		++cnt;
		cur = (cur + 1) % n;
	}

	for (int i=0; i<n; ++i) {
		printf("%d\n", ccnt[i]);
	}

	return 0;
}
