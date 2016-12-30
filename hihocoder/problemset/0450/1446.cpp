#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 500

char matrix[MAXN+2][MAXN+2];
int dp[MAXN+2][MAXN+2][4];

int main() {
	memset(matrix, '0', sizeof(matrix));

	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%s", &matrix[i][1]);
	}

	memset(dp, 0, sizeof(dp));
	int mov[2] = {1, -1};
	int start[2] = {1, n};
	int end[2] = {n+1, 0};

	for (int i=0; i<2; ++i) {
		int a = i << 1, b = (i << 1) +1;
		for (int i1=start[i]; i1!=end[i]; i1+=mov[i]) {
			for (int i2=start[i]; i2!=end[i]; i2+=mov[i]) {
				if (matrix[i1][i2] != '1') { continue; }
				dp[i1][i2][a] = 1+ dp[i1-mov[i]][i2][a];
				dp[i1][i2][b] = 1 + dp[i1][i2-mov[i]][b];
			}
		}
	}

	int mx = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			int mn = min(dp[i][j][0], min(dp[i][j][1],
				  min(dp[i][j][2], dp[i][j][3])));
			mx = max(mn, mx);
		}
	}

	printf("%d\n", max(mx-1, 0));
	return 0;
}
