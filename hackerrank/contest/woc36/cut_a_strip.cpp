#include <bits/stdc++.h>
using namespace std;

#define MAXN 385
#define INF 0x7fffffff

int a[MAXN][MAXN], b[MAXN][MAXN];
int rmx[MAXN][MAXN];
int bmx[MAXN][MAXN][2][2];
int suffix[MAXN][MAXN];

void proc_row_mx(int r, int m, int k) {
	for (int j=0; j<m; ++j) {
		int sm = 0;
		for (int i=j; i>=0; --i) {
			sm += (j-i+1 > k) ? 0 : a[r][i];
			suffix[i][j] = (i==j) ? sm : min(sm, suffix[i+1][j]);
		}
	}

	for (int i=0; i<m; ++i) {
		int mn = INF, rsum = 0;
		for (int j=i; j<m; ++j) {
			rsum += a[r][j];
			mn = min(mn, suffix[i][j]);
			rmx[i][j] = rsum - mn;
		}
	}
}

int proc_block_mx(int r, int m, int k) {
	proc_row_mx(r, m, k);
	int cur = r & 1, pre = (r+1) & 1, mx = -INF;
	for (int i=0; i<m; ++i) {
		int rsum = 0;
		for (int j=i; j<m; ++j) {
			rsum += a[r][j];
			bmx[i][j][cur][0] = bmx[i][j][pre][0] + rsum;
			if (r == 0) {
				bmx[i][j][cur][1] = rmx[i][j];
			} else { 
				bmx[i][j][cur][1] = max(bmx[i][j][pre][1]+rsum, bmx[i][j][pre][0]+rmx[i][j]);
			}

			mx = max(mx, bmx[i][j][cur][1]);

			if (bmx[i][j][cur][0] < 0) {
				bmx[i][j][cur][0] = 0;
				bmx[i][j][cur][1] = max(0, bmx[i][j][cur][1]);
			}
			if (bmx[i][j][cur][1] < 0) {
				bmx[i][j][cur][1] = 0;
			}
		}
	}

	return mx;
}

int proc(int n, int m, int k) {
	memset(bmx, 0, sizeof(bmx));
	int mx = -INF;
	for (int i=0; i<n; ++i) {
		mx = max(mx, proc_block_mx(i, m, k));
	}

	return mx;
}

void rotate(int n, int m) {
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) { b[j][n-i-1] = a[i][j]; }
	}
	for (int i=0; i<m; ++i) {
		for (int j=0; j<n; ++j) { a[i][j] = b[i][j]; }
	}
}

int cutAStrip(int n, int m, int k) {
	int mx = proc(n, m, k);
	rotate(n, m);
	mx = max(mx, proc(m, n, k));
	return mx;
}

int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) { scanf("%d", &a[i][j]); }
	}
	int result = cutAStrip(n, m, k);
	printf("%d\n", result);
    return 0;
}

