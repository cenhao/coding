#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXN 100
#define INF 0x7fff0000

int n, m;
int lmap[MAXN+1][MAXN+1];
int mx[MAXN+1];
int mn[MAXN+1];
int order[MAXN];

void read() {
	scanf("%d", &n);
	memset(lmap, 0, sizeof(lmap));
	int a, b;
	for (int i=1; i<n; ++i) {
		scanf("%d %d", &a, &b);
		lmap[a][++lmap[a][0]] = b;
		lmap[b][++lmap[b][0]] = a;
	}

	scanf("%d", &m);
	memset(order, 0, sizeof(order));
	for (int i=0; i<m; ++i) {
		int k;
		scanf("%d", &k);
		order[k] = i + 1;
	}
}

bool dfs(int cur, int parent) {
	int nxt;
	int lmx = 0, lmn = INF;
	for (int i=1; i<=lmap[cur][0]; ++i) {
		nxt = lmap[cur][i];
		if (nxt == parent) { continue; }
		if (!dfs(nxt, cur)) { return false; }
		if (mn[nxt] != 0 && mx[nxt] != 0) {
			lmx = max(mx[nxt], lmx);
			lmn = min(mn[nxt], lmn);
		}
	}

	if (order[cur] != 0) {
		if (lmn < INF) {
			if (order[cur] > lmn) { return false; }
			mn[cur] = order[cur];
			mx[cur] = lmx;
		} else {
			mx[cur] = mn[cur] = order[cur];
		}
	} else if (order[cur] == 0) {
		if (lmn < INF) {
			mn[cur] = lmn;
			mx[cur] = lmx;
		} else {
			mx[cur] = mn[cur] = 0;
		}
	}

	for (int i=1; i<=lmap[cur][0]; ++i) {
		nxt = lmap[cur][i];
		if (nxt == parent) { continue; }
		if (mx[nxt] == 0 || mn[nxt] == 0) { continue; }
		for (int i2=i+1; i2<=lmap[cur][0]; ++i2) {
			int nxt2 = lmap[cur][i2];
			if (nxt2 == parent || mx[nxt2] == 0 || mn[nxt2] == 0) { continue; }
			if (!((mx[nxt] < mn[nxt2]) || (mx[nxt2] < mn[nxt]))) { return false; }
		}
	}

	return true;
}

bool possible() {
	return dfs(1, 0);
}

int main() {
	int t;
	for (scanf("%d", &t); t>0; --t) {
		read();
		printf(possible() ? "YES\n" : "NO\n");
	}
}
