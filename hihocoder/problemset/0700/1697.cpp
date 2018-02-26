#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
struct node_t { int l, r, p, v; } nodes[MAXN+1];

void traverse(int cur) {
	if (cur == -1) { return; }
	printf("%d\n", nodes[cur].v);
	traverse(nodes[cur].l);
	traverse(nodes[cur].r);
}

int main() {
	int n; scanf("%d", &n);
	nodes[0] = { -1, -1, -1, 0 };

	for (int i=0, cur=0, nxt=1; i<n; ++i) {
		int v; scanf("%d", &v);
		nodes[nxt] = { -1, -1, -1, v };

		while (nodes[nxt].v < nodes[cur].v) {
			cur = nodes[cur].p;
		}

		nodes[nxt].l = nodes[cur].r;
		if (nodes[cur].r > 0) { nodes[nodes[cur].r].p = nxt; }
		nodes[cur].r = nxt;
		nodes[nxt].p = cur;
		cur = nxt++;
	}

	traverse(nodes[0].r);
	return 0;
}
