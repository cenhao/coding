#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

char rec[MAXN+1];
int conc[MAXN+1];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", rec);
		int len = strlen(rec);
		int abs = 0;
		int mx = 0;

		for (int i=0; i<len; ++i) {
			if (rec[i] == 'O') {
				conc[i] = 0;
			} else if (rec[i] == 'L') {
				conc[i] = (i == 0) ? 1 : conc[i-1]+1;
				mx = max(mx, conc[i]);
			} else {
				conc[i] = 0;
				++abs;
			}
		}

		if (abs <= 1 && mx < 3) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}
