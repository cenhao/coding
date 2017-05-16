#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXM 1000000

int f[MAXN+1], w[MAXN+1];

int find(int x) {
	if (f[x] == x) { return x; }
	return f[x] = find(f[x]);
}

void merge(int u, int v) {
	int fu = find(u), fv = find(v);
	if (fu == fv) { return; }
	if (w[fu] > w[fv]) {
		f[fv] = fu;
		w[fu] += w[fv];
	} else {
		f[fu] = fv;
		w[fv] += w[fu];
	}
}

struct Edge {
	int u, v, l;
} e[MAXM];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) { scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].l); }
	for (int i=1; i<=n; ++i) { f[i] = i; w[i] = 1; }
	sort(e, e+m, [](const Edge &e1, const Edge &e2) -> bool {
		return e1.l < e2.l;
	});
	int sum = 0;
	for (int i=0; i<m; ++i) {
		if (find(e[i].u) == find(e[i].v)) { continue; }
		merge(e[i].u, e[i].v);
		sum += e[i].l;
	}

	printf("%d\n", sum);
	return 0;
}
