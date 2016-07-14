/*
ID: cenhao11
PROG: hamming
LANG: C++11
*/

#include <stdio.h>
#include <string.h>

#define MAXNUM (1 << 8)
#define CHUNK_SIZE (MAXNUM >> 5)

int hammingAway[MAXNUM][CHUNK_SIZE];
int pick[MAXNUM];

int hammingWeightWithin8Bits(int num) {
	int cnt = 0;
	for (int i=0; i<8; ++i) {
		if (num & (1 << i)) { ++cnt; }
	}

	return cnt;
}

void preprocess(int b, int d) {
	memset(hammingAway, 0, sizeof(hammingAway));
	int end = 1 << b;
	for (int i=0; i<end; ++i) {
		for (int j=i+1; j<end; ++j) {
			if (hammingWeightWithin8Bits(i ^ j) >= d) {
				hammingAway[i][j >> 5] |= 1 << (j & 31);
			}
		}
	}
}

bool check(int num, int *pick, int cnt) {
	int idx = num >> 5;
	int mask = 1 << (num & 31);

	for (int i=0; i<cnt; ++i) {
		if ((mask & hammingAway[pick[i]][idx]) == 0) { return false; }
	}

	return true;
}

bool dfs(int *pick, int start, int end, int cnt, int req)
{
	if (cnt == req) { return true; }
	int stop = end - req + cnt + 1;
	for (int i=start; i<stop; ++i) {
		if (check(i, pick, cnt)) {
			pick[cnt] = i;
			if (dfs(pick, i+1, end, cnt+1, req)) { return true; }
		}
	}

	return false;
}

int main() {
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);

	int n, b, d;
	scanf("%d %d %d", &n, &b, &d);
	preprocess(b, d);
	dfs(pick, 0, 1 << b, 0, n);

	for (int i=0; i<n; ++i) {
		if (i != 0 && i % 10 == 0) {
			printf("\n");
		} else if (i != 0) {
			printf(" ");
		}
		printf("%d", pick[i]);
	}

	printf("\n");
	return 0;
}
