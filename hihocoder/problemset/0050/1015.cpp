#include <stdio.h>
#include <string.h>

#define MAXP 10000
#define MAXT 1000000

char pattern[MAXP + 1];
char text[MAXT + 1];

int fail[MAXP];

void preprocess() {
	int pi = -1;
	fail[0] = -1;

	for (int ti=1, len=strlen(pattern); ti<len; ++ti) {
		while (pattern[pi+1] != pattern[ti] && pi >= 0) { pi = fail[pi]; }
		if (pattern[pi+1] == pattern[ti]) ++pi;
		fail[ti] = pi;
	}
}

int kmp() {
	preprocess();

	int pi = -1, cnt = 0;
	int plen = strlen(pattern);

	for (int ti=0, len=strlen(text); ti<len; ++ti) {
		while (pattern[pi+1] != text[ti] && pi >= 0) { pi = fail[pi]; }
		if (pattern[pi+1] == text[ti]) ++pi;
		if (pi == plen-1) {
			++cnt;
			pi = fail[pi];
		}
	}

	return cnt;
}

int main() {
	int n;
	scanf("%d\n", &n);

	for (int c=0; c<n; ++c) {
		scanf("%s", pattern);
		scanf("%s", text);
		printf("%d\n", kmp());
	}
}
