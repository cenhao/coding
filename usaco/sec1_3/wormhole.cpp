/*
ID: cenhao11
PROG: wormhole
LANG: C++11
*/

#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;

#define MAXN 15

int x[MAXN], y[MAXN], n;
int r[MAXN], p[MAXN];

void prep() {
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (y[i] == y[j] && x[i] > x[j]) {
				r[j] = (x[i] < x[r[j]] || r[j] == 0) ? i : r[j];
			}
		}
	}
}

bool loop()
{
	int pos = 0;
	for (int i=1; i<=n; ++i) {
		pos = i;
		for (int cnt=0; cnt<n; ++cnt) {
			pos = r[p[pos]];
		}

		if (pos != 0) { return true; }
	}

	return false;
}

int dfs(int left) {
	if (left == 0) { return loop() ? 1 : 0; }
	int sum = 0;

	for (int i=1; i<=n; ++i) {
		if (p[i] != 0) { continue; }
		for (int j=i+1; j<=n; ++j) {
			if (p[j] != 0) { continue; }
			p[i] = j;
			p[j] = i;
			sum += dfs(left-2);
			p[i] = p[j] = 0;
		}
		break;
	}

	return sum;
}

int solve() {
	prep();
	return dfs(n);
}

int main() {
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
	memset(r, 0, sizeof(r));
	memset(p, 0, sizeof(p));

	while (EOF != scanf("%d", &n)) {
		for (int i=1; i<=n; ++i) { scanf("%d%d", &x[i], &y[i]); }
		printf("%d\n", solve());
	}

	return 0;
}
