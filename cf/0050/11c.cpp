#include <bits/stdc++.h>
using namespace std;

#define MAXN 250
char mat[MAXN+2][MAXN+2];

int get_state(int x, int y) {
	int state = 0;
	for (int i=x-1; i<=x+1; ++i) {
		for (int j=y-1; j<=y+1; ++j) {
			if (mat[i][j] >= '1') { state |= 1<<((i-x+1)*3+(j-y+1)); }
		}
	}
	return state;
}

bool check_para(int x, int y) {
	int lb = x, rt = y;
	while (mat[lb+1][y] == '1') { ++lb; }
	while (mat[x][rt+1] == '1') { ++rt; }
	if (lb - x != rt - y) { return false; }
	for (int i=y; i<=rt; ++i) {
		if (mat[lb][i] != '1') { return false; }
	}
	for (int i=x; i<=lb; ++i) {
		if (mat[i][rt] != '1') { return false; }
	}
	for (int i=x-1; i<=lb+1; ++i) {
		if (mat[i][y-1]>='1' || mat[i][rt+1]>='1') { return false; }
	}
	for (int i=y-1; i<=rt+1; ++i) {
		if (mat[x-1][i]>='1' || mat[lb+1][i]>='1') { return false; }
	}
	if (y+1 < rt && x+1 < lb) {
		for (int i=x+1; i<lb; ++i) {
			if (mat[i][y+1]>='1' || mat[i][rt-1]>='1') { return false; }
		}
		for (int i=y+1; i<rt; ++i) {
			if (mat[x+1][i]>='1' || mat[lb-1][i]>='1') { return false; }
		}
	}

	return true;
}

bool check_rotate(int x, int y) {
	int lx = x, ly = y;
	while (mat[lx+1][ly-1] == '1') { ++lx; --ly; }
	int rx = x, ry = y;
	while (mat[rx+1][ry+1] == '1') { ++rx; ++ry; }
	if (lx - x != rx - x) { return false; }
	int bx = lx, by = ly;
	while (mat[bx+1][by+1] == '1') { ++bx; ++by; }
	if (bx-rx != ry-by) { return false; }
	for (int i=bx, j=by; i!=rx&&j!=ry; --i, ++j) {
		if (mat[i][j] != '1') { return false; }
	}

	int len = rx - x + 1;
	for (int i=0; i<=len; ++i) {
		if (mat[x-1+i][y+i]>='1' || mat[lx+i][ly-1+i]>='1') { return false; }
		if (mat[x-1+i][y-i]>='1' || mat[rx+i][ry+1-i]>='1') { return false; }
	}
	for (int i=1; i<=len; ++i) {
		if (mat[x-2+i][y+i]>='1' || mat[lx+i][ly-2+i]>='1') { return false; }
		if (mat[x-2+i][y-i]>='1' || mat[rx+i][ry+2-i]>='1') { return false; }

	}
	for (int i=1; i<len; ++i) {
		if (mat[x+i][y-1+i]>='1' || mat[lx-1+i][ly+i]>='1') { return false; }
		if (mat[x+i][y+1-i]>='1' || mat[rx-1+i][ry-i]>='1') { return false; }
	}
	for (int i=2; i<len; ++i) {
		if (mat[x+i][y-2+i]>='1' || mat[lx-2+i][ly+i]>='1') { return false; }
		if (mat[x+i][y+2-i]>='1' || mat[rx-2+i][ry-i]>='1') { return false; }
	}

	return true;
}

int process(int n, int m) {
	int ans = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			if (mat[i][j] != '1') { continue; }
			int state = get_state(i, j);
			if (state == 0x1b0 || state == 0xb0) {
				if (check_para(i, j)) { ++ans; }
			} else if (state == 0x150) {
				if (check_rotate(i, j)) { ++ans; }
			}
		}
	}

	return ans;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d%d", &n, &m);
		memset(mat, 0, sizeof(mat));
		for (int i=1; i<=n; ++i) { scanf("%s", &mat[i][1]); }
		printf("%d\n", process(n, m));
	}

	return 0;
}
