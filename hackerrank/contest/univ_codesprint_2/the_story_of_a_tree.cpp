#include <cstdint>
#include <cstdio>
#include <cstring>
#include <unordered_set>
using namespace std;

#define MAXN 100000
#define HASH_VAL(u, v) (((int64_t)u-1)*MAXN + v-1)

int gcd(int a, int b) {
	while (b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

struct AdjacentNode {
	int v;
	int nxt;
} an[2*MAXN+10];
int first;

int adj[MAXN+1];

void connect(int u, int v) {
	int tmp = first++;
	an[tmp].nxt = adj[u];
	an[tmp].v = v;
	adj[u] = tmp;
}

int dfs_1(int cur, int par, const unordered_set<int64_t> &guesses) {
	int cnt = 0;
	for (int i=adj[cur]; i!=-1; i=an[i].nxt) {
		if (an[i].v == par) { continue; }
		if (guesses.end() != guesses.find(HASH_VAL(cur, an[i].v))) { ++cnt; }
		cnt += dfs_1(an[i].v, cur, guesses);
	}

	return cnt;
}

int dfs_2(int cur, int par, const unordered_set<int64_t> &guesses, int hit, int k) {
	if (par != -1 && guesses.find(HASH_VAL(cur, par)) != guesses.end()) { ++hit; }

	int cnt = (hit >= k) ? 1 : 0;
	for (int i=adj[cur]; i!=-1; i=an[i].nxt) {
		if (an[i].v == par) { continue; }
		bool found = guesses.find(HASH_VAL(cur, an[i].v)) != guesses.end();
		cnt += dfs_2(an[i].v, cur, guesses, hit-(found?1:0), k);
	}

	return cnt;
}

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int n; scanf("%d", &n);
		memset(adj, -1, sizeof(adj));
		first = 0;
		for (int i=1; i<n; ++i) {
			int u, v; scanf("%d %d", &u, &v);
			connect(u, v);
			connect(v, u);
		}

		int g, k; scanf("%d %d", &g, &k);
		unordered_set<int64_t> guesses(g);
		for (int i=0; i<g; ++i) {
			int u, v; scanf("%d %d", &u, &v);
			guesses.insert(HASH_VAL(u, v));
		}

		int hit = dfs_1(1, -1, guesses);
		int cnt = dfs_2(1, -1, guesses, hit, k);

		int div = gcd(cnt, n);
		printf("%d/%d\n", cnt/div, n/div);
	}

	return 0;
}
