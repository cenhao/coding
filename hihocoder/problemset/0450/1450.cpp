#include <stdio.h>

#define ESP 1e-8

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int p[2], tri[3][2];
		scanf("%d %d", &p[0], &p[1]);
		double pp[2] = {0, 0};
		for (int i=0; i<3; ++i) {
			scanf("%d %d", &tri[i][0], &tri[i][1]);
			pp[0] += tri[i][0]; pp[1] += tri[i][1];
		}

		pp[0] /= 3; pp[1] /= 3;

		bool within = true;
		for (int i=0; i<3 && within; ++i) {
			int ii = (i + 1) % 3;
			double vp[2] = {p[0]-tri[i][0], p[1]-tri[i][1]};
			double vpp[2] = {pp[0]-tri[i][0], pp[1]-tri[i][1]};
			double vii[2] = {tri[ii][0]-tri[i][0], tri[ii][1]-tri[i][1]};

			double cp_p_ii = vp[0]*vii[1] - vp[1]*vii[0];
			double cp_pp_ii = vpp[0]*vii[1] - vpp[1]*vii[0];

			if (!((cp_p_ii > ESP && cp_pp_ii > ESP) ||
				(cp_p_ii < -ESP && cp_pp_ii < -ESP) ||
				(cp_p_ii <= ESP && cp_p_ii >= -ESP))) {
				within = false;
			}
		}

		printf(within ? "YES\n" : "NO\n");
	}

	return 0;
}
