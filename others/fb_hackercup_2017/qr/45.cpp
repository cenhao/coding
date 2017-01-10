#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXX 20
#define MAXY 20

double pack[2][MAXX*MAXY];
char spell[128];

int main() {
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		int h, s; scanf("%d %d", &h, &s);
		double mx = 0.0;
		for (int i=0; i<s; ++i) {
			scanf("%s", spell);
			int x, y, z=0; char sign = '+';
			int matched = sscanf(spell, "%dd%d%c%d", &x, &y, &sign, &z);

			if (matched > 2) {
				z = (sign == '+') ? z : -z;
			}

			memset(pack[0], 0, sizeof(pack[0]));
			pack[0][0] = 1.0;
			double chance = 1.0 / y;
			int cur, pre;
			for (int i1=1; i1<=x; ++i1) {
				cur = i1 & 1; pre = (i1-1) & 1;
				memset(pack[cur], 0, sizeof(pack[cur]));

				for (int i2=1; i2<=y; ++i2) {
					for (int i3=i1*y; i3>=i2; --i3) {
						pack[cur][i3] += pack[pre][i3-i2] * chance;
					}
				}
			}

			double safechance = 0.0; int threshold = h-z;
			for (int i1=1, end=x*y; i1<=end; ++i1) {
				if (i1 >= threshold) { safechance += pack[cur][i1]; }
			}

			mx = max(mx, safechance);
		}

		printf("Case #%d: %.6lf\n", t, mx);
	}

	return 0;
}
