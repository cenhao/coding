#include <cstdio>
#include <cstring>
using namespace std;

int matrix[3][3];
int ans[3][3];
bool vis[10];

int check(int pos, int cnt) {
	if (cnt == 9) {
		int dsum = 0, rdsum = 0;
		for (int i=0; i<3; ++i) {
			int hsum = 0;
			for (int j=0; j<3; ++j) {
				hsum += matrix[i][j];
			}
			if (hsum != 15) { return 0; }

			int vsum = 0;
			for (int j=0; j<3; ++j) {
				vsum += matrix[j][i];
			}
			if (vsum != 15) { return 0; }

			dsum += matrix[i][i];
			rdsum += matrix[i][2-i];
		}

		if (dsum == rdsum && dsum == 15) {
			for (int i=0; i<3; ++i) {
				for (int j=0; j<3; ++j) {
					ans[i][j] = matrix[i][j];
				}
			}

			return 1;
		}

		return 0;
	}

	int x = pos / 3, y = pos % 3;
	if (matrix[x][y] != 0) {
		return check(pos+1, cnt);
	}

	int scnt = 0;
	for (int k=1; k<=9; ++k) {
		if (vis[k]) { continue; }
		vis[k] = true;
		matrix[x][y] = k;
		scnt += check(pos+1, cnt+1);
		matrix[x][y] = 0;
		vis[k] = false;

		if (scnt > 1) { return scnt; }
	}

	return scnt;
}

int main() {
	memset(vis, false, sizeof(vis));

	int cnt = 0;
	for (int i=0; i<3; ++i) {
		for (int j=0; j<3; ++j) {
			scanf("%d", &matrix[i][j]);
			if (matrix[i][j] != 0) {
				vis[matrix[i][j]] = true;
				++cnt;
			}
		}
	}

	if (check(0, cnt) == 1) {
		for (int i=0; i<3; ++i) {
			for (int j=0; j<3; ++j) {
				printf("%d%c", ans[i][j], (j==2 ? '\n' : ' '));
			}
		}
	} else {
		printf("Too Many\n");
	}

	return 0;
}
