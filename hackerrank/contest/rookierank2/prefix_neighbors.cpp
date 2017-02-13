#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define RNG 26 /* A ~ Z */
#define MAXN 400000
#define MAXS 11

struct TrieNode {
	bool is_str;
	int links[RNG];
	int pv, npv; /* pick value, not pick value */
} nodes[MAXN * MAXS + 10];
int nfirst = 0;

void init_node(int nidx) {
	nodes[nidx].is_str = false;
	memset(nodes[nidx].links, -1, sizeof(nodes[nidx].links));
	nodes[nidx].pv = nodes[nidx].npv = 0;
}

void insert(char *str) {
	int nidx = 0, len = strlen(str);
	for (int i=0; i<len; ++i) {
		int lv = str[i] - 'A';
		if (nodes[nidx].links[lv] == -1) {
			int cidx = nodes[nidx].links[lv] = nfirst++;
			init_node(cidx);
		}

		nidx = nodes[nidx].links[lv];
	}

	nodes[nidx].is_str = true;
}

void greed_process(int idx, int depth, int value) {
	int cidx;
	for (int i=0; i<RNG; ++i) {
		if ((cidx = nodes[idx].links[i]) != -1) {
			greed_process(cidx, depth+1, value + i + 'A');
			int tmp = max(nodes[cidx].pv, nodes[cidx].npv);
			if (nodes[idx].is_str) {
				nodes[idx].pv += nodes[cidx].npv;
				nodes[idx].npv += tmp;
			} else {
				nodes[idx].pv += tmp;
				nodes[idx].npv += nodes[cidx].npv;
			}
		}
	}

	if (nodes[idx].is_str) { nodes[idx].pv += value; }
}

int main() {
	int n; scanf("%d", &n);
	int root = nfirst++;
	init_node(root);

	char buff[MAXS+1];
	for (int i=0; i<n; ++i) {
		scanf("%s", buff);
		insert(buff);
	}

	greed_process(root, 0, 0);
	int ans = 0, cidx;

	printf("%d\n", nodes[root].pv);
	return 0;
}
