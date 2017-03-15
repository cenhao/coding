#include <bits/stdc++.h>
using namespace std;

#define MAXN 50

struct Snack {
	int desire, price;
} sn[MAXN];

int dfs(int start, int psum, int dsum, int cnt, int end) {
	int mx = 0;
	if ((psum % 50) == 0) { mx = max(mx, dsum); }
	if (cnt >= 3) { return mx; }
	for (int i=start; i<end; ++i) {
		mx = max(mx, dfs(i+1, psum+sn[i].price, dsum+sn[i].desire, cnt+1, end));
	}
	return mx;
}

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int n; scanf("%d", &n);

		int a, b;
		char buff[32];
		for (int i=0; i<n; ++i) {
			scanf("%s %d", buff, &sn[i].desire);
			int rcnt = sscanf(buff, "%d.%d", &a, &b);
			if (rcnt != 2) { b = 0; }
			sn[i].price = a * 10 + b;
		}

		printf("%d\n", dfs(0, 0, 0, 0, n));
	}

	return 0;
}
