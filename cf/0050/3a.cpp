#include <bits/stdc++.h>
using namespace std;

int main() {
	char src[4], dst[4]; scanf("%s%s", src, dst);
	int x[2] = { 8+'0'-src[1], 8+'0'-dst[1] };
	int y[2] = { src[0] - 'a', dst[0] - 'a' };
	int dx = x[1] - x[0], dy = y[1] - y[0];
	int diag = min(abs(dx), abs(dy));

	int ans = 0;
	char mov[4];
	if (diag > 0) {
		ans += diag;
		mov[2] = 0;
		if (dy > 0) {
			mov[0] = 'R';
			dy -= diag;
		} else {
			mov[0] = 'L';
			dy += diag;
		}

		if (dx > 0) {
			mov[1] = 'D';
			dx -= diag;
		} else {
			mov[1] = 'U';
			dx += diag;
		}
	}

	ans += abs(dx);
	ans += abs(dy);
	printf("%d\n", ans);
	for (int i=0; i<diag; ++i) { printf("%s\n", mov); }

	mov[1] = 0;
	if (dx != 0) {
		mov[0] = (dx > 0) ? 'D' : 'U';
		for (int i=abs(dx); i>0; --i) { printf("%s\n", mov); }
	}
	if (dy != 0) {
		mov[0] = (dy > 0) ? 'R' : 'L';
		for (int i=abs(dy); i>0; --i) { printf("%s\n", mov); }
	}

	return 0;
}
