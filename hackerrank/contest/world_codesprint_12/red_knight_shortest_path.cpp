#include <bits/stdc++.h>
using namespace std;

#define MAXN 200

const int mov[6][2] = {
	{-2, -1}/*UL*/, {-2, 1}/*UR*/, {0, 2}/*R*/, {2, 1}/*LR*/, {2, -1}/*LL*/, {0, -2}/*L*/
};

const char mname[6][3] = {
	"UL", "UR", "R", "LR", "LL", "L"
};

int prem[MAXN][MAXN], ans[MAXN*MAXN];
bool vis[MAXN][MAXN];

struct Pos { int x, y; };

int main() {
	int n; scanf("%d", &n);
	int sx, sy; scanf("%d%d", &sx, &sy);
	int ex, ey; scanf("%d%d", &ex, &ey);

	memset(vis, false, sizeof(vis));
	vis[sx][sy] = true;
	prem[sx][sy] = -1;

	Pos tmp = { sx, sy };
	queue<Pos> q;
	q.push(tmp);
	bool reach = false;

	while (!q.empty() && !reach) {
		tmp = q.front(); q.pop();
		for (int i=0; i<6; ++i) {
			Pos tmp1 = { tmp.x + mov[i][0], tmp.y + mov[i][1] };
			if (tmp1.x<0 || tmp1.x>=n || tmp1.y<0 || tmp1.y>=n || vis[tmp1.x][tmp1.y]) { continue; }
			vis[tmp1.x][tmp1.y] = true;
			prem[tmp1.x][tmp1.y] = i;

			if (tmp1.x == ex && tmp1.y == ey) {
				reach = true;
				break;
			}
			q.push(tmp1);
		}
	}

	if (reach) {
		int cnt = 0;
		int x = ex, y = ey;
		while (prem[x][y] >= 0) {
			ans[cnt++] = prem[x][y];
			int xx = x - mov[prem[x][y]][0];
			int yy = y - mov[prem[x][y]][1];
			x = xx; y = yy;
		}

		printf("%d\n", cnt);
		for (int i=cnt-1; i>=0; --i) {
			printf("%s%c", mname[ans[i]], i==0 ? '\n' : ' ');
		}
	} else {
		printf("Impossible\n");
	}

	return 0;
}
