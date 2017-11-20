#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<i; ++j) {
			printf("%d ", m+j*k-(i-j));
		}
		for (int j=i; j<n; ++j) {
			printf("%d%c", m+i*k-(j-i), (j<n-1) ? ' ':'\n');
		}
	}

	return 0;
}
