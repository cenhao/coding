#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

struct Space {
	int r, s, e;
	bool operator == (const Space &ss) const {
		return r == ss.r && s == ss.s && e == ss.e;
	}
};

namespace std {
	template<> struct hash<Space> {
		size_t operator() (const Space &s) const { return hash<int>()(s.r*MAXN + s.s); }
	};
}

int main() {
	int n, k; scanf("%d%d", &n, &k);
	unordered_set<Space> avai;
	int center = k/2+1;
	Space tmp = { center, 1, k };
	avai.insert(tmp);
	for (int i=0; i<n; ++i) {
		int m; scanf("%d", &m);
		auto pit = avai.end();
		int mn = 0x7fffffff, pr, ps;
		for (auto it=avai.begin(); it!=avai.end(); ++it) {
			if (it->e-it->s+1 < m) { continue; }
			int cost = abs(it->r-center) * m, ts, te;
			if (it->s == 1 && it->e == k) {
				ts = center - m/2;
				te = ts + m - 1;
				cost += (center-ts+1)*(center-ts)/2;
				cost += (te-center+1)*(te-center)/2;
			} else if (it->e < center) {
				ts = it->e-m+1;
				te = it->e;
				cost += (center-it->e+center-ts) * m / 2;
			} else {
				ts = it->s;
				te = ts +m-1;
				cost += (ts-center+ts+m-1-center) * m / 2;
			}

			if (cost < mn) {
				mn = cost;
				pr = it->r;
				ps = ts;
				pit = it;
			} else if (cost == mn) {
				if (it->r < pr) {
					pr = it->r;
					ps = ts;
					pit = it;
				} else if (pr == it->r && ts < ps) {
					ps = ts;
					pit = it;
				}
			}
		}

		if (pit == avai.end()) {
			printf("-1\n");
		} else {
			int pe = ps + m - 1;
			printf("%d %d %d\n", pr, ps, pe);
			avai.erase(pit);
			if (pr <= center && pr > 1 && ps <= center && pe >= center) {
				tmp = { pr-1, 1, k };
				avai.insert(tmp);
			}
			if (pr >= center && pr < k && ps <= center && pe >= center) {
				tmp = { pr+1, 1, k };
				avai.insert(tmp);
			}
			if (ps <= center && ps > 1) {
				tmp = { pr, 1, ps-1 };
				avai.insert(tmp);
			}
			if (pe >= center && pe < k) {
				tmp = { pr, pe+1, k };
				avai.insert(tmp);
			}
		}
	}

	return 0;
}
