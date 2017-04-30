#include <bits/stdc++.h>
using namespace std;

#define MAXN 300000

struct Edge {
	int v;
	int nxt;
} e[MAXN*2+2];

int adj[MAXN+1];
int w[MAXN+1];
int pmx[MAXN+1], cpmx[MAXN+1]; // positive mx, connected positive mx
int nmn[MAXN+1], cnmn[MAXN+1]; // negative mn, connected negative mn

void dfs_1(int cur, int par) {
	pmx[cur] = cpmx[cur] = nmn[cur] = cnmn[cur] = 0;

	for (int i=adj[cur]; i!=-1; i=e[i].nxt) {
		if (e[i].v == par) { continue; }
		int v = e[i].v;
		dfs_1(v, cur);
		pmx[cur] = max(pmx[cur], pmx[v]);
		cpmx[cur] += cpmx[v];
		nmn[cur] = min(nmn[cur], nmn[v]);
		cnmn[cur] += cnmn[v];
	}

	cpmx[cur] = max(0, cpmx[cur] + w[cur]);
	pmx[cur] = max(pmx[cur], cpmx[cur]);
	cnmn[cur] = min(0, cnmn[cur] + w[cur]);
	nmn[cur] = min(nmn[cur], cnmn[cur]);
}

int64_t dfs_2(int cur, int par, int ppmx, int pcpmx, int pnmn, int pcnmn) {
	int cpsum = 0, cnsum = 0;
	int ncpmx[2] = {ppmx, 0}, ncpmxi = par;
	int ncnmn[2] = {pnmn, 0}, ncnmni = par;

	for (int i=adj[cur], v; i!=-1; i=e[i].nxt) {
		if ((v = e[i].v) == par) {
			cpsum += pcpmx;
			cnsum += pcnmn;
		} else {
			cpsum += cpmx[v];
			cnsum += cnmn[v];

			if (pmx[v] > ncpmx[0]) {
				ncpmx[1] = ncpmx[0];
				ncpmx[0] = pmx[v]; ncpmxi = v;
			} else if (pmx[v] > ncpmx[1]) {
				ncpmx[1] = pmx[v];
			}

			if (nmn[v] < ncnmn[0]) {
				ncnmn[1] = ncnmn[0];
				ncnmn[0] = nmn[v]; ncnmni = v;
			} else if (nmn[v] < ncnmn[1]) {
				ncnmn[1] = nmn[v];
			}
		}
	}

	int64_t mx = max(int64_t(ncpmx[0]) * ncpmx[1], int64_t(ncnmn[0]) * ncnmn[1]);
	cpsum = max(0, cpsum + w[cur]);
	cnsum = min(0, cnsum + w[cur]);

	for (int i=adj[cur], v; i!=-1; i=e[i].nxt) {
		if ((v=e[i].v) == par) {
			mx = max(mx, max(0, cpsum-pcpmx)*int64_t(ppmx));
			mx = max(mx, min(0, cnsum-pcnmn)*int64_t(pnmn));
		} else {
			int pleft = max(0, cpsum-cpmx[v]);
			int nleft = min(0, cnsum-cnmn[v]);
			mx = max(mx, int64_t(pleft) * pmx[v]);
			mx = max(mx, int64_t(nleft) * nmn[v]);

			int curpmx = max((v==ncpmxi) ? ncpmx[1]:ncpmx[0], pleft);
			int curnmn = min((v==ncnmni) ? ncnmn[1]:ncnmn[0], nleft);
			mx = max(mx, dfs_2(v, cur, curpmx, pleft, curnmn, nleft));
		}
	}

	return mx;
}

int main() {
	memset(adj, -1, sizeof(adj));

	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) { scanf("%d", &w[i]); }
	for (int i=1; i<n; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		int i1 = i*2-1, i2 = i*2;
		e[i1] = { v, adj[u] };
		adj[u] = i1;
		e[i2] = { u, adj[v] };
		adj[v] = i2;
	}

	dfs_1(1, 0);
	int64_t ans = dfs_2(1, 0, 0, 0, 0, 0);
	printf("%" PRId64 "\n", ans);
	return 0;
}
