#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
#define MAXS 401
#define OFF 200
#define MAXK 20

const int cha[2][3] = { { 0, 4, 7}, { 0, 3, 7 } };

int song[3*MAXN+1];
int dist[MAXN+1][MAXS][2];
int dp[MAXN+1][MAXS][2][MAXK+1];
int adp[MAXN+1][MAXK+1];

int main() {
	int n, K; scanf("%d%d", &n, &K);
	for (int i=1; i<=3*n; ++i) { scanf("%d", &song[i]); }

	for (int i=1; i<=n; ++i) {
		for (int j=0; j<MAXS; ++j) {
			for (int k=0; k<2; ++k) {
				dist[i][j][k] = 0;
				for (int l=0; l<3; ++l) {
					dist[i][j][k] += abs(song[3*(i-1)+l+1]-(j-OFF+cha[k][l]));
				}
			}
		}
	}

	memset(dp, -1, sizeof(dp));
	memset(adp, -1, sizeof(adp));
	for (int i=0; i<MAXS; ++i) {
		dp[1][i][0][0] = dist[1][i][0];
		dp[1][i][1][0] = dist[1][i][1];

		if (adp[1][0] == -1 || dp[1][i][0][0] < adp[1][0]) {
			adp[1][0] = dp[1][i][0][0];
		}
		if (adp[1][0] == -1 || dp[1][i][1][0] < adp[1][0]) {
			adp[1][0] = dp[1][i][1][0];
		}
	}

	for (int i=2; i<=n; ++i) {
		for (int j=0; j<MAXS; ++j) {
			for (int k=0; k<2; ++k) {
				for (int l=0; l<=K; ++l) {
					if (dp[i-1][j][k][l] >= 0) {
						dp[i][j][k][l] = dp[i-1][j][k][l] + dist[i][j][k];
					}

					if (l>0 && adp[i-1][l-1] >= 0) {
						if (dp[i][j][k][l] == -1 || adp[i-1][l-1]+dist[i][j][k] < dp[i][j][k][l]) {
							dp[i][j][k][l] = adp[i-1][l-1]+dist[i][j][k];
						}
					}

					if (dp[i][j][k][l] >= 0) {
						if (adp[i][l] == -1 || dp[i][j][k][l] < adp[i][l]) {
							adp[i][l] = dp[i][j][k][l];
						}
					}
				}
			}
		}
	}

	int mn = -1;
	for (int i=0; i<=K; ++i) {
		if (mn <= 0 || (adp[n][i] >=0 && adp[n][i] < mn)) {
			mn = adp[n][i];
		}
	}

	printf("%d\n", mn);
	return 0;
}
