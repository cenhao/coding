#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000

char s[MAXN+1];

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		scanf("%s", s);
		int len = strlen(s);
		int state = 0; // 0 -> nothing, 1 -> ^1, 2 -> 0+
		int cnt = 0;
		for (int i=0; i<len; ++i) {
			if (s[i] == '1') {
				if (state == 0) {
					state = 1;
				} else if (state == 2) {
					state = 1;
					++cnt;
				}
				// state == 1, do nothing
			}
			else if (s[i] == '0') {
				if (state == 1) { state = 2; }
			} else {
				state = 0;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}
