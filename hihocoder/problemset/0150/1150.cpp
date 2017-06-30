/*
 * distance to all users dist_a = sum((x-x_i)^2+(y-y_i)^2)
 * the partial devirative of dist_a on x is: sum(x-x_i)
 * and devirative reach the extreme value on x = sum(x_i)/n (avg).
 * same for y = sum(y_i)/n
 *
 * so when the tower is at (avg_x, avg_y), the cost is minimal
 * for all users.
 *
 * However the tower has to built on integer location, hence
 * the location can be waggled a bit to try to get closer to
 * its closest company.
 *
 * Note that the squared euclid distance grows much faster than
 * manhattan distance, so the waggling space should be very limited
 * (at most 2?)
 *
 * Also, change in x-axis is independent to change in y-axis.
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXA 1000

int a[MAXA][2];

inline int64_t dist(int64_t v, int vv) {
	return (v-vv) * (v-vv);
}

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int n, m, acnt, bcnt; scanf("%d%d%d%d", &n, &m, &acnt, &bcnt);
		int64_t sum[2] = { 0, 0 };
		for (int i=0; i<acnt; ++i) {
			scanf("%d%d", &a[i][0], &a[i][1]);
			sum[0] += a[i][0]; sum[1] += a[i][1];
		}
		int64_t start[2] = { sum[0] / double(acnt) + 0.5, sum[1] / double(acnt) + 0.5 };
		int64_t best[2] = { 0, 0 };
		for (int i=0; i<acnt; ++i) {
			best[0] += dist(start[0], a[i][0]);
			best[1] += dist(start[1], a[i][1]);
		}
		int64_t ans = -1;
		for (int i=0; i<bcnt; ++i) {
			int b[2]; scanf("%d%d", &b[0], &b[1]);
			int64_t t[2] = { start[0], start[1] };
			int64_t tbest[2] = { best[0] + abs(b[0]-t[0]), best[1] + abs(b[1]-t[1]) };
			for (int j=0; j<2; ++j) {
				while (t[j] != b[j]) {
					int adj = (t[j] > b[j]) ? -1 : 1;
					t[j] += adj;
					int64_t tmp = 0;
					for (int k=0; k<acnt; ++k) { tmp += dist(t[0], a[k][j]); }
					if (tmp+abs(b[j]-t[j]) < tbest[j]) {
						tbest[j] = tmp + abs(b[j]-t[j]);
					} else {
						t[0] -= adj;
						break;
					}
				}
			}

			if (ans < 0 || tbest[0]+tbest[1] < ans) {
				ans = tbest[0] + tbest[1];
			}
		}

		printf("Case #%d: %" PRId64 "\n", t, ans);
	}
	return 0;
}
