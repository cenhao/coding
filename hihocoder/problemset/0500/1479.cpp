#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 100000

struct Node {
	int v;
	int fc, sb, sum;
	int64_t tcnt;
} nodes[MAXN+1];

int dfs1(int cur, int target) {
	int vsum = nodes[cur].v;
	for (int i=nodes[cur].fc; i!=-1; i=nodes[i].sb) {
		vsum += dfs1(i, target);
		nodes[cur].tcnt += nodes[i].tcnt;
	}

	if (vsum == target && cur != 0) { ++nodes[cur].tcnt; }
	nodes[cur].sum = vsum;
	return vsum;
}

int64_t dfs2(int cur, int target, int64_t ptcnt, int psum, int par) {
	int64_t ans = 0;
	if (nodes[cur].sum == target && cur != 0) {
		ans += ptcnt;
		if (psum == target && par != 0) { --ans; }
	}
	for (int i=nodes[cur].fc; i!=-1; i=nodes[i].sb) {
		nodes[cur].tcnt -= nodes[i].tcnt;
		int csum = psum + nodes[cur].sum - nodes[i].sum;
		int adj = (csum == target && cur != 0) ? 1 : 0;
		if (nodes[cur].sum == target && cur != 0) { --adj; }
		ans += dfs2(i, target, ptcnt+nodes[cur].tcnt+adj, csum, cur);
	}

	return ans;
}

int main() {
	int t; scanf("%d", &t);

	while (t--) {
		int sum = 0;
		memset(nodes, -1, sizeof(nodes));
		nodes[0].v = nodes[0].tcnt = 0;

		int n, p; scanf("%d", &n);
		for (int i=1; i<=n; ++i) {
			scanf("%d %d", &nodes[i].v, &p);
			nodes[i].sb = nodes[p].fc;
			nodes[p].fc = i;
			nodes[i].tcnt = 0;
			sum += nodes[i].v;
		}

		if (sum % 3 != 0) {
			printf("%d\n", 0);
			continue;
		}

		int target = sum / 3;
		dfs1(0, target);
		printf("%" PRId64 "\n", dfs2(0, target, 0, 0, -1));
	}

	return 0;
}
