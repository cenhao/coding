#include <bits/stdc++.h>
using namespace std;

#define MAXN 50001
char mov[MAXN];

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int n; scanf("%d", &n);
		scanf("%s", mov);
		for (int i=0; i<2*n-2; ++i) {
			mov[i] = (mov[i] == 'S') ? 'E' : 'S';
		}

		printf("Case #%d: %s\n", t, mov);
	}

	return 0;
}
