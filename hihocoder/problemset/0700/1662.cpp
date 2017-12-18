#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
int mat[MAXN][MAXN];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	int ans = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			scanf("%d", &mat[i][j]);
			if (i < 2 || j < 2) { continue; }
			int rsum[3] = { 0, 0, 0 };
			int csum[3] = { 0, 0, 0 };
			int dsum = 0, rdsum = 0;
			for (int a=0; a<3; ++a) {
				for (int b=0; b<3; ++b) {
					rsum[a] += mat[i-a][j-b];
					csum[b] += mat[i-a][j-b];
					if (a == b) { dsum += mat[i-a][j-b]; }
					if (a+b == 2) { rdsum += mat[i-a][j-b]; }
				}
			}

			bool ok = true;
			for (int a=0; a<3 && ok; ++a) {
				ok &= (rsum[0] == rsum[a]);
				ok &= (rsum[a] == csum[a]);
			}

			if (ok && dsum == rdsum && rsum[0] == dsum) {
				++ans;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
