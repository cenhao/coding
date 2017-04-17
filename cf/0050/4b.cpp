#include <bits/stdc++.h>
using namespace std;

#define MAXN 30

int tb[MAXN][2];

int main() {
	int d, sum; scanf("%d %d", &d, &sum);
	for (int i=0; i<d; ++i) {
		scanf("%d %d", &tb[i][0], &tb[i][1]);
		sum -= tb[i][0];
	}

	for (int i=0; i<d && sum > 0; ++i) {
		int v = min(tb[i][1]-tb[i][0], sum);
		sum -= v; tb[i][0] += v;
	}

	if (sum != 0) {
		printf("NO\n");
	} else {
		printf("YES\n");
		for (int i=0; i<d; ++i) {
			printf("%d%c", tb[i][0], (i == d-1) ? '\n' : ' ');
		}
	}

	return 0;
}
