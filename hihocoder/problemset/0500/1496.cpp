#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

struct TrieNode {
	int links[2];
	int mx[2];
} nodes[MAXN*20];
int first;

void insert(int v) {
	int cur = 0;
	for (int i=19; i>=0; --i) {
		int idx = (v >> i) & 1;
		if (nodes[cur].links[idx] == -1) {
			nodes[cur].links[idx] = ++first;
			nodes[first].links[0] = nodes[first].links[1] = -1;
			nodes[first].mx[0] = nodes[first].mx[1] = 0;
		}

		cur = nodes[cur].links[idx];
		if (v >= nodes[cur].mx[0]) {
			nodes[cur].mx[1] = nodes[cur].mx[0];
			nodes[cur].mx[0] = v;
		} else if (v > nodes[cur].mx[1]) {
			nodes[cur].mx[1] = v;
		}
	}
}

void dfs(int cur, int64_t &mx) {
	if (cur == -1) return;
	int64_t tmp = int64_t(nodes[cur].mx[0]) * nodes[cur].mx[1] * (nodes[cur].mx[0] & nodes[cur].mx[1]);
	mx = max(mx, tmp);
	dfs(nodes[cur].links[0], mx);
	dfs(nodes[cur].links[1], mx);
}

int main() {
	int t; scanf("%d", &t);

	while (t--) {
		first = 0;
		nodes[first].mx[0] = nodes[first].mx[1] = 0;
		nodes[first].links[0] = nodes[first].links[1] = -1;

		int n; scanf("%d", &n);
		for (int i=0; i<n; ++i) {
			int v; scanf("%d", &v);
			insert(v);
		}

		int64_t mx = 0;
		dfs(0, mx);
		printf("%" PRId64 "\n", mx);
	}

	return 0;
}
