#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

struct Node {
	int l, r;
} nodes[MAXN+1];

int arr[MAXN+1];

void dfs(int cur, int &d) {
	if (cur == -1) {
		for (int i=d-1; i>=0; --i) { printf("%d\n", arr[i]); }
		d = 0;
		return;
	}
	arr[d++] = cur;
	dfs(nodes[cur].l, d);
	dfs(nodes[cur].r, d);
}

int main() {
	memset(nodes, -1, sizeof(nodes));
	memset(arr, 0, sizeof(arr));
	int n; scanf("%d", &n);
	for (int i=1; i<n; ++i) {
		int f, c; scanf("%d%d", &f, &c);
		if (nodes[f].l == -1 || nodes[f].l > c) {
			nodes[f].r = nodes[f].l;
			nodes[f].l = c;
		} else {
			nodes[f].r = c;
		}

		arr[c] = 1;
	}

	int root;
	for (int i=1; i<=n; ++i) {
		if (arr[i] == 0) {
			root = i;
			break;
		}
	}

	int d = 0;
	dfs(root, d);

	return 0;
}
