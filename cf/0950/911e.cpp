#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000
int a[MAXN], stk[MAXN];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) { scanf("%d", &a[i]); }
	int h = -1, nxt = 1;
	bool ok = true;
	for (int i=0; i<m && ok; ++i) {
		if (h >= 0 && a[i] > stk[h]) {
			ok = false;
		} else {
			stk[++h] = a[i];
			while (h >= 0 && stk[h] == nxt) {
				++nxt; --h;
			}
		}
	}


	if (ok) {
		while (h >= 0) {
			int val = stk[h] - 1;
			a[m++] = stk[++h] = val;
			while (h >= 0 && stk[h] == nxt) {
				++nxt; --h;
			}
		}

		for (int i=n; i>=nxt; --i) { a[m++] = i; }
		for (int i=0; i<m; ++i) { printf("%d%c", a[i], (i==m-1) ? '\n' : ' '); }
	} else {
		printf("-1\n");
	}

	return 0;
}
