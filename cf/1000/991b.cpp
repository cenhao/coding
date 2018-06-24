#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
int a[MAXN];

int main() {
	int n; scanf("%d", &n);
	int sm = 0, need = 45 * n;
	for (int i=0; i<n; ++i) {
		scanf("%d", &a[i]);
		a[i] *= 10;
		sm += a[i];
	}
	sort(a, a+n);
	if (sm >= need) {
		printf("0\n");
	} else {
		for (int i=0; i<n; ++i) {
			sm += 50 - a[i];
			if (sm >= need) {
				printf("%d\n", i+1);
				break;
			}
		}
	}
	return 0;
}
