#include <algorithm>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 1000005
char str[MAXL];
char buff[MAXL*2];
int dp[MAXL*2];

int main() {
	int n;
	scanf("%d", &n);
	fgets(str, sizeof(str), stdin);

	for (int cn=0; cn<n; ++cn) {
		fgets(str, sizeof(str), stdin);
		size_t len = strlen(str) - 1;//remove newline
		size_t end = len * 2 + 1;

		//preprocess str to buff
		buff[0] = 0;
		for (size_t i=0; i<len; ++i) {
			buff[i*2+1] = 1;
			buff[i*2+2] = str[i];
		}
		buff[end] = 1;

		//solve with dp
		memset(dp, -1, sizeof(dp));
		dp[0] = dp[1] = 0;
		int mx = 1; int pos = 1;
		for (int i=2; i<=end; ++i) {
			for (int j=pos; j<i; ++j) {
				if (dp[j] < 0) {
					if (j <= mx) { dp[j] = min(mx-j, dp[(pos<<1)-j]); }
				}

				if ((dp[j]+j==i-1) && (buff[i]==buff[j-dp[j]-1])) {
					mx = i; pos = j;
					dp[j] += 1;
					break;
				}
			}

			if (mx < i) {
				mx = i;
				pos = i;
				dp[i] = 0;
			}
		}

		int ret = -1;
		for (int i=0; i<=end; ++i) {
			ret = max(ret, dp[i]);
		}

		printf("%d\n", (ret*2+1)/2);
	}

	return 0;
}
