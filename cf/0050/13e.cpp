#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int p[MAXN+1], nxt[MAXN+1], cnt[MAXN+1];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) { scanf("%d", &p[i]); }

	int bs = sqrt(n);
	for (int i=n-1; i>=0; --i) {
		int bi = i / bs, nstep = min(n, i+p[i]);
		if (nstep == n || nstep/bs > bi) {
			cnt[i] = 1; nxt[i] = nstep;
		} else {
			cnt[i] = cnt[nstep] + 1; nxt[i] = nxt[nstep];
		}
	}

	for (int i=0; i<m; ++i) {
		int cmd; scanf("%d", &cmd);
		if (cmd == 0) {
			int a, b; scanf("%d%d", &a, &b);
			--a; p[a] = b;
			int nstep = min(n, a+b), bi = a / bs;
			if (nstep == n || nstep/bs > bi) {
				cnt[a] = 1; nxt[a] = nstep;
			} else {
				cnt[a] = cnt[nstep] + 1; nxt[a] = nxt[nstep];
			}

			for (int j=a-1, end=bi*bs; j>=end; --j) {
				nstep = j+p[j];
				if (nstep <= a) {
					nxt[j] = nxt[nstep]; cnt[j] = cnt[nstep]+1;
				}
			}
		} else {
			int a; scanf("%d", &a);
			--a;

			int ans = 0, last;
			while (a < n) {
				last = a;
				ans += cnt[a];
				a = nxt[a];
			}

			while (last+p[last] < n) { last += p[last]; }
			printf("%d %d\n", last+1, ans);
		}
	}

	return 0;
}
