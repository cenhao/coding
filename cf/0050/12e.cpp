#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
int cache[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n-1; ++i) {
		for (int j=0; j<n-1; ++j) {
			if (i == j) {
				printf("0 ");
				cache[i] = (i + j) % (n-1) + 1;
			} else {
				printf("%d ", (i+j) % (n-1) + 1);
			}
		}
		printf("%d\n", cache[i]);
	}
	for (int i=0; i<n; ++i) {
		printf("%d%c", cache[i], i!=n-1 ? ' ' : '\n');
	}
	return 0;
}
