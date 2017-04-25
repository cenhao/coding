#include <bits/stdc++.h>
using namespace std;

#define MAXN 300
#define MAXM 200

struct Price {
	int p;
	int mn, mx;
}nights[MAXN+1][MAXN];

struct Item {
	int p, mx;
};

int nxt[MAXN+1];
int ans[MAXN+1][MAXN+1];
auto cmp = [](const Item &i1, const Item &i2) -> bool {
	return i1.p > i2.p;
};
vector<priority_queue<Item, vector<Item>, decltype(cmp)>> pqs(MAXN+1, priority_queue<Item, vector<Item>, decltype(cmp)>(cmp));

int main() {
	// input
	int n, m, q; scanf("%d %d %d", &n, &m, &q);
	for (int j=0; j<m; ++j) {
		for (int i=1; i<=n; ++i) { scanf("%d", &nights[i][j].p); }
	}
	for (int j=0; j<m; ++j) {
		for (int i=1; i<=n; ++i) { scanf("%d", &nights[i][j].mn); }
	}
	for (int j=0; j<m; ++j) {
		for (int i=1; i<=n; ++i) { scanf("%d", &nights[i][j].mx); }
	}

	for (int i=1; i<=n; ++i) {
		sort(nights[i], nights[i]+m, [](const Price &p1, const Price &p2) -> bool {
			return (p1.mn == p2.mn) ? (p1.mx < p2.mx) : (p1.mn < p2.mn);
		});
	}

	memset(nxt, 0, sizeof(nxt));

	for (int j=1; j<=n; ++j) {
		for (int i=1; i<=n; ++i) {
			while (nxt[i] < m && nights[i][nxt[i]].mn <= j) {
				if (nights[i][nxt[i]].p != 0) {
					Item item = { nights[i][nxt[i]].p, nights[i][nxt[i]].mx };
					pqs[i].push(item);
				}
				++nxt[i];
			}
		}

		int invalid_cnt = 0, sum = 0;
		int l = 1, r = 0;
		for (int i=1; i+j-1<=n; ++i) {
			while (r < i+j-1) {
				++r;
				while (!pqs[r].empty() && pqs[r].top().mx < j) { pqs[r].pop(); }
				if (pqs[r].empty()) {
					++invalid_cnt;
				} else {
					sum += pqs[r].top().p;
				}
			}
			while (l < i) {
				if (pqs[l].empty()) {
					--invalid_cnt;
				} else {
					sum -= pqs[l].top().p;
				}
				++l;
			}

			ans[i][j] = (invalid_cnt) ? -1 : sum;
		}
	}

	for (int i=0; i<q; ++i) {
		int c, l; scanf("%d %d", &c, &l);
		printf("%d\n", ans[c][l]);
	}

	return 0;
}
