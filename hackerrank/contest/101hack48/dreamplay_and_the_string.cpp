#include <bits/stdc++.h>
using namespace std;

#define MAXS 1000000

char s[MAXS+1], p[MAXS+1];

bool check(int start, int plen) {
	for (int i=0; i<plen; ++i) {
		if (s[start+i] != p[i]) { return false; }
	}
	return true;
}

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		scanf("%s %s", s, p);
		int slen = strlen(s), plen = strlen(p);
		int k = slen - plen;
		bool sw;
		if (k & 1) {
			sw = !check((k-1)/2, plen) || !check((k+1)/2, plen);
		} else {
			sw = !check(k/2, plen) && (!check(k/2-1, plen) || !check(k/2+1, plen));
		}

		printf("%s\n", sw ? "Steven" : "Amanda");
	}

	return 0;
}
