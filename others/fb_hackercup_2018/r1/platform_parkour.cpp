#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000
#define MAXM 20
#define INF 1000000000LL

struct Pkist { int u, d, a, b; } p[MAXM];
int64_t h[MAXN], u[MAXN], d[MAXN];

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int n, m; scanf("%d%d", &n, &m);
		int64_t h1, h2;
		int w, x, y, z;
		scanf("%" SCNd64 "%" SCNd64 "%d%d%d%d", &h1, &h2, &w, &x, &y, &z);
		for (int i=0; i<m; ++i) {
			scanf("%d%d%d%d", &p[i].a, &p[i].b, &p[i].u, &p[i].d);
			--p[i].a; --p[i].b;
			if (p[i].b < p[i].a) {
				swap(p[i].a, p[i].b);
				swap(p[i].u, p[i].d);
			}
		}

		sort(p, p+m, [](const Pkist &p1, const Pkist &p2) {
			return p1.a == p2.a ? p1.b < p2.b : p1.a < p2.a;
		});

		auto cmpu = [](const Pkist &p1, const Pkist &p2) { return p1.u > p2.u; };
		auto cmpd = [](const Pkist &p1, const Pkist &p2) { return p1.d > p2.d; };
		priority_queue<Pkist, vector<Pkist>, decltype(cmpu)> upq(cmpu);
		priority_queue<Pkist, vector<Pkist>, decltype(cmpd)> dpq(cmpd);
		int64_t mxh = -1;

		int mpos = 0;
		for (int i=0; i<n; ++i) {
			int64_t tmp;
			if (i == 0) {
				tmp = h1;
			} else if (i == 1) {
				tmp = h2;
			} else {
				tmp = (w*h1 + x*h2 + y) % z;
				h1 = h2; h2 = tmp;
			}

			h[i] = tmp;
			mxh = max(mxh, tmp);
			while (!upq.empty() && upq.top().b<i) { upq.pop(); }
			while (!dpq.empty() && dpq.top().b<i) { dpq.pop(); }
			u[i] = upq.empty() ? -1 : upq.top().u;
			d[i] = dpq.empty() ? -1 : dpq.top().d;
			while (mpos<m && p[mpos].a<=i) {
				upq.push(p[mpos]);
				dpq.push(p[mpos]);
				++mpos;
			}
		}

		int64_t l = 0, r = 2 * mxh;
		while (l <= r) {
			bool ok = true;
			int64_t preu = INF, pred = 0;
			int64_t mid = (l + r) / 2;
			for (int i=0; i<n && ok; ++i) {
				if (u[i] >= 0) {
					preu = min((int64_t)INF, preu+2*u[i]);
					pred = max((int64_t)0, pred-2*d[i]);
				} else {
					preu = min((int64_t)INF, 2*h[i] + mid);
					pred = max((int64_t)0, 2*h[i] - mid);
				}

				int64_t tu = min((int64_t)INF, 2*h[i] + mid), td = max((int64_t)0, 2*h[i] - mid);
				preu = min(preu, tu), pred = max(pred, td);
				if (preu < pred) { ok = false; }
			}

			if (ok) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		printf("Case #%d: %.6lf\n", t, l/2.0);
	}
	return 0;
}
