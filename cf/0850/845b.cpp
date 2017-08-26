#include <bits/stdc++.h>
using namespace std;

int main() {
	char d[7]; scanf("%s", d);
	int sum[2] = { 0, 0 };
	for (int i=0; i<6; ++i) { sum[i/3] += d[i] - '0'; }
	if (sum[0] < sum[1]) {
		for (int i=0; i<3; ++i) { swap(d[i], d[i+3]); }
		swap(sum[0], sum[1]);
	}

	int diff = sum[0] - sum[1], ans;
	if (diff == 0) {
		ans = 0;
	} else {
		int space[6];
		int adj[2] = { 0, 9 };
		for (int i=0; i<6; ++i) { space[i] = abs(d[i] - '0' - adj[i/3]); }
		sort(space, space+6);
		for (int i=5; i>=0; --i) {
			if (space[i] >= diff) {
				ans = 6-i;
				break;
			}
			diff -= space[i];
		}
	}

	printf("%d\n", ans);
	return 0;
}
