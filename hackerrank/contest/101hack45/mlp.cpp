#include <cstdio>
using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	if ((k == 2 && n != 2) || k > n) {
		printf("-1\n");
		return 0;
	}

	printf("%d\n", k-1 + 2*(n-k));
	return 0;
}
