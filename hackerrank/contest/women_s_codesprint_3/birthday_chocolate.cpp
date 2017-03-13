#include <cstdio>
using namespace std;

#define MAXN 100

int choco[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i=0; i<n; ++i) { scanf("%d", &choco[i]); }
	int d, m; scanf("%d %d", &d, &m);
	if (m > n) {
		printf("0\n");
	} else {
		int sum = 0, cnt = 0;
		for (int i=0; i<m-1; ++i) { sum += choco[i]; }
		for (int i=m-1; i<n; ++i) {
			sum += choco[i];
			if (sum == d) { ++cnt; }
			sum -= choco[i-m+1];
		}

		printf("%d\n", cnt);
	}

	return 0;
}
