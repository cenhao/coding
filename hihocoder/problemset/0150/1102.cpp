#include <bits/stdc++.h>
using namespace std;

const int range[8] = {0, 1500, 4500, 9000, 35000, 55000, 80000, 0x7fffffff};
const double rate[8] = {0, 0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};
const int tax[8] = {0, 45, 300, 900, 6500, 6000, 8750, 0x7fffffff};

int main() {
	int n; scanf("%d", &n);
	int ans = 0;
	for (int i=1; i<8; ++i) {
		if (n > tax[i]) {
			ans += range[i]-range[i-1];
			n -= tax[i];
		} else {
			ans += n / rate[i];
			break;
		}
	}

	printf("%d\n", ans+3500);
	return 0;
}
