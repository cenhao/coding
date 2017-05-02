#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

bool mat[MAXN+1][MAXN+1];
int score[MAXN+1];
bool reco[MAXN+1];
int dp[MAXN+1][MAXN+1];
int tmp[MAXN+1];

bool dfs_1(int cur, int par, int n, int &cnt) {
	mat[cur][par] = false; // remove c-p link
	for (int i=1; i<=n; ++i) {
		if (!mat[cur][i]) { continue; }
		reco[cur] |= dfs_1(i, cur, n, cnt);
	}

	if (reco[cur]) {
		mat[par][cur] = false; // disconnect from p
		++cnt;
		if (cur != 1) { score[1] += score[cur]; }
		for (int i=1; i<=n; ++i) {
			if (mat[cur][i]) {
				mat[cur][i] = false;
				mat[1][i] = true;
			}
		}
	}

	return reco[cur];
}

int dfs_2(int cur, int n) {
	int mxcnt = 1;
	dp[cur][1] = score[cur];
	for (int i=1; i<=n; ++i) {
		if (!mat[cur][i]) { continue; }
		int cnt = dfs_2(i, n);
		for (int j=1; j<=n; ++j) { tmp[j] = dp[cur][j]; }
		for (int j=cnt; j>=1; --j) {
			for (int k=mxcnt; k>=1; --k) {
				tmp[k+j] = max(tmp[k+j], dp[cur][k]+dp[i][j]);
			}
		}
		for (int j=1; j<=n; ++j) { dp[cur][j] = tmp[j]; }
		mxcnt += cnt;
	}

	return mxcnt;
}

int main() {
	memset(mat, false, sizeof(mat));
	memset(reco, false, sizeof(reco));

	int n, k, m; scanf("%d %d %d", &n, &k, &m);
	for (int i=1; i<=n; ++i) { scanf("%d", &score[i]); }
	for (int i=0; i<k; ++i) {
		int v; scanf("%d", &v);
		reco[v] = true;
	}

	for (int i=1; i<n; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		mat[u][v] = mat[v][u] = true;
	}

	if (k > m) {
		printf("-1\n");
		return 0;
	}

	int cnt = 0;
	dfs_1(1, 0, n, cnt);
	if (cnt > m) {
		printf("-1\n");
		return 0;
	}

	memset(dp, 0, sizeof(dp));
	dfs_2(1, n);
	printf("%d\n", dp[1][m-cnt+1]);
	return 0;
}
