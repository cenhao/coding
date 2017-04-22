#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

char file[MAXN][MAXN+3];

int main() {
	int cnt = 0, mx = 0;
	while (NULL != fgets(file[cnt], sizeof(file[cnt]), stdin)) {
		int len = strlen(file[cnt]);
		file[cnt][--len] = 0;
		mx = max(mx, len);
		++cnt;
	}

	int uneven = 0;
	for (int i=-1; i<=mx; ++i) { printf("*"); }
	printf("\n");
	for (int i=0; i<cnt; ++i) {
		printf("*");
		int space = mx - strlen(file[i]);
		int pre = space / 2;
		int suf = space / 2;
		if (space & 1) {
			if (uneven & 1) {
				++pre;
			} else {
				++suf;
			}
			++uneven;
		}
		for (int j=0; j<pre; ++j) { printf(" "); }
		printf("%s", file[i]);
		for (int j=0; j<suf; ++j) { printf(" "); }
		printf("*\n");
	}
	for (int i=-1; i<=mx; ++i) { printf("*"); }
	printf("\n");

	return 0;
}
