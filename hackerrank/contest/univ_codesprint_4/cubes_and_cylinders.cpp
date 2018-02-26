#include <bits/stdc++.h>
using namespace std;

#define MAXN 500
struct Cube { int edge, cnt; } cubes[MAXN];
struct Cylinder { int r, vol; } cylinders[MAXN];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) { scanf("%d", &cubes[i].edge); }
	for (int i=0; i<n; ++i) { scanf("%d", &cubes[i].cnt); }
	for (int i=0; i<m; ++i) { scanf("%d", &cylinders[i].r); }
	for (int i=0; i<m; ++i) { scanf("%d", &cylinders[i].vol); }

	sort(cubes, cubes+n, [](const Cube &c1, const Cube &c2) {
		return c1.edge > c2.edge;
	});
	sort(cylinders, cylinders+m, [](const Cylinder &c1, const Cylinder &c2) {
		return c1.r > c2.r;
	});

	int ans = 0;
	for (int i=0, j=0; i<n && j<m; ++i) {
		int e2 = cubes[i].edge * cubes[i].edge * 2;
		while (cubes[i].cnt > 0 && j<m && e2<cylinders[j].r*cylinders[j].r*4) {
			int mn = min(cylinders[j].vol, cubes[i].cnt);
			ans += mn;
			cylinders[j].vol -= mn;
			cubes[i].cnt -= mn;
			if (cylinders[j].vol <= 0) { ++j; }
		}
	}

	printf("%d\n", ans);
	return 0;
}
