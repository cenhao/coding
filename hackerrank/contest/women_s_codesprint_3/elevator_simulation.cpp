#include <algorithm>
#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

#define MAXN 100
#define MAXC 25

struct Passenger {
	int id, t, f;
} p[MAXN];

int line[2][MAXN], h[2], r[2];

int main() {
	memset(p, 0, sizeof(p));

	int n, w, c, m; scanf("%d %d %d %d", &n, &w, &c, &m);
	for (int i=0; i<n; ++i) { scanf("%d %d %d", &p[i].id, &p[i].t, &p[i].f); }

	int t = 0, next = 0, carried = 0, tn = 0, rtn, tf;
	h[0] = h[1] = 0; r[0] = r[1] = 0;
	while (carried < n) {
		++tn;
		if (h[0] == r[0] && h[1] == r[1]) { t = max(t, p[next].t); }
		while (next < n && p[next].t <=t+w) {
			line[p[next].id-1][r[p[next].id-1]++] = next;
			++next;
		}

		int cnt = 0, mf = 0;
		for (int i=1; i>=0; --i) {
			for (int j=h[i]; j<r[i] && cnt < c; ++j) {
				++cnt; ++carried;
				mf = max(mf, p[line[i][j]].f);
				if (line[i][j] == m-1) { rtn = tn; }
				if (carried == n) { tf = t + w + p[line[i][j]].f; }
				++h[i];
			}
		}

		t += w + 2*mf;
	}

	printf("%d %d\n", rtn, tf);
	return 0;
}
