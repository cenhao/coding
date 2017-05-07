#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int a[MAXN];
bool vis[MAXN];

int main() {
	memset(vis, 0, sizeof(vis));

	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &a[i]); }
	int mx = 0;
	for (int i=0; i<n; ++i) {
		int pos = i;
		int cnt = 0;
		while (!vis[pos]) {
			vis[pos] = true;
			++cnt;
			pos = a[pos]-1;
		}

		mx = max(mx, cnt);
	}

	printf("%d\n", mx);
	return 0;
}
