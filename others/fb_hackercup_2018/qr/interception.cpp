#include <bits/stdc++.h>
using namespace std;

#define MAXN 50
int p[MAXN+1];

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int n; scanf("%d", &n);
		for (int i=n; i>=0; --i) { scanf("%d", &p[i]); }
		printf("Case #%d: ", t);
		if (n & 1) {
			printf("1\n0.0\n");
		} else {
			printf("0\n");
		}
	}
	return 0;
}
