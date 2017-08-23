#include <bits/stdc++.h>
using namespace std;

#define MAXN 200

// u, r, d, l
const int shift[4] = { 0, 1, 2, 3 };
const int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int state[MAXN][MAXN];

inline int cd2idx(char d) {
	switch (d) {
		case 'u': return 0;
		case 'r': return 1;
		case 'd': return 2;
		default: return 3;
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	int cur_d = 2, x = 0, y = 0;
	memset(state, 0, sizeof(state));
	for (int i=2*n*m-1; i>0; --i) {
		int s[3]; char cd;
		scanf("%d %d %d %c", &s[0], &s[1], &s[2], &cd);
		int d = cd2idx(cd), ts = 0;
		for (int i=0; i<3; ++i) { ts |= s[i] << ((i + shift[cur_d]) % 4); }
		state[x][y] |= ts;
		cur_d = d;
		x += dir[d][0]; y += dir[d][1];
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) { printf("+%c", (state[i][j] & 0x2) ? '-' : ' '); }
		printf("+\n");
		for (int j=0; j<m; ++j) { printf("%c ", (state[i][j] & 0x1) ? '|' : ' '); }
		printf("%c\n", (state[i][m-1] & 0x4) ? '|' : ' ');
	}

	for (int i=0; i<m; ++i) {
		printf("+%c", (state[n-1][i] & 0x8) ? '-' : ' ');
	}
	printf("+\n");
	return 0;
}
