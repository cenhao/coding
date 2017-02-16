#include <cstdint>
#include <cstdio>
using namespace std;

#define MAXN 1000000

int64_t low[MAXN+1], up[MAXN+1];
int ans[MAXN];

void lazy_init(int n) {
	static bool first = true;
	static int inited = 0;
	if (first) {
		low[0] = up[0] = 0;
		first = false;
	}

	if (n <= inited) { return; }

	for (int i=inited+1, i1=inited; i<=n; ++i, ++i1) {
		up[i] = i1 + up[i1];
		low[i] = i1 + low[i1/2] + low[i1-i1/2];
	}
	inited = n;
}

void generate(int s, int e, int c, int idx) {
	if (s > e) { return; }

	int len = e-s+1;
	int l = 0, r = len / 2, m;
	c -= len - 1;

	while (l <= r) {
		m = (l + r) / 2;
		if (low[m] + low[len-1-m] > c) {
			l = m + 1;
		} else if(low[m] + up[len-1-m] < c) {
			r = m - 1;
		} else {
			break;
		}
	}

	ans[idx] = s + m;
	generate(s, s+m-1, low[m], idx+1);
	generate(s+m+1, e, c-low[m], idx+m+1);
}

int main() {
	int q; scanf("%d", &q);
	for (int i=0; i<q; ++i) {
		int len, c; scanf("%d %d", &len, &c);
		lazy_init(len);
		if (up[len] < c || c < low[len]) {
			printf("-1\n");
			continue;
		}

		generate(1, len, c, 0);
		for (int i=0; i<len; ++i) {
			printf("%d%c", ans[i], (i==len-1) ? '\n' : ' ');
		}
	}

	return 0;
}
