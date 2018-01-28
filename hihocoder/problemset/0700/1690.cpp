#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
char str[MAXN+1];

int main() {
	scanf("%s", str);
	int len = strlen(str);
	int dp[26]; memset(dp, 0, sizeof(dp));
	for (int i=0; i<len; ++i) {
		int idx = str[i] - 'a';
		if (str[i] == 'a') {
			++dp[idx];
		} else if (str[i] == 'e') {
			dp[idx] = max(dp[0], dp[idx])+1;
		} else if (str[i] == 'i') {
			dp[idx] = max(dp[0], max(dp['e'-'a'], dp[idx])) + 1;
		} else if (str[i] == 'o') {
			++dp[idx];
		} else {
			dp[idx] = max(dp['o'-'a'], dp[idx]) + 1;
		}
	}

	int aeimx = max(dp[0], max(dp['e'-'a'], dp['i'-'a']));
	int oumx = max(dp['o'-'a'], dp['u'-'a']);

	printf("%d\n", aeimx+oumx);
	return 0;
}
