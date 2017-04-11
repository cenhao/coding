#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int dp[MAXN][MAXN+1];
char instr[MAXN+1];

int main() {
	scanf("%s", instr);
	int len = strlen(instr);
	for (int i=0; i<=len; ++i) {
		for (int j=0; j+i<=len; ++j) {
			if (i <= 1) { dp[j][i] = 0; }
			else {
				if (instr[j] == instr[j+i-1]) {
					dp[j][i] = dp[j+1][i-2];
				} else {
					dp[j][i] =
						min(dp[j+1][i-2], min(dp[j][i-1], dp[j+1][i-1])) + 1;
				}
			}
		}
	}

	printf("%d\n", dp[0][len]);
	return 0;
}
