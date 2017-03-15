#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 1000
const int mov[4][2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };

int x[MAXN][2], y[MAXN][2];
int cover[MAXN];
bool conn[MAXN][MAXN];

int dfs(int start, int end) {
	if (conn[start][start]) { return 0; }
	conn[start][start] = true;

	int cnt = 1;
	for (int i=start+1; i<end; ++i) {
		if (conn[start][i]) {
			cnt += dfs(i, end);
		}   
	}   

	return cnt;
}

int main() {
	int n, w, h; scanf("%d %d %d", &w, &h, &n);

	memset(cover, 0, sizeof(cover));
	memset(conn, 0, sizeof(conn));
	for (int i=0; i<n; ++i) {
		scanf("%d %d %d %d", &x[i][0], &y[i][0], &x[i][1], &y[i][1]);
		for (int j=i-1; j>=0; --j) {
			if (!(x[j][0] >= x[i][1] || x[j][1] <= x[i][0] ||
				  y[j][0] >= y[i][1] || y[j][1] <= y[i][0])) {
				conn[j][i] = true;
				for (int k=0; k<4; ++k) {
					if (x[j][mov[k][0]] > x[i][0] && x[j][mov[k][0]] < x[i][1] &&
						y[j][mov[k][1]] > y[i][0] && y[j][mov[k][1]] < y[i][1]) {
						cover[j] |= (1 << k);
					}
				}
			}
		}
	}

	int mx = 0, pick;
	for (int i=0; i<n; ++i) {
		if (cover[i] == 15) { continue; }
		for (int j=i; j<n; ++j) { conn[j][j] = false; }
		int cnt = dfs(i, n);

		if (cnt > mx) {
			mx = cnt;
			pick = i;
		}
	}

	printf("%d %d\n", mx, pick+1);
	return 0;
}
