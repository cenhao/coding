#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define INF 0x7fffffff
int a[MAXN];

struct Status {
	int v, p, lv, rv;
} s[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }

	int h = 0;
	s[0] = { a[0], 0, -INF, INF };
	for (int i=1, state=0; i<n; ++i) {
		if(state==1 && s[h].lv<a[i] && a[i]<s[h].v) {
			++h; state = 0;
		}

		while (a[i]<s[h].lv || a[i]>s[h].rv) { ++h; }

		if (s[h].lv<a[i] && a[i]<s[h].v) {
			s[i] = { a[i], s[h].v, s[h].lv, s[h].v };
			state = 1;
		} else {
			s[i] = { a[i], s[h].v, s[h].v, s[h].rv };
			++h;
			state = 0;
		}
	}

	for (int i=0; i<n; ++i) {
		printf("%d%c", s[i].p, (i==n-1) ? '\n' : ' ');
	}

	return 0;
}
