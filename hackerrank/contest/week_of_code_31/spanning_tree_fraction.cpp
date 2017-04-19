/*
 * Binary search optimal value C = sum(a) / sum(b)
 * C * sum(b) = sum(a) => sum(a) - sum(b*C) = 0
 * => sum(a-b*C) = 0
 * use a-b*c as the weight of the edges, then find the
 * maximal spanning tree. if the sum of the weight is larger than 0,
 * then C is possible
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define ESP 1e-7

struct Edge {
	int a, b;
	int v;
	int nxt;
} e[2*MAXN+5];
int ef;

int adj[MAXN+1];
int vis[MAXN+1];
double mx[MAXN+1];

int gcd(int a, int b) {
	while (b != 0) { int r = a % b; a = b; b = r; }
	return a;
}

bool check(double c, int n, int &asum, int &bsum) {
	auto cmp = [c](const int &lhs, const int &rhs) -> bool {
		return (::e[lhs].a - ::e[lhs].b*c) < (::e[rhs].a - ::e[rhs].b*c);
	};

	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
	e[ef].a = e[ef].b = e[ef].v = 0;
	pq.push(ef);
	double sum = 0;
	asum = 0, bsum = 0;
	memset(vis, 0, n*sizeof(int));
	int cnt = 0;

	while (!pq.empty() && cnt < n) {
		int tmp = pq.top(); pq.pop();
		if (vis[e[tmp].v]&1) { continue; }

		sum += e[tmp].a - e[tmp].b * c;
		asum += e[tmp].a; bsum += e[tmp].b;
		vis[e[tmp].v] |= 1;
		tmp = e[tmp].v;

		for (int i=adj[tmp]; i!=-1; i=e[i].nxt) {
			if (vis[e[i].v] & 1) { continue; }
			double v = e[i].a - c*e[i].b;
			if (!(vis[e[i].v] & 2) || v>=mx[e[i].v]+ESP) {
				vis[e[i].v] |= 2;
				mx[e[i].v] = v;
				pq.push(i);
			}
		}

		++cnt;
	}

	int d = gcd(asum, bsum);
	asum /= d;
	bsum /= d;

	return sum >= 0;
}

int main() {
	memset(adj, -1, sizeof(adj));
	ef = 0;

	int n, m; scanf("%d %d", &n, &m);
	int sum = 0;
	for (int i=0; i<m; ++i) {
		int u, v, a, b; scanf("%d %d %d %d", &u, &v, &a, &b);
		if (u == v) { continue; }
		e[ef].v = v; e[ef].a = a; e[ef].b = b;
		e[ef].nxt = adj[u]; adj[u] = ef++;
		e[ef].v = u; e[ef].a = a; e[ef].b = b;
		e[ef].nxt = adj[v]; adj[v] = ef++;
		sum += a;
	}

	double l = 0, r = sum;
	int A, B;
	for (int i=0; i<60; ++i) {
		double mid = (l + r) / 2.0;
		int asum, bsum;
		if (check(mid, n, asum, bsum)) {
			l = mid;
			A = asum, B = bsum;
		} else {
			r = mid;
		}
	}

	printf("%d/%d\n", A, B);
	return 0;
}
