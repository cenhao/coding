/*
ID: cenhao11
PROG: milk3
LANG: C++11
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MILK 21

const int full = MILK - 1;
bool visit[MILK * MILK * MILK];
bool cVol[MILK];
int outCnt, A, B, C;

void dfs(int a, int b, int c) {
	int key = a + b * MILK + c * MILK * MILK;
	if (visit[key]) { return; }

	visit[key] = true;
	if (!cVol[c] && a==0) {
		cVol[c] = true;
		if ((++outCnt) == C+1) { return; }
	}

	int toA, toB, toC;
	if (a != 0) {
		toB = min(B-b, a);
		toC = min(C-c, a);
		if (toB != 0) { dfs(a-toB, b+toB, c); }
		if (toC != 0) { dfs(a-toC, b, c+toC); }
	}
	if (b != 0) {
		toA = min(A-a, b);
		toC = min(C-c, b);
		if (toA != 0) { dfs(a+toA, b-toA, c); }
		if (toC != 0) { dfs(a, b-toC, c+toC); }
	}
	if (c != 0) {
		toA = min(A-a, c);
		toB = min(B-b, c);
		if (toA != 0) { dfs(a+toA, b, c-toA); }
		if (toB != 0) { dfs(a, b+toB, c-toB); }
	}
}

int main() {
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);

	while (EOF != scanf("%d%d%d", &A, &B, &C)) {
		memset(visit, 0, sizeof(visit));
		memset(cVol, 0, sizeof(cVol));
		outCnt = 0;

		dfs(0, 0, C);

		for (int i=0; i<MILK; ++i) {
			if (cVol[i]) {
				printf("%d%c", i, ((outCnt--) == 1) ? '\n' : ' ');
			}
		}
	}
}
