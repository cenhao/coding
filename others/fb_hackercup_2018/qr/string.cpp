#include <bits/stdc++.h>
using namespace std;

#define MAXSL 2000
char a[MAXSL+1];

bool check(int sta, int len) {
	for (int i=sta; i<len; ++i) {
		if (a[i] != a[i-sta]) { return i == sta; }
	}

	return true;
}

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		scanf("%s", a);
		int len = strlen(a), ans = -1;
		for (int i=1; i<len; ++i) {
			if (!check(i, len)) {
				ans = i;
				break;
			}
		}
		printf("Case #%d: ", t);
		if (ans < 0) {
			printf("Impossible\n");
		} else {
			for (int i=0; i<ans; ++i) { printf("%c", a[i]); }
			printf("%s\n", a);
		}
	}

	return 0;
}

