#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1000
#define INF 100000

struct Split {
	int two, five, move;
} dp[MAXN+1][MAXN+1][3];
char buff[MAXN*2];

const int divi[2] = { 2, 5 };

int main() {
	int n; scanf("%d", &n);

	memset(dp, 0x70, sizeof(dp));
	dp[1][0][0].two = dp[1][0][0].five = 0;
	dp[1][0][1].two = dp[1][0][1].five = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			int v; scanf("%d", &v);
			if (v == 0) {
				// if there's zero value, we're sure that
				// the answer will be no more that 1, as
				// anything multiplied by zero is zero.
				// but to try out other combination, set
				// the value to be INF to avoid using it.
				dp[i][j][0] = { INF, INF, 0 };
				dp[i][j][1] = { INF, INF, 0 };
				dp[i][j][2] = { -1, -1, ((i==1) ? 0 : 1) };
				continue;
			}

			int s[2] = { 0, 0 };
			for (int k=0; k<2; ++k) {
				while (v % divi[k] == 0) {
					v /= divi[k]; ++s[k];
				}
			}

			if (dp[i][j-1][2].two == -1 || dp[i-1][j][2].two == -1) {
				dp[i][j][2] = { -1, -1, (dp[i][j-1][2].two == -1) ? 0 : 1 };
			} else {
				dp[i][j][2].move = (i == 1) ? 0 : 1;
			}

			if (dp[i][j-1][0].two < dp[i-1][j][0].two) {
				dp[i][j][0].two = dp[i][j-1][0].two + s[0];
				dp[i][j][0].five = dp[i][j-1][0].five + s[1];
				dp[i][j][0].move = 0; // R
			} else if (dp[i][j-1][0].two > dp[i-1][j][0].two) {
				dp[i][j][0].two = dp[i-1][j][0].two + s[0];
				dp[i][j][0].five = dp[i-1][j][0].five + s[1];
				dp[i][j][0].move = 1; // D
			} else {
				dp[i][j][0].two = dp[i-1][j][0].two + s[0];
				if (dp[i][j-1][0].five < dp[i-1][j][0].five) {
					dp[i][j][0].five = dp[i][j-1][0].five + s[1];
					dp[i][j][0].move = 0; // R
				} else {
					dp[i][j][0].five = dp[i-1][j][0].five + s[1];
					dp[i][j][0].move = 1; // D
				}
			}

			if (dp[i][j-1][1].five < dp[i-1][j][1].five) {
				dp[i][j][1].two = dp[i][j-1][1].two + s[0];
				dp[i][j][1].five = dp[i][j-1][1].five + s[1];
				dp[i][j][1].move = 0; // R
			} else if (dp[i][j-1][1].five > dp[i-1][j][1].five) {
				dp[i][j][1].two = dp[i-1][j][1].two + s[0];
				dp[i][j][1].five = dp[i-1][j][1].five + s[1];
				dp[i][j][1].move = 1; // D
			} else {
				dp[i][j][1].five = dp[i][j-1][1].five + s[1];
				if (dp[i][j-1][1].two < dp[i-1][j][1].two) {
					dp[i][j][1].two = dp[i][j-1][1].two + s[1];
					dp[i][j][1].move = 0; // R
				} else {
					dp[i][j][1].two = dp[i-1][j][1].two + s[1];
					dp[i][j][1].move = 1; // D
				}
			}
		}
	}

	int mn = 0x7fffffff, id;
	int two = min(dp[n][n][0].two, dp[n][n][0].five);
	int five = min(dp[n][n][1].two, dp[n][n][1].five);
	if (two > five) {
		id = 1;
		mn = five;
	} else {
		id = 0;
		mn = two;
	}

	if (dp[n][n][2].two == -1 && 1 < mn) {
		id = 2;
		mn = 1;
	}

	buff[2*n-2] = 0;
	int x = n, y = n, cur = 2*n-3;
	while (x != 1 || y != 1) {
		if (dp[x][y][id].move == 0) {
			buff[cur--] = 'R';
			--y;
		} else {
			buff[cur--] = 'D';
			--x;
		}
	}

	printf("%d\n%s\n", mn, buff);
	return 0;
}
