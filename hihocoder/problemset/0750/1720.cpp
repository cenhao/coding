#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
bool vis[MAXN+1], enc[10];

int main() {
	int p, q; scanf("%d%d", &p, &q);
	memset(vis, 0, sizeof(vis));
	memset(enc, 0, sizeof(enc));
	while (p!=0 && !vis[p]) {
		vis[p] = true;
		p *= 10;
		while (p < q) {
			p *= 10;
			enc[0] = true;
		}
		int d = p / q, r = p % q;
		enc[d] = true;
		p = r;
	}
	for (int i=0; i<10; ++i) {
		if (enc[i]) { printf("%d", i); }
	}
	printf("\n");
	return 0;
}
