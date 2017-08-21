#include <bits/stdc++.h>
using namespace std;

int ans[10];

void dfs(int start, int pre, int n, int k) {
	if (n == start) {
		for (int i=0; i<n; ++i) { printf("%d", ans[i]); }
		printf("\n");
		return;
	}

	for (int i=(start==0?1:0); i<=k && pre*i<=k; ++i) {
		ans[start] = i;
		dfs(start+1, i, n, k);
	}
}

int main() {
	int n, k; scanf("%d%d", &n, &k);
	dfs(0, 1, n, k);

	return 0;
}
