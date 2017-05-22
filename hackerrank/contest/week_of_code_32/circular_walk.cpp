#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000000

int r[MAXN];

int main() {
	int n, s, t; scanf("%d %d %d", &n, &s, &t);
	int g, seed, p; scanf("%d %d %d %d", &r[0], &g, &seed, &p);

	for (int i=1; i<n; ++i) { r[i] = (r[i-1] * g + seed) % p; }
	int cnt = 0;
	int curl = s, curr = s;
	int nxtl = s, nxtr = s;
	bool found = false;

	while (curl>=nxtl || curr<=nxtr) {
		int mx = nxtr, mn = nxtl;
		for (int i=curl; i>=nxtl; --i) {
			int idx = (i+n) % n;
			if (idx == t) {
				found = true;
				break;
			}

			mn = min(i-r[idx], mn);
			mx = max(i+r[idx], mx);
		}

		if (found) { break; }

		for (int i=curr; i<=nxtr; ++i) {
			int idx = i % n;
			if (idx == t) {
				found = true;
				break;
			}

			mn = min(i-r[idx], mn);
			mx = max(i+r[idx], mx);
		}

		if (found) { break; }

		curl = nxtl-1; curr = nxtr + 1;
		nxtl = mn; nxtr = mx;

		++cnt;
	}

	printf("%d\n", found ? cnt : -1);
	return 0;
}
