/*
 * hiho code 1032
 * Longest palindrome - redo
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXL 1000000

char str[MAXL+1];
char pstr[MAXL*2+2]; // processed str

// if the longest palindrome centered at i is X(si)X, dp[i] = len(X)
int dp[MAXL*2+2];
int center; // the center of latest found palidrome

void process() {
	int len = strlen(str);
	pstr[0] = 0; pstr[2*len+1] = 1;
	for (int i=0; i<len; ++i) {
		pstr[i*2+1] = 1; pstr[i*2+2] = str[i];
	}

	memset(dp, -1, sizeof(dp));
	dp[0] = dp[1] = 0;
	center = 1;

	for (int i=2, end=2*len+1; i<=end; ++i) {
		int j;
		for (j=center; j<i; ++j) {
			if (dp[j] < 0) {
				dp[j] = min(i-1-j, dp[center+center-j]);
			}

			if (dp[j]+j+1 == i && pstr[j+j-i] == pstr[i]) {
				center = j;
				++dp[j];
				break;
			}
		}

		if (j >= i) {
			dp[i] = 0;
			center = i;
		}
	}

	int mx = -1;
	for (int i=1, end=2*len+1; i<=end; ++i) {
		mx = max(mx, dp[i]);
	}

	printf("%d\n", mx);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%s", str);
		process();
	}

	return 0;
}
