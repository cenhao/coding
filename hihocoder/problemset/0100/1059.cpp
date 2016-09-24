#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>

#define MAXS 2100

char stra[MAXS+1];
char strb[MAXS+1];

int f[MAXS+1][MAXS+1];
// dp[x][y][1] is the maximum with x, y as the last character of the last
// substring.
// dp[x][y][0] is the maximum
int dp[MAXS+1][MAXS+1][2];

int process() {
	memset(dp, 0, sizeof(dp));
	memset(f, 0, sizeof(f));
	int lena = strlen(stra);
	int lenb = strlen(strb);

	for (int i=1; i<=lena; ++i) {
		for (int j=1; j<=lenb; ++j) {
			f[i][j] = (stra[i-1] == strb[j-1]) ? 1+f[i-1][j-1] : 0;
			if (f[i][j] >= 3) {
				dp[i][j][1] = dp[i-3][j-3][0] + 3;
				if (f[i][j] > 3) {
					dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][1]+1);
				}
			}

			dp[i][j][0] = max(dp[i][j][1], max(dp[i-1][j][0], dp[i][j-1][0]));
		}
	}

	return dp[lena][lenb][0];
}

int main() {
	scanf("%s", stra); scanf("%s", strb);
	printf("%d\n", process());
	return 0;
}
