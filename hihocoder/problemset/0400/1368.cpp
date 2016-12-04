#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

#define MAXN 1000
#define MAXK 30

int x[MAXN], y[MAXN];
int kx[MAXK], ky[MAXK];
int xt[(MAXK+2)*3], yt[(MAXK+2)*3];
int dxt[(MAXK+2)*3], dyt[(MAXK+2)*3];
int dist[(MAXK+2)*3][(MAXK+2)*3];

struct Pool {
	int x, y;
	bool operator <(const Pool &p) const {
		return (x == p.x) ? (y < p.y) : (x < p.x);
	}
};
set<Pool> pools;

int compress(int s, int e, int nm, int k, int *a, int *ka) {
	int cnt = 6;
	a[0] = s; a[1] = s-1; a[2] = s+1;
	a[3] = e; a[4] = e-1; a[5] = e+1;
	for (int i=0; i<k; ++i) {
		a[cnt++] = ka[i]-1; a[cnt++] = ka[i]; a[cnt++] = ka[i]+1;
	}
	sort(a, a+cnt);
	int tcnt=0, last=0;
	for (int i=0; i<cnt && a[i]<=nm; ++i) {
		if (a[i] != last) {
			a[tcnt++] = a[i];
			last = a[i];
		}
	}

	return tcnt;
}

int findv(int *a, int s, int v) {
	int l=0, r=s-1;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (a[m] <= v) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}

	return r;
}

void computeDist(int cnt, int *a, int *nd, int *d) {
	for (int i=1; i<cnt; ++i) {
		nd[i-1] = 0;
		for (int j=a[i-1]-1; j<a[i]-1; ++j) { nd[i-1] += d[j]; }
	}
}

struct QueueItem {
	int x, y;
	int len;

	bool operator < (const QueueItem &qi) const {
		return len > qi.len;
	}
};

int spfa(int sxi, int syi, int exi, int eyi, int xcnt, int ycnt) {
	memset(dist, 0x7f, sizeof(dist));
	const int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // > v < ^
	QueueItem item = { sxi, syi, 0 }, tmp;
	priority_queue<QueueItem> pq;
	pq.push(item);
	bool found = false;

	while (!pq.empty()) {
		item = pq.top(); pq.pop();
		if (item.len > dist[item.x][item.y]) { continue; }
		dist[item.x][item.y] = item.len;
		if (item.x == exi && item.y == eyi) {
			found = true;
			break;
		}
		for (int i=0; i<4; ++i) {
			tmp.x = item.x + move[i][0]; tmp.y = item.y + move[i][1];
			Pool p = { xt[tmp.x], yt[tmp.y] };
			if (tmp.x >= xcnt || tmp.x < 0 ||
				tmp.y >= ycnt || tmp.y < 0) { continue; }
			if (pools.find(p) != pools.end()) { continue; }
			int add;
			if (tmp.x == item.x) {
				add = dyt[min(item.y, tmp.y)];
			} else {
				add = dxt[min(item.x, tmp.x)];
			}

			tmp.len = item.len + add;
			if (tmp.len < dist[tmp.x][tmp.y]) {
				dist[tmp.x][tmp.y] = tmp.len; // IMPORTANT!
				pq.push(tmp);
			}
		}
	}

	return found ? dist[exi][eyi] : -1;
}

int solve(int sx, int sy, int ex, int ey, int n, int m, int k) {
	int xcnt = compress(sx, ex, n, k, xt, kx);
	int ycnt = compress(sy, ey, m, k, yt, ky);
	int sxi = findv(xt, xcnt, sx); int syi = findv(yt, ycnt, sy);
	int exi = findv(xt, xcnt, ex); int eyi = findv(yt, ycnt, ey);
	computeDist(xcnt, xt, dxt, x);
	computeDist(ycnt, yt, dyt, y);
	return spfa(sxi, syi, exi, eyi, xcnt, ycnt);
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<n-1; ++i) { scanf("%d", &x[i]); }
	for (int i=0; i<m-1; ++i) { scanf("%d", &y[i]); }

	int k; scanf("%d", &k);
	for (int i=0; i<k; ++i) {
		scanf("%d %d", &kx[i], &ky[i]);
		Pool p = { kx[i], ky[i] };
		pools.insert(p);
	}

	int q; scanf("%d", &q);
	for (int i=0; i<q; ++i) {
		int sx, sy, ex, ey; scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		printf("%d\n", solve(sx, sy, ex, ey, n, m, k));
	}

	return 0;
}
