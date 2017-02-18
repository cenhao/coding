#include <cstdio>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	bool init = false;
	int mx, mn;
	int mxc = 0, mnc = 0;
	for (int i=0; i<n; ++i) {
		int s; scanf("%d", &s);
		if (init) {
			if (s > mx) {
				++mxc;
				mx = s;
			} else if (s < mn) {
				++mnc;
				mn = s;
			}
		} else {
			mx = mn = s;
			init = true;
		}
	}

	printf("%d %d\n", mxc, mnc);
	return 0;
}
