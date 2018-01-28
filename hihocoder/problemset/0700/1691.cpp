#include <bits/stdc++.h>
using namespace std;

#define MAXN 10
char tar[MAXN+1], sta[MAXN+1], tmps[MAXN+1];

int dfs(const char *tar, char *cur, int cidx, int n, int cnt) {
	if (cidx == n) {
		int ans = 0;
		for (int i=0; i<cidx; ++i) {
			if (tar[i] != cur[i]) {
				int diff = abs(tar[i]-cur[i]);
				ans += min(diff, 10-diff);
			}
		}

		return ans + cnt;
	}

	int mn = dfs(tar, cur, cidx+1, n, cnt);
	for (int i=0; i<cidx; ++i) {
		swap(cur[i], cur[cidx]);
		mn = min(mn, dfs(tar, cur, cidx+1, n, cnt+1));
		swap(cur[i], cur[cidx]);
	}

	return mn;
}

int main() {
	int n; scanf("%d", &n);
	scanf("%s%s", tar, sta);

	int ans = dfs(tar, sta, 0, n, 0);
	printf("%d\n", ans);
	return 0;
}
