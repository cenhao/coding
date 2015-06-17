/*
ID: cenhao11
PROG: barn1
LANG: C++11
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXS 205

int gaps[MAXS];
int cowidx[MAXS];

int main()
{
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);

	int m, s, c;

	while (EOF != scanf("%d %d %d\n", &m, &s, &c)) {
		for (int i=0; i<c; ++i) { scanf("%d", &cowidx[i]); }
		sort(cowidx, cowidx+c);
		for (int i=1; i<c; ++i) { gaps[i-1] = cowidx[i] - cowidx[i-1] - 1; }
		sort(gaps, gaps+c-1, greater<int>());
		int sum = 0;
		int end = min(m-1, c-1);
		for (int i=0; i<end; ++i) { sum += gaps[i]; }
		printf("%d\n", cowidx[c-1] - cowidx[0] + 1 - sum);
	}

	return 0;
}
