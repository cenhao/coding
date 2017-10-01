#include <bits/stdc++.h>
using namespace std;

#define MAXN 300
const int mov[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
int area[MAXN][MAXN];
bool vis[MAXN][MAXN];
struct Pos { int x, y, w; };

int main() {
	int n, m; scanf("%d%d", &n, &m);
	memset(area, 0, sizeof(area));
	for (int i=0; i<m; ++i) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		memset(vis, 0, sizeof(vis));
		vis[x][y] = true;
		area[x][y] += w;
		Pos tmp = {x, y, w};
		queue<Pos> q;
		q.push(tmp);

		while (!q.empty()) {
			tmp = q.front(); q.pop();
			for (int i=0; i<8; ++i) {
				int xx = tmp.x + mov[i][0], yy = tmp.y + mov[i][1];
				if (xx >= n || xx < 0 || yy >= n || yy < 0 || vis[xx][yy]) { continue; }
				vis[xx][yy] = true;
				area[xx][yy] += tmp.w - 1;
				if (tmp.w > 1) {
					Pos tmp1 = {xx, yy, tmp.w-1};
					q.push(tmp1);
				}
			}
		}
	}

	int mx = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			mx = max(area[i][j], mx);
		}
	}

	printf("%d\n", mx);
	return 0;
}
