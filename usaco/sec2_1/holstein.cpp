/*
ID: cenhao11
PROG: holstein
LANG: C++11
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXV 25
#define MAXG 15

int required[MAXV];
int vitamin[MAXG][MAXV];
int current[MAXV];

int choose[MAXV];

void add(int *cur, int *vit, int num) {
	for (int i=0; i<num; ++i) {
		cur[i] += vit[i];
	}
}

void sub(int *cur, int *vit, int num) {
	for (int i=0; i<num; ++i) {
		cur[i] -= vit[i];
	}
}

bool check(int *cur, int *req, int num)
{
	for (int i=0; i<num; ++i) {
		if (cur[i] < req[i]) { return false; }
	}

	return true;
}

void dfs(int start, int end, int num, int depth, int *mn, int *cur, int (*vit)[MAXV], int *req, int *tmp) {
	for (int i=start; i<end; ++i) {
		tmp[depth] = i;
		add(cur, vit[i], num);
		if (check(cur, req, num)) {
			if (depth + 1< *mn) {
				*mn = depth + 1;
				memcpy(choose, tmp, sizeof(int)*(*mn));
			}
		} else {
			dfs(i+1, end, num, depth+1, mn, cur, vit, req, tmp);
		}
		sub(cur, vit[i], num);
	}
}

int main() {
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);

	int v, g;
	memset(current, 0, sizeof(current));

	scanf("%d", &v);
	for (int i=0; i<v; ++i) { scanf("%d", &required[i]); }

	scanf("%d", &g);
	for (int i=0; i<g; ++i) {
		for (int j=0; j<v; ++j) { scanf("%d", &vitamin[i][j]); }
	}

	int tmp[MAXV];
	int mn = 0x7fff0000;
	dfs(0, g, v, 0, &mn, current, vitamin, required, tmp);
	printf("%d", mn);
	for (int i=0; i<mn; ++i) { printf(" %d", choose[i] + 1); }
	printf("\n");

	return 0;
}
