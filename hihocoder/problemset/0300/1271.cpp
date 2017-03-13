#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
using namespace std;

#define MAXN 4
#define MAXT 1000

int A[MAXN][MAXN];
struct Slot {
	int val, row;
} AA[MAXN*MAXN];
int B[MAXT];
int C[MAXT];

int main() {
	int q; scanf("%d", &q);
	while (q--) {
		int n, m, t, s; scanf("%d %d %d %d", &n, &m, &t, &s);
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				scanf("%d", &A[i][j]);
				AA[i*m+j].val = A[i][j];
				AA[i*m+j].row = i;
			}
		}

		memset(B, 0, sizeof(B));
		for (int i=0; i<t; ++i) { scanf("%d", &B[i]); }
		sort(B, B+t, greater<int>());

		memset(C, 0, sizeof(C));
		for (int i=0; i<t; ++i) { scanf("%d", &C[i]); }
		sort(C, C+t, greater<int>());

		sort(AA, AA+n*m, [](const Slot& s1, const Slot& s2) -> bool {
			return s1.val > s2.val;
		});

		int slot = n*m, mx = -1;
		bool found = false;
		for (int state=0, estate=1<<slot; state<estate; ++state) {
			int S = 0, D = 0, mark = 0;
			int scnt = 0, dcnt = 0;
			for (int i=0; i<slot; ++i) {
				if (state & (1 << i)) {
					S += AA[i].val * B[scnt++];
				} else {
					if (C[dcnt] == 0) { continue; }
					D += AA[i].val * C[dcnt++];
					mark |= 1 << AA[i].row;
				}
			}

			if (S >= s) {
				if (D >= mx) {
					if (D > mx) { found = false; }
					mx = D;
					if (!found) {
						found = (mark == ((1<<n) - 1));
					}
				}
			}
		}

		if (mx < 0) {
			printf("Not Exist\n");
			continue;
		}

		printf("%d\n", mx);
		printf("%s\n", found ? "Yes" : "No");
	}

	return 0;
}
