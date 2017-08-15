#include <bits/stdc++.h>
using namespace std;

inline bool possible(int n, int l) {
	return ((2*n % l == 0) && (2*n/l+1-l > 0) && (((2*n/l+1-l) & 1) == 0));
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i=sqrt(2*n); i>=1; --i) {
			if (possible(n, i)) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
