#include <bits/stdc++.h>
using namespace std;

#define MAXN 3000

struct Node {
	int children, nxt;
	int dp[MAXN];
} nodes[MAXN+1];

int tmp[MAXN];

int dfs(int cur) {
	nodes[cur].dp[0] = 0;
	int cnt = 0, mx = 0;
	for (int i=nodes[cur].children; i!=-1; i=nodes[i].nxt) {
		int smx = dfs(i);
		memcpy(tmp, nodes[cur].dp, sizeof(nodes[cur].dp));
		for (int j=1; j<=smx; ++j) {
			if (nodes[i].dp[j] == -1) { continue; }
			for (int k=mx; k>=0; --k) {
				if (nodes[cur].dp[k] == -1) { continue; }
				if (tmp[k+j] == -1
					|| tmp[k+j] > nodes[cur].dp[k] + nodes[i].dp[j]) {
					tmp[k+j] = nodes[cur].dp[k] + nodes[i].dp[j];
				}
			}
		}
		memcpy(nodes[cur].dp, tmp, sizeof(nodes[cur].dp));
		mx += smx;
		++cnt;
	}

	for (int i=mx; i>=0; --i) {
		if (nodes[cur].dp[i] == -1) { continue; }
		if (nodes[cur].dp[i+cnt] == -1
			|| nodes[cur].dp[i+cnt] > nodes[cur].dp[i] + 1) {
			nodes[cur].dp[i+cnt] = nodes[cur].dp[i] + 1;
		}
	}

	mx += cnt;
	return mx;
}

int main() {
	memset(nodes, -1, sizeof(nodes));

	int n; scanf("%d", &n);
	for (int i=2; i<=n; ++i) {
		int f; scanf("%d", &f);
		nodes[i].nxt = nodes[f].children;
		nodes[f].children = i;
	}

	dfs(1);

	for (int i=0; i<n; ++i) {
		printf("%d%c", nodes[1].dp[i], i == n-1 ? '\n' : ' ');
	}

	return 0;
}
