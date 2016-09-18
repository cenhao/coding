#include <algorithm>
using namespace std;
#include <stdio.h>
#include <string.h>

#define MAXS 1000

char str[MAXS+1];
int dp[MAXS][MAXS];

int main() {
	while (EOF != scanf("%s", str)) {
		memset(dp, 0, sizeof(dp));
		int len = strlen(str);
		for (int i=0; i<len; ++i) { dp[i][0] = 0; dp[i][1] = 1; }
		for (int i=2; i<=len; ++i) {
			for (int i2=len-i; i2>=0; --i2) {
				dp[i2][i] = (str[i2] == str[i2+i-1]) ?
					dp[i2+1][i-2] + 2 : max(dp[i2][i-1], dp[i2+1][i-1]);
			}
		}

		printf("%d\n", len - dp[0][len]);
	}

	return 0;
}
