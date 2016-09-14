#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 100000

struct Node {
	int v;
	int nxt;
} nodes[MAXN*2];

int first, n;
int head[MAXN+1];

void read() {
	memset(head, -1, sizeof(head));
	first = 0;
	int u, v;
	for (int i=1; i<n; ++i) {
		scanf("%d %d", &u, &v);
		nodes[first].v = v; nodes[first].nxt = head[u]; head[u] = first++;
		nodes[first].v = u; nodes[first].nxt = head[v]; head[v] = first++;
	}
}

int process(int cur, int parent, int *pmx) {
	int mc1 = 0, mc2 = 0;

	for (int i=head[cur]; i!=-1; i=nodes[i].nxt) {
		if (nodes[i].v == parent) { continue; }

		int tmp = process(nodes[i].v, cur, pmx) + 1;
		if (tmp > mc1) {
			mc2 = mc1;
			mc1 = tmp;
		} else if (tmp > mc2) {
			mc2 = tmp;
		}
	}

	*pmx = max(*pmx, mc1 + mc2);
	return mc1;
}

int process() {
	int mx = 0;
	process(1, 0, &mx);
	return mx;
}

int main() {
	scanf("%d", &n);
	read();
	printf("%d\n", process());
	return 0;
}
