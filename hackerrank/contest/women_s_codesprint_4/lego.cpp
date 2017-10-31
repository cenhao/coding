#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		int prod = 1;
		for (int i=0; i<4; ++i) {
			int v; scanf("%d", &v);
			prod *= v;
		}
		for (int i=0; i<2; ++i) {
			int v; scanf("%d", &v);
			prod /= v;
		}
		printf("%d\n", prod);
	}
	return 0;
}
