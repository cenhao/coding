#include <bits/stdc++.h>
using namespace std;

#define MAXS 100000

int dp[2][MAXS+1], fail[MAXS+1];
char s[MAXS+1], t[MAXS+1];

int main() {
	scanf("%s %s", s, t);
	int slen = strlen(s), tlen = strlen(t);

	// kmp init
	fail[0] = -1;
	for (int i=1, pos=-1; i<tlen; ++i) {
		while (pos != -1 && t[pos+1] != t[i]) { pos = fail[pos]; }
		if (t[pos+1] == t[i]) { ++pos; }
		fail[i] = pos;
	}

	memset(dp[1], -1, sizeof(int)*(1+tlen));
	dp[1][0] = 0;

	for (int i=0; i<slen; ++i) {
		int cur = i & 1; int pre = cur ^ 1;
		memset(dp[cur], -1, sizeof(int)*(1+tlen));

		// try to match the next character
		dp[cur][0] = dp[pre][0];
		for (int j=0; j<tlen; ++j) {
			dp[cur][0] = max(dp[cur][0], dp[pre][j+1]);
			if (s[i] == t[j] || s[i] == '?') { dp[cur][j+1] = dp[pre][j]; }
		}

		// if a new `t` was formed with last character, then we need to leverage
		// this to handle the overlapped case.
		if (dp[pre][tlen] >= 0) {
			int fp = fail[tlen-1];
			while (true) {
				if (s[i] == '?' || s[i] == t[fp+1]) {
					dp[cur][fp+1+1] = max(dp[cur][fp+1+1], dp[pre][tlen]);
				}
				if (fp == -1) { break; }
				fp = fail[fp];
			}
		}

		// a new `t` is formed
		if (s[i] == t[tlen-1] || s[i] == '?') {
			if (dp[cur][tlen] >= 0) { ++dp[cur][tlen]; }
		}
	}

	int cur = (slen-1) & 1, mx = -1;
	for (int i=0; i<=tlen; ++i) { mx = max(mx, dp[cur][i]); }

	printf("%d\n", mx);
	return 0;
}
