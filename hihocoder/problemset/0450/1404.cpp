#include <stdio.h>
#include <string.h>

#define MAXN 15

char board[MAXN+2][MAXN+2]; // can be optimized
int cnt[2][4][MAXN+1][MAXN+1]; // can be optimized
int move[4][2] = {{-1, 0}, {0, -1}, {-1, -1}, {-1, 1}};
bool ok[2];

int main() {
	int t;
	for (scanf("%d", &t); t; --t) {
		memset(board, '.', sizeof(board));
		memset(cnt, 0, sizeof(cnt));
		ok[0] = ok[1] = false;

		for (int i=1; i<=MAXN; ++i) {
			scanf("%s", &board[i][1]);

			for (int i1=1; i1<=MAXN; ++i1) {
				if (board[i][i1] == '.') { continue; }
				int idx = (board[i][i1] == 'B' ? 0 : 1);
				if (ok[idx]) { continue; }

				for (int i2=0; i2<4; ++i2) {
					cnt[idx][i2][i][i1] = cnt[idx][i2][i+move[i2][0]][i1+move[i2][1]] + 1;
					if (cnt[idx][i2][i][i1] >= 5) { ok[idx] = true; }
				}
			}
		}

		printf("%s\n", ok[0] ? (ok[1] ? "Both" : "Black") : (ok[1] ? "White" : "None"));
	}

	return 0;
}
