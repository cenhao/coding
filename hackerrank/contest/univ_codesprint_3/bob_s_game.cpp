#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

char board[MAXN][MAXN+1];
int sg[MAXN][MAXN];
int bit2int[9] = {0, 0, 1, 0, 2, 0, 0, 0, 3};

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int n; scanf("%d", &n);
		int sgs = 0;
		for (int i=0; i<n; ++i) {
			scanf("%s", board[i]);
			for (int j=0; j<n; ++j) {
				if (board[i][j] == 'X') { continue; }
				int v = 1024;
				if (i>0 && board[i-1][j]!='X') { v |= (1 << sg[i-1][j]); }
				if (j>0 && board[i][j-1]!='X') { v |= (1 << sg[i][j-1]); }
				if (i>0 && j>0 && board[i-1][j-1]!='X') { v |= (1 << sg[i-1][j-1]); }
				v = ~v;
				v &= ~(v-1);
				sg[i][j] = bit2int[v];
				if (board[i][j] == 'K') { sgs ^= sg[i][j]; }
			}
		}

		if (sgs == 0) {
			printf("LOSE\n");
		} else {
			int ans = 0;
			for (int i=0; i<n; ++i) {
				for (int j=0; j<n; ++j) {
					if (board[i][j] != 'K') { continue; }
					int target = sg[i][j] ^ sgs;
					if (i>0 && board[i-1][j]!='X' && sg[i-1][j]==target) { ++ans; }
					if (j>0 && board[i][j-1]!='X' && sg[i][j-1]==target) { ++ans; }
					if (i>0 && j>0 && board[i-1][j-1]!='X' && sg[i-1][j-1]==target) { ++ans; }
				}
			}

			printf("WIN %d\n", ans);
		}
	}

	return 0;
}
