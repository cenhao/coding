#include <bits/stdc++.h>
using namespace std;

#define MAXS 5000001

char s[MAXS+1];
char buff[MAXS*2+1];
int range[MAXS*2+1];
int degree[MAXS];

int main() {
	scanf("%s", s);
	int len = strlen(s);

	buff[0] = 0;
	for (int i=0; i<len; ++i) {
		buff[i*2+1] = s[i];
		buff[i*2+2] = 1;
	}

	range[0] = range[1] = 0;
	for (int i=2, end=len*2, center=1; i<=end; ++i) {
		int cc = center;
		while (cc < i) {
			if (range[cc]+cc+1 == i && buff[2*cc-i] == buff[i]) { break; }
			++cc;
			range[cc] = min(i-cc-1, range[2*center-cc]);
		}

		if (buff[2*cc-i] == buff[i]) { ++range[cc]; }
		center = cc;
	}

	memset(degree, 0, sizeof(degree));
	int ans = 0;
	for (int i=0; i<len; ++i) {
		int center = i + 1;
		if (range[center] == i) {
			degree[i] = (i == 0 ? 0 : degree[(i-1)/2]) + 1;
			ans += degree[i];
		}
	}

	printf("%d\n", ans);

	return 0;
}
