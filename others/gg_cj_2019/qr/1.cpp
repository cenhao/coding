#include <bits/stdc++.h>
using namespace std;

#define MAXL 101

char n[MAXL], m[MAXL];

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		scanf("%s", n);
		int len = strlen(n);
		reverse(n, n+len);
		memset(m, 0, sizeof(m));
		int mlen = 0;
		for (int i=0; i<=len; ++i) {
			if (n[i] != '4') { continue; }
			while (mlen != i) { m[mlen++] = '0'; }
			n[i] = m[mlen++] = '2';
		}

		reverse(m, m+mlen);
		reverse(n, n+len);
		if (mlen == 0) { m[0] = '0'; }
		printf("Case #%d: %s %s\n", t, n, m);
	}

	return 0;
}
