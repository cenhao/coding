#include <bits/stdc++.h>
using namespace std;

int main() {
	int m[3], ans = 0; scanf("%d %d %d", &m[0], &m[1], &m[2]);
	for (int i=0; i<3; ++i) { ans += min(100, m[i]*10); }
	printf("%d\n", ans);
	return 0;
}
