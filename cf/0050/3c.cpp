#include <bits/stdc++.h>
using namespace std;

#define GET_ID(x) ((x == 'X') ? 0 : 1)

int main() {
	char board[3][16];
	for (int i=0; i<3; ++i) { scanf("%s", board[i]); }

	int cnt[2] = { 0, 0 };
	int h[3][2], v[3][2], d[2], rd[2];
	memset(h, 0, sizeof(h));
	memset(v, 0, sizeof(h));
	memset(d, 0, sizeof(h));
	memset(rd, 0, sizeof(h));

	for (int i=0; i<3; ++i) {
		for (int j=0; j<3; ++j) {
			if (board[i][j] == '.') { continue; }
			int id = GET_ID(board[i][j]);
			++cnt[id];
			++h[i][id]; ++v[j][id];
			if (i == j) { ++d[id]; }
			if (i + j == 2) { ++rd[id]; }
		}
	}

	if (cnt[0] - cnt[1] > 1 || cnt[0] < cnt[1]) {
		printf("illegal\n");
		return 0;
	}

	bool win[2] = { false, false };
	for (int i=0; i<2; ++i) {
		win[i] |= d[i] == 3 || rd[i] == 3;
		for (int j=0; j<3; ++j) { win[i] |= (h[j][i] == 3 || v[j][i] == 3); }
	}

	if ((win[0] && win[1]) ||
		(win[0] && cnt[0] <= cnt[1]) ||
		(win[1] && cnt[0] != cnt[1])) {
		printf("illegal\n");
		return 0;
	}

	if (win[0] || win[1]) {
		printf("the %s player won\n", win[0] ? "first" : "second");
		return 0;
	}

	bool draw = true;
	if ((d[0] == 0 && 4-cnt[1]+d[1]>=3) ||
		(rd[0] == 0 && 4-cnt[1]+rd[1]>=3) ||
		(d[1] == 0 && 5-cnt[0]+d[0]>=3) ||
		(rd[1] == 0 && 5-cnt[0]+d[1])>=3) {
		draw = false;
	}

	int left[2] = { 5, 4 };
	for (int i=0; i<3; ++i) {
		for (int j=0; j<2; ++j) {
			if (h[i][(j+1)&1] == 0 && left[j]-cnt[j]+h[i][j] >= 3) {
				draw = false;
			}
			if (v[i][(j+1)&1] == 0 && left[j]-cnt[j]+v[i][j] >= 3) {
				draw = false;
			}
		}
	}

	if (draw && cnt[0]+cnt[1] != 8) {
		printf("draw\n");
		return 0;
	}

	printf("%s\n", cnt[0] > cnt[1] ? "second" : "first");

	return 0;
}
