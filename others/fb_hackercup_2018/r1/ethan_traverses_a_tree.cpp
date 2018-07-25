#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000

int lr[MAXN+1][2];
int f[MAXN+1];
int preo[MAXN], posto[MAXN];
int ans[MAXN+1];

int pre_traverse(int cur, int idx) {
	if (cur == 0) { return 0; }
	int cnt = 1;
	preo[idx] = cur;
	cnt += pre_traverse(lr[cur][0], idx+cnt);
	cnt += pre_traverse(lr[cur][1], idx+cnt);
	return cnt;
}

int post_traverse(int cur, int idx) {
	if (cur == 0) { return 0; }
	int cnt = post_traverse(lr[cur][0], idx);
	cnt += post_traverse(lr[cur][1], idx+cnt);
	posto[idx+cnt] = cur;
	return cnt + 1;
}

int find(int x) {
	return f[x] = f[x]==f[f[x]] ? f[x] : find(f[x]);
}

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int n, k; scanf("%d%d", &n, &k);
		for (int i=1; i<=n; ++i) { scanf("%d%d", &lr[i][0], &lr[i][1]); }
		pre_traverse(1, 0);
		post_traverse(1, 0);
		/*if (t == 70) {
			for (int i=0; i<n; ++i) { printf("%d:%d ", i, preo[i]); }
			printf("\n");
			for (int i=0; i<n; ++i) { printf("%d:%d ", i, posto[i]); }
			printf("\n");
		}*/
		for (int i=1; i<=n; ++i) { f[i] = i; }
		for (int i=0; i<n; ++i) {
			if (preo[i] == posto[i]) { continue; }
			int p1 = find(preo[i]), p2 = find(posto[i]);
			f[p2] = p1;
		}
		int cur = 0;
		memset(ans, -1, sizeof(ans));
		for (int i=1; i<=n; ++i) {
			int p = find(i);
			if (ans[p] == -1) {
				ans[p] = ans[i] = cur >= k ? k : ++cur;
			} else {
				ans[i] = ans[p];
			}
		}

		printf("Case #%d:", t);
		if (k > cur) {
			printf(" Impossible\n");
		} else {
			for (int i=1; i<=n; ++i) { printf(" %d", ans[i]); }
			printf("\n");
		}
	}

	return 0;
}
