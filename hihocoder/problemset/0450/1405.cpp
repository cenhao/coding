#include <stdio.h>

#define MAXN 100

int inorder[MAXN];

void dfs(int sta, int end, int *idx, int n) {
	if (sta >= end) { return; }

	int mn = inorder[sta];
	int pos = sta;
	for (int i=sta; i<end; ++i) {
		if (inorder[i] < mn) {
			mn = inorder[i];
			pos = i;
		}
	}

	printf("%d%c", mn, (*idx == n-1) ? '\n':' ');
	++(*idx);
	dfs(sta, pos, idx, n);
	dfs(pos+1, end, idx, n);
}

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &inorder[i]); }
	int first = 0;
	dfs(0, n, &first, n);
	return 0;
}
