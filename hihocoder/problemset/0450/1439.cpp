#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 100
#define F_AND 0
#define F_OR 1
#define F_TRUE 2
#define F_FALSE 3
#define INF 100000

struct Node {
	int lc, rc;
	int flag;
	int cost;
	int result;
} nodes[MAXN+1];

void dfs(int cur) {
	if (cur == -1) { return; }

	dfs(nodes[cur].lc);
	dfs(nodes[cur].rc);

	if (nodes[cur].flag >= F_TRUE) {
		nodes[cur].cost = INF;
		return;
	}

	int tmp;
	if (nodes[cur].flag == F_AND) {
		tmp = (nodes[nodes[cur].lc].flag == F_TRUE &&
			   nodes[nodes[cur].rc].flag == F_TRUE) ?
			F_TRUE : F_FALSE;
		if (tmp == F_TRUE) {
			nodes[cur].cost =
				min(nodes[nodes[cur].lc].cost, nodes[nodes[cur].rc].cost);
		} else {
			if (nodes[nodes[cur].lc].flag == F_FALSE) {
				if (nodes[nodes[cur].rc].flag == F_FALSE) {
					nodes[cur].cost = min(
						1+min(nodes[nodes[cur].lc].cost, nodes[nodes[cur].rc].cost),
						nodes[nodes[cur].lc].cost+nodes[nodes[cur].rc].cost);
				} else {
					nodes[cur].cost = 1;
				}
			} else {
				nodes[cur].cost = 1;
			}
		}
	} else {
		tmp = (nodes[nodes[cur].lc].flag == F_TRUE ||
			   nodes[nodes[cur].rc].flag == F_TRUE) ?
			F_TRUE : F_FALSE;
		if (tmp == F_FALSE) {
			nodes[cur].cost =
				min(nodes[nodes[cur].lc].cost, nodes[nodes[cur].rc].cost);
		} else {
			if (nodes[nodes[cur].lc].flag == F_TRUE) {
				if (nodes[nodes[cur].rc].flag == F_TRUE) {
					nodes[cur].cost = min(
						1+min(nodes[nodes[cur].lc].cost, nodes[nodes[cur].rc].cost),
						nodes[nodes[cur].lc].cost+nodes[nodes[cur].rc].cost);
				} else {
					nodes[cur].cost = 1;
				}
			} else {
				nodes[cur].cost = 1;
			}
		}
	}

	nodes[cur].flag = tmp;
}

int main() {
	memset(nodes, -1, sizeof(nodes));

	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		int p; char f[10]; scanf("%d %s", &p, f);

		nodes[p].rc = nodes[p].lc;
		nodes[p].lc = i;
		
		if (f[0] == 'A') {
			nodes[i].flag = F_AND;
		} else if (f[0] == 'O') {
			nodes[i].flag = F_OR;
		} else if (f[0] == 'T') {
			nodes[i].flag = F_TRUE;
		} else {
			nodes[i].flag = F_FALSE;
		}
	}

	dfs(nodes[0].lc);
	if (nodes[nodes[0].lc].cost >= INF) {
		printf("-1\n");
	} else {
		printf("%d\n", nodes[nodes[0].lc].cost);
	}
	return 0;
}
