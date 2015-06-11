/*
ID: cenhao11
PROG: transform
LANG: C++
*/

#include <stdio.h>

#define MAXN 10

char src[MAXN][MAXN];
char dst[MAXN][MAXN];

typedef bool CmpFunc(int x, int y, int n);

inline bool CmpRotate90(int x, int y, int n)
{
	return src[x][y] == dst[y][n-x-1];
}

inline bool CmpRotate180(int x, int y, int n)
{
	return src[x][y] == dst[n-x-1][n-y-1];
}

inline bool CmpRotate270(int x, int y, int n)
{
	return src[x][y] == dst[n-y-1][x];
}

inline bool CmpReflection(int x, int y, int n)
{
	return src[x][y] == dst[x][n-y-1];
}

inline bool CmpRefAndR90(int x, int y, int n)
{
	return src[x][y] == dst[n-y-1][n-x-1];
}

inline bool CmpRefAndR180(int x, int y, int n)
{
	return src[x][y] == dst[n-x-1][y];
}

inline bool CmpRefAndR270(int x, int y, int n)
{
	return src[x][y] == dst[y][x];
}

inline bool CmpNoChange(int x, int y, int n)
{
	return src[x][y] == dst[y][x];
}

int CmpFramework(int n, CmpFunc cmpFunc)
{
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (!cmpFunc(i, j, n)) { return 0; }
		}
	}

	return 1;
}

int main()
{
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);

	int n;
	char newline;

	while (EOF != scanf("%d\n", &n)) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) { scanf("%c", &src[i][j]); }
			scanf("%c", &newline);
		}

		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) { scanf("%c", &dst[i][j]); }
			scanf("%c", &newline);
		}

		if (CmpFramework(n, CmpRotate90)) { printf("%d\n", 1); }
		else if (CmpFramework(n, CmpRotate180)) { printf("%d\n", 2); }
		else if (CmpFramework(n, CmpRotate270)) { printf("%d\n", 3); }
		else if (CmpFramework(n, CmpReflection)) { printf("%d\n", 4); }
		else if (CmpFramework(n, CmpRefAndR90)) { printf("%d\n", 5); }
		else if (CmpFramework(n, CmpRefAndR180)) { printf("%d\n", 5); }
		else if (CmpFramework(n, CmpRefAndR270)) { printf("%d\n", 5); }
		else if (CmpFramework(n, CmpNoChange)) { printf("%d\n", 6); }
		else { printf("%d\n", 7); }
	}

	return 0;
}
