#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define OFF(x) (x+MAXN+5)

const int mov[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool vis[2*MAXN+10][2*MAXN+10];
char steps[MAXN+1];

inline int d2n(char c) {
	switch (c) {
		case 'U': return 0;
		case 'L': return 1;
		case 'D': return 2;
		case 'R': return 3;
	}
}

int main() {
	scanf("%s", steps);
	int len = strlen(steps);
	memset(vis, 0, sizeof(vis));
	int x = OFF(0), y = OFF(0);
	vis[x][y] = true;
	bool possible = true;
	for (int i=0; i<len; ++i) {
		int d = d2n(steps[i]);
		x += mov[d][0]; y += mov[d][1];
		bool check = vis[x][y];
		if (!check) {
			int cnt = 0;
			for (int j=0; j<4; ++j) {
				int xx = x + mov[j][0], yy = y + mov[j][1];
				if (vis[xx][yy]) { ++cnt; }
				check = (cnt > 1);
			}
		}

		if (check) {
			possible = false;
			break;
		}

		vis[x][y] = true;
	}

	printf("%s\n", possible ? "OK" : "BUG");
	return 0;
}
