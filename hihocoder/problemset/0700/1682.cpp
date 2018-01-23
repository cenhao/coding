#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
const int mov[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };

char g[MAXN+2][MAXN+2];

int main() {
	memset(g, 0, sizeof(g));
	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i) { scanf("%s", &g[i][1]); }
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (g[i][j] == '*') {
				printf("*");
				continue;
			}
			int tmp = 0;
			for (int k=0; k<8; ++k) {
				int x = i + mov[k][0], y = j + mov[k][1];
				if (g[x][y] == '*') { ++tmp; }
			}
			printf("%d", tmp);
		}
		printf("\n");
	}
}
