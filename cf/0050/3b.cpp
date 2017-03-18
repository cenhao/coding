#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

struct Boat {
	int t, c, n; // type, capacity
} b[MAXN];

int t[2][MAXN];

int main() {
	int n, v; scanf("%d %d", &n, &v);
	for (int i=0; i<n; ++i) {
		scanf("%d %d", &b[i].t, &b[i].c);
		b[i].n = i + 1;
	}
	sort(b, b+n, [](const Boat &b1, const Boat &b2) -> bool {
		return double(b1.c)/b1.t > double(b2.c)/b2.t;
	});

	int cnt[3] = { 0, 0 };
	for (int i=0; i<n; ++i) { t[b[i].t-1][cnt[b[i].t-1]++] = i; }

	int idx = 0, sum = 0;
	int used[3] = { 0, 0 };
	while (v > 0 && idx < n) {
		if (v >= b[idx].t) {
			v -= b[idx].t;
			sum += b[idx].c;
			++used[b[idx].t-1];
		}

		++idx;
	}

	if (used[1] < cnt[1]) {
		if (v == 1 && used[0] > 0) {
			if (b[t[1][used[1]]].c > b[t[0][used[0]-1]].c) {
				sum -= b[t[0][used[0]-1]].c;
				sum += b[t[1][used[1]]].c;
				++used[1]; --used[0];
			}
		} else if (v == 0 && used[0] > 1) {
			if (b[t[1][used[1]]].c > b[t[0][used[0]-1]].c+b[t[0][used[0]-2]].c) {
				sum -= b[t[0][used[0]-1]].c + b[t[0][used[0]-2]].c;
				sum += b[t[1][used[1]]].c;
				++used[1]; used[0] -= 2;
			}
		}
	}

	printf("%d\n", sum);
	
	for (int i=0; i<used[0]; ++i) {
		printf("%d%c", b[t[0][i]].n, (i == used[0]-1) ? ((used[1] == 0) ? '\n' : ' ') : ' ');
	}

	for (int i=0; i<used[1]; ++i) {
		printf("%d%c", b[t[1][i]].n, (i == used[1]-1) ? '\n' : ' ');
	}

	return 0;
}
