#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

char robots[MAXN+1];

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		scanf("%s", robots);
		bool lb = false;
		int cnt = 0, buff = 0;
		for (int i=0, end=strlen(robots); i<end; ++i) {
			if (robots[i] == 'l' && lb) {
				++cnt;
				cnt += buff;
				buff = 0;
			} else if (robots[i] == 'd') {
				cnt += buff;
				lb = true;
				buff = 0;
			} else if (robots[i] == 'r') {
				++buff;
				lb = true;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}
