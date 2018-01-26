#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXM 1000000
int alias[MAXN+1], state[MAXN+1], vis[MAXN+1];
unordered_set<int> adj[MAXN+1];

int find(int x) {
	if (alias[x] != alias[alias[x]]) { alias[x] = find(x); }
	return alias[x];
}

void flood(int i) {
	for (auto c: adj[i]) {
		int bc = find(c);
		if (bc != c) {
			if (adj[i].find(bc) != adj[i].end()) { adj[i].insert(bc); }
			adj[i].erase(c);
		}

		if ((state[bc] & state[i]) != state[i]) {
			state[bc] |= state[i];
			flood(bc);
		}
	}
}

void merge(int a, int b) {
	int aa = find(a), ba = find(b);
	if (aa == ba) { return; }
	unordered_set<int> tmp;
	for (auto i : adj[aa]) { tmp.insert(find(i)); }
	for (auto i : adj[ba]) { tmp.insert(find(i)); }

	alias[ba] = aa;
	adj[aa] = move(tmp);
	adj[ba] = move(tmp); // clean up
	state[aa] |= state[ba];

	flood(aa);
}

void add(int a, int b) {
	int aa = find(a), ba = find(b);
	adj[aa].insert(ba);
	if ((state[ba] & state[aa]) != state[aa]) {
		state[ba] |= state[aa];
		flood(ba);
	}
}

int main() {
	char buff[32];
	fgets(buff, sizeof(buff), stdin);
	int n, m; sscanf(buff, "%d%d", &n, &m);
	for (int i=1; i<=n; ++i) { alias[i] = i; }
	memset(state, 0, sizeof(state));
	state[1] = 1; state[n] = 2;
	int ans = -1;
	for (int i=0; i<m; ++i) {
		int a, b;
		char op;
		fgets(buff, sizeof(buff), stdin);
		sscanf(buff, "A%d %c A%d", &a, &op, &b);

		if (ans > 0) { continue; }

		if (op == '=') {
			merge(a, b);
		} else {
			add(a, b);
		}

		int oa = find(1), na = find(n);
		if (oa == na || (state[na] & 1) || (state[oa] & 2)) {
			ans = i+1;
		}
	}

	printf("%d\n", ans);
	return 0;
}
