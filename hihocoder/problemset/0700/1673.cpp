#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000
struct StackItem { int h, p; } st[MAXN];
char mat[2][MAXN+2];
int cnt[2][MAXN+1];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	memset(cnt, 0, sizeof(cnt));
	int mx = 0;
	for (int i=0; i<n; ++i) {
		int cur = i & 1, pre = (i-1) & 1;
		scanf("%s", &mat[cur][1]);
		mat[cur][0] = mat[cur][1];
		int r = 0;
		for (int j=1; j<=m; ++j) {
			cnt[cur][j] = (mat[cur][j]==mat[pre][j]) ? 1 : cnt[pre][j]+1;
			if (mat[cur][j] == mat[cur][j-1]) { r = 0; }
			int p = j;
			while (r != 0 && st[r-1].h > cnt[cur][j]) {
				auto item = st[--r];
				mx = max(mx, (j-item.p) * item.h);
				p = item.p;
			}

			st[r++] = {cnt[cur][j], p};
		}

		while (r != 0) {
			auto item = st[--r];
			mx = max(mx, (m-item.p+1) * item.h);
		}
	}

	printf("%d\n", mx);
	return 0;
}
