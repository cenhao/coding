#include <cstdio>
using namespace std;

void dfs(int n) {
	if (n == 2) {
		printf("min(int, int)");
		return;
	}

	printf("min(int, ");
	dfs(n-1);
	printf(")");
}

int main() {
	int n; scanf("%d", &n);
	dfs(n);
	printf("\n");
	return 0;
}
