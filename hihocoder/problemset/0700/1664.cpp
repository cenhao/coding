#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
char mat[MAXN][MAXN+1];
int height[MAXN];
struct QItem { int p, h; } q[MAXN];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) { scanf("%s", mat[i]); }
	int mx = 0;
	memset(height, 0, sizeof(height));
	for (int i=0; i<n; ++i) {
		int h = 0, r = 0;
		for (int j=0; j<m; ++j) {
			height[j] = (i == 0 || mat[i][j] != mat[i-1][j]) ? height[j]+1 : 1;
			if (j == 0 || mat[i][j] == mat[i][j-1]) {
				h = r = 0;
				q[r++] = { j, height[j] };
				mx = max(1, mx);
			} else {
				int tj = j;
				while (h < r && q[r-1].h > height[j]) {
					tj = q[r-1].p;
					--r;
				}
				q[r++] = { tj, height[j] };
				while (h < r && q[h].h+q[h].p <= j) { ++h; }
				mx = max(mx, min(q[h].h, j-q[h].p+1));
			}
		}
	}

	printf("%d\n", mx);
	return 0;
}
